#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // Create an unordered_set to store unique elements from nums
        unordered_set<int> us(nums.begin(), nums.end()); // SC: O(n), where n is the size of nums
        int ans = 0;                                     // Variable to store the length of the longest consecutive sequence
        for (auto num : nums)
        {
            // Check if the current number is the start of a sequence
            if (!us.count(num - 1))
            {
                int currentNum = num; // Initialize current number to num
                int cnt = 1;          // Initialize count of current sequence
                // Check for the next consecutive elements
                while (us.count(currentNum + 1))
                {
                    currentNum++; // Move to the next number in the sequence
                    cnt++;        // Increment the count of consecutive numbers
                }
                // Update the answer with the maximum length found
                ans = max(ans, cnt);
            }
        }
        return ans; // Return the length of the longest consecutive sequence
    }
};

int main()
{
    int n;
    cin >> n; // Input the size of the array without any prompt

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // Input array elements without any prompt
    }

    Solution solution;
    int result = solution.longestConsecutive(nums); // Call the function

    return result; // Output the result without any statement
}

// Time Complexity: O(n), where n is the size of the input array nums
// Space Complexity: O(n), where n is the size of the input array nums (due to the unordered_set us)
