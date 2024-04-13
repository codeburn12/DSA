#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int i = n - 2, j = n - 1;

        // Getting index for the first number which is less than its next number
        while (i >= 0 && nums[i] >= nums[i + 1])
        {
            i--;
        }

        // If all numbers are greater than their next, it means given number is the largest permutation, so reverse the numbers
        if (i < 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            // Find the first number from the end that is greater than nums[i]
            while (i < j && nums[i] >= nums[j])
            {
                j--;
            }
            swap(nums[j], nums[i]);
        }

        // Sort the numbers after index i to get the next permutation
        sort(nums.begin() + i + 1, nums.end());
    }
};

int main()
{
    // Input
    vector<int> nums;
    int num;
    cout << "Enter the numbers (enter -1 to stop): ";
    while (true)
    {
        cin >> num;
        if (num == -1)
            break;
        nums.push_back(num);
    }

    // Create an instance of the Solution class
    Solution solution;

    // Call the nextPermutation function
    solution.nextPermutation(nums);

    // Output
    cout << "Next Permutation: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    // Time Complexity: O(n) - where n is the number of elements in nums
    // Space Complexity: O(1) - constant space used, excluding input nums
    return 0;
}
