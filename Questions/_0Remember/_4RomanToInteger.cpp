#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    int romanToDecimal(string &str)
    {
        // Create a map to store Roman numerals and their corresponding values
        unordered_map<char, int> um = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}};

        int ans = 0;     // Initialize the result to 0
        int prevNum = 0; // Variable to keep track of the previous numeral's value

        // Traverse the string from right to left
        for (int i = str.length() - 1; i >= 0; i--)
        {
            int num = um[str[i]]; // Get the value of the current Roman numeral

            // If the current numeral is less than the previous one, subtract it from the result
            if (num < prevNum)
            {
                ans -= num;
            }
            // Otherwise, add it to the result
            else
            {
                ans += num;
            }

            // Update the previous numeral's value
            prevNum = num;
        }
        return ans; // Return the final result
    }
};

int main()
{
    string roman;
    cin >> roman; // Take input from the user without any statement

    Solution sol;
    cout << sol.romanToDecimal(roman) << endl; // Output the result

    return 0;
}

/*
Time Complexity: O(n)
- We iterate through the string once, where n is the length of the string.

Space Complexity: O(1)
- The space used by the unordered_map is constant (since there are a fixed number of Roman numerals).
- Only a few additional variables are used, which occupy constant space.
*/
