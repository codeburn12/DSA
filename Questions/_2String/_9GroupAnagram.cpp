#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;               // This will hold the final grouped anagrams
        unordered_map<string, vector<string>> um; // This map will group strings by their sorted version

        // Iterate over each string in the input vector
        for (auto str : strs)
        {
            string s = str;           // Copy the current string
            sort(s.begin(), s.end()); // Sort the characters of the string
            um[s].push_back(str);     // Use the sorted string as the key and add the original string to the map
        }

        // Iterate over the map to construct the final answer
        for (auto it : um)
        {
            ans.push_back(it.second); // Each value in the map is a group of anagrams
        }

        return ans; // Return the grouped anagrams
    }
};

int main()
{
    // Read input from the user
    int n;
    cin >> n; // Number of strings
    vector<string> strs(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> strs[i];
    }

    Solution solution;
    vector<vector<string>> result = solution.groupAnagrams(strs);

    // Print the result
    for (const auto &group : result)
    {
        for (const auto &word : group)
        {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Time Complexity:
The overall time complexity is O(N * K * log K), where N is the number of strings and K is the maximum length of a string.
- Sorting each string takes O(K * log K) time.
- Inserting each string into the map and then constructing the result takes O(N * K) time.

Space Complexity:
The space complexity is O(N * K).
- The unordered_map stores all the strings, which takes up O(N * K) space.
- The space used for the output vector is also O(N * K).
*/
