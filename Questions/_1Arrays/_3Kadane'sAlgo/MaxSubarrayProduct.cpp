#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxi = nums[0], mini = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0) // If the current number (nums[i]) is negative, we swap maxi and mini because multiplying by a negative number can flip the maximum and minimum products.
            {
                swap(maxi, mini);
            }
            maxi = max(nums[i], nums[i] * maxi);
            mini = min(nums[i], nums[i] * mini); // used for handling negative numbers

            ans = max(ans, maxi);
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n; // Input size of the array

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // Input array elements
    }

    Solution solution;
    int result = solution.maxProduct(nums); // Call the maxProduct function

    return result; // Output the result without any statement
}
// TC: O(n) - Time complexity where n is the size of the input array nums.
// SC: O(1) - Space complexity. The space used is constant and does not depend on the size of the input.
