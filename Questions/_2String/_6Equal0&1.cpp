#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    // Function to find the maximum number of substrings with equal number of 0s and 1s
    int maxSubStr(string str)
    {
        int zero = 0; // Counter for 0s
        int one = 0;  // Counter for 1s
        int ans = 0;  // Number of valid substrings

        // Iterate through each character in the string
        for (auto s : str)
        {
            if (s == '0') // If the character is '0', increment the zero counter
                zero++;
            if (s == '1') // If the character is '1', increment the one counter
                one++;

            // If the count of 0s and 1s are equal, we found a valid substring
            if (zero == one)
            {
                ans++;    // Increment the answer counter
                zero = 0; // Reset zero counter
                one = 0;  // Reset one counter
            }
        }

        // If there are leftover 0s or 1s, it means we cannot split the string into valid substrings
        if (zero != 0 || one != 0)
            return -1; // Return -1 indicating it's not possible

        return ans; // Return the number of valid substrings
    }
};

int main()
{
    Solution sol;
    string str;
    cin >> str;                         // Taking input from the user
    cout << sol.maxSubStr(str) << endl; // Output the result
    return 0;
}

/*
Time Complexity: O(n), where n is the length of the string.
This is because we are iterating through the string only once.

Space Complexity: O(1).
We are using a constant amount of extra space for the counters and the answer.
*/
