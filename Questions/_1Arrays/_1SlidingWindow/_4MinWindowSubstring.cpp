#include <unordered_map>
#include <string>
#include <climits>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        // Step 1: Create a frequency map for characters in t
        unordered_map<char, int> mt;
        for (auto c : t)
        {
            mt[c]++;
        }

        // Step 2: Initialize variables for sliding window
        unordered_map<char, int> ms; // Frequency map for current window
        int windowSize = 0;          // Number of unique characters from t with required frequency in the window
        int j = 0;                   // Left pointer of the window
        int uniqueEleT = mt.size();  // Number of unique characters in t
        int minM = INT_MAX;          // Minimum window length found
        int minLeft = -1;            // Starting index of the minimum window

        // Step 3: Expand the window by moving the right pointer
        for (int i = 0; i < s.size(); i++)
        {
            ms[s[i]]++; // Include current character in the window
            if (mt.count(s[i]) && ms[s[i]] == mt[s[i]])
            {
                windowSize++; // Increment windowSize if character count matches with t
            }

            // Step 4: Contract the window from the left to find the smallest valid window
            while (windowSize == uniqueEleT)
            {
                if (i - j + 1 < minM)
                { // Check if current window is smaller
                    minM = i - j + 1;
                    minLeft = j; // Update starting index of the smallest window
                }
                ms[s[j]]--; // Exclude the leftmost character
                if (mt.count(s[j]) && ms[s[j]] < mt[s[j]])
                {
                    windowSize--; // Decrement windowSize if character count is less than required
                }
                j++; // Move left pointer to the right
            }
        }

        // Step 5: Return the minimum window substring or an empty string if no valid window is found
        return minLeft == -1 ? "" : s.substr(minLeft, minM);
    }
};

// Time Complexity: O(n + m), where n is the length of string s and m is the length of string t
// Space Complexity: O(m), where m is the length of string t (to store the frequency map mt)
