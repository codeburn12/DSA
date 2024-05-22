#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> memo;
        int prefixSum = 0, ans = 0;
        memo[0]++;
        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            if (memo.find(prefixSum - k) != memo.end())
                ans += memo[prefixSum - k];
            memo[prefixSum]++;
        }
        return ans;
    }
};

int main()
{
    // Input size of the array
    int n;
    cin >> n;

    // Input array elements
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // Input value of k
    int k;
    cin >> k;

    // Call subarraySum function and store the result
    Solution solution;
    int result = solution.subarraySum(nums, k);

    return result; // Output the result without any statement
}
// TC: O(n) - Time complexity where n is the size of the input array nums. We traverse the array once.
// SC: O(n) - Space complexity. We use an unordered_map to store prefix sums and their frequencies, which can have at most n elements.
