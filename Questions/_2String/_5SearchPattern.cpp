#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    // Function to compute the Longest Prefix Suffix (LPS) array
    vector<int> longestPrefixSuffix(string pattern)
    {
        int n = pattern.length();
        vector<int> lps(n, 0); // Initialize LPS array with 0
        int i = 1;             // Pointer for traversing the pattern
        int len = 0;           // Length of the previous longest prefix suffix

        // Loop to fill the LPS array
        while (i < n)
        {
            if (pattern[i] == pattern[len])
            {                 // When characters match
                len++;        // Increase length of current LPS
                lps[i] = len; // Update LPS array
                i++;          // Move to the next character
            }
            else
            { // When characters do not match
                if (len != 0)
                { // If len is not zero, update len to previous LPS value
                    len = lps[len - 1];
                }
                else
                { // If len is zero, set LPS[i] to 0 and move to next character
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps; // Return the computed LPS array
    }

    // Function to search for pattern in text using KMP algorithm
    vector<int> search(string pattern, string text)
    {
        int m = text.length();                          // Length of the text
        int n = pattern.length();                       // Length of the pattern
        int i = 0;                                      // Pointer for traversing the text
        int j = 0;                                      // Pointer for traversing the pattern
        vector<int> lps = longestPrefixSuffix(pattern); // Compute the LPS array
        vector<int> ans;                                // Vector to store the starting indices of found patterns

        // Loop to search for the pattern in the text
        while (i < m)
        {
            if (text[i] == pattern[j])
            {        // When characters match
                i++; // Move to the next character in text
                j++; // Move to the next character in pattern
            }
            if (j == n)
            {                             // When the whole pattern is found
                ans.push_back(i - j + 1); // Store the starting index of the pattern
                j = lps[j - 1];           // Update j to the last known good position in pattern
            }
            else if (i < m && text[i] != pattern[j])
            { // When characters do not match
                if (j != 0)
                { // If j is not zero, update j to the last known good position in pattern
                    j = lps[j - 1];
                }
                else
                { // If j is zero, move to the next character in text
                    i++;
                }
            }
        }
        return ans; // Return the starting indices of the found patterns
    }
};

// Main function to take input from user and call the search function
int main()
{
    string text;
    string pattern;
    cin >> text;
    cin >> pattern;

    Solution sol;
    vector<int> result = sol.search(pattern, text);

    // Print the starting indices of the pattern found in the text
    for (int index : result)
    {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:
- The time complexity of computing the LPS array is O(n), where n is the length of the pattern.
- The time complexity of the search function is O(m + n), where m is the length of the text and n is the length of the pattern.
Overall time complexity: O(m + n)

Space Complexity:
- The space complexity is O(n) for storing the LPS array.
Overall space complexity: O(n)
*/
