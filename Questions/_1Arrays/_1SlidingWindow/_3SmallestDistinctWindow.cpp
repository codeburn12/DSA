#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findSubString(string str)
    {
        // To keep track of the frequency of characters in the current window
        unordered_map<char, int> um;
        // To find out the number of unique characters in the input string
        unordered_set<char> us(str.begin(), str.end());
        // Initialize two pointers for the sliding window technique
        int j = 0;
        // Variable to store the minimum length of the substring that contains all unique characters
        int minM = str.size();
        // Total number of unique characters in the input string
        int uniqueEle = us.size();

        // Iterate over the input string with the end pointer of the sliding window
        for (int i = 0; i < str.size(); i++)
        {
            // Increment the frequency count of the current character
            um[str[i]]++;
            // If the current window contains all unique characters
            while (um.size() == uniqueEle)
            {
                // Update the minimum length of such a window
                minM = min(minM, i - j + 1);
                // Decrement the frequency count of the character at the start of the window
                um[str[j]]--;
                // If the frequency count of the start character becomes zero, remove it from the map
                if (um[str[j]] == 0)
                {
                    um.erase(str[j]);
                }
                // Move the start pointer to the right
                j++;
            }
        }
        // Return the length of the smallest substring that contains all unique characters
        return minM;
    }
};

int main()
{
    // Take input from the user
    string str;
    cin >> str;

    // Create an object of the Solution class
    Solution sol;
    // Find the length of the smallest substring that contains all unique characters
    int result = sol.findSubString(str);

    // Output the result
    cout << result << endl;
    return 0;
}

/*
Time Complexity:
O(N): Where N is the length of the input string. The algorithm iterates through the string once with the end pointer i and the start pointer j moves at most N times. Each character is processed a constant number of times.
Space Complexity:
O(U): Where U is the number of unique characters in the input string. This is because we use an unordered map to store the frequency of characters in the current window, and the size of the map is bounded by the number of unique characters. The unordered set used for finding the number of unique characters also takes up O(U) space.
*/