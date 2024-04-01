#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<pair<char, int>> duplicate_char(const string &s)
    {
        map<char, int> um;
        vector<pair<char, int>> ans;

        for (auto str : s)
        {
            um[str]++;
        }

        for (auto it : um)
        {
            if (it.second >= 2)
            {
                ans.push_back({it.first, it.second});
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string input;
    getline(cin, input);

    vector<pair<char, int>> result = solution.duplicate_char(input);

    for (auto p : result)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}

// Time Complexity: O(n*log(n)) - due to sorting in map (n is the length of the input string)
// Time Complexity: O(n) - where n = length of the string passed and it takes O(1) time to insert and access any element in an unordered map
// Space Complexity: O(n) - to store the characters and their counts in the map
