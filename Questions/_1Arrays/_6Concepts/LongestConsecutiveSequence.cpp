#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> us(nums.begin(), nums.end()); // SC: O(n), where n is the size of nums
        int ans = 0;
        for (auto num : nums)
        {
            if (!us.count(num - 1))
            {
                int currentNum = num;
                int cnt = 1;
                while (us.count(currentNum + 1))
                {
                    currentNum++;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n; // Input the size of the array

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // Input array elements
    }

    Solution solution;
    int result = solution.longestConsecutive(nums); // Call the function

    return result; // Output the result without any statement
}
// TC: O(n), where n is the size of the input array nums
// SC: O(n), where n is the size of the input array nums (due to the unordered_set us)
