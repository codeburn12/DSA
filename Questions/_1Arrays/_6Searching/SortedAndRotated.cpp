#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            // Checking if left part of mid is sorted
            if (nums[mid] >= nums[start])
            {
                // Check if the target is within the sorted left part
                if (nums[start] <= target && nums[mid] > target)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            // Checking if right part of mid is sorted
            else
            {
                // Check if the target is within the sorted right part
                if (nums[end] >= target && nums[mid] < target)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return -1; // Target not found
    }
};

int main()
{
    // Input size of the array and elements from the user
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // Input the target value from the user
    int target;
    cin >> target;

    // Create an instance of the Solution class and call the search method
    Solution obj;
    int result = obj.search(nums, target);

    // Output the result
    cout << result << endl;

    return 0;
}
// Time Complexity: The time complexity of the search method is O(log n), where n is the size of the input array nums. This is because the algorithm uses binary search, which halves the search space in each iteration.
// Space Complexity : The space complexity of the code is O(1) because the algorithm uses only a constant amount of extra space, regardless of the input size.It does not use any additional data structures that scale with the input size.