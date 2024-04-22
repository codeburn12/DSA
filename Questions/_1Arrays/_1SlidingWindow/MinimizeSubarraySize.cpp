#include <iostream>
#include <vector>
#include <climits> // For INT_MAX

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int start = 0, prefixSum = 0, windowSize = INT_MAX;
        for (int end = 0; end < nums.size(); end++)
        {
            prefixSum += nums[end];
            while (prefixSum >= target)
            {
                windowSize = min(windowSize, end - start + 1);
                prefixSum -= nums[start];
                start++;
            }
        }
        return windowSize == INT_MAX ? 0 : windowSize;
    }
};

int main()
{
    int target, n;
    cin >> target; // Input the target value
    cin >> n;      // Input the size of the array

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // Input array elements
    }

    Solution solution;
    int result = solution.minSubArrayLen(target, nums); // Call the function

    return result; // Output the result without any statement
}
// TC: O(n) - Time complexity where n is the size of the input array nums. The algorithm traverses the array once with two pointers.
// SC: O(1) - Space complexity. The algorithm uses constant space for variables regardless of the input size.
