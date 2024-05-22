#include <iostream>
using namespace std;

class Solution
{
public:
    string removeConsecutiveCharacter(string S)
    {
        string ans; // Initialize an empty string to store the result
        int i = 0;  // Initialize an index variable

        // Iterate through the input string
        while (i < S.size())
        {
            // If it's the first character or different from the previous one, add it to the result
            if (i == 0 || S[i] != S[i - 1])
            {
                ans.push_back(S[i]); // Add the character to the result string
                i++;                 // Move to the next character
            }
            else
            { // If it's the same as the previous character
                // Skip over all consecutive occurrences of the same character
                while (i < S.size() && S[i] == S[i - 1])
                {
                    i++; // Move to the next character
                }
            }
        }
        return ans; // Return the modified string without consecutive characters
    }
};

int main()
{
    Solution sol;                                  // Create an instance of the Solution class
    string input;                                  // Declare a string variable to store user input
    cin >> input;                                  // Take input from the user
    cout << sol.removeConsecutiveCharacter(input); // Print the result without any additional statement
    return 0;                                      // Exit the program
}
/*
The time complexity of this code is O(n),
where n is the length of the input string S.This is because we iterate through the string once.Space Complexity :

The space complexity is also O(n),
where n is the length of the input string S.This is because we use an additional string ans to store the modified string without consecutive characters.
*/