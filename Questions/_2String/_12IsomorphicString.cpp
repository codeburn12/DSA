#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    // Function to check if two strings are isomorphic
    bool isIsomorphic(string str1, string str2)
    {
        int m = str1.length(), n = str2.length();
        // If lengths are different, strings cannot be isomorphic
        if (m != n)
        {
            return false;
        }

        // Maps to store mappings from characters of str1 to str2 and vice versa
        unordered_map<char, char> um, memo;

        for (int i = 0; i < m; i++)
        {
            char str1Char = str1[i];
            char str2Char = str2[i];

            // If mapping already exists but doesn't match current characters, return false
            if ((um.find(str1Char) != um.end() && um[str1Char] != str2Char) ||
                (memo.find(str2Char) != memo.end() && memo[str2Char] != str1Char))
            {
                return false;
            }
            // Update mappings
            um[str1Char] = str2Char;
            memo[str2Char] = str1Char;
        }
        // If all mappings are consistent, return true
        return true;
    }
};

int main()
{
    // Taking input from the user
    string str1, str2;
    cin >> str1 >> str2;

    // Creating an instance of the Solution class
    Solution sol;

    // Calling the isIsomorphic function and printing the result
    if (sol.isIsomorphic(str1, str2))
    {
        cout << "The strings are isomorphic." << endl;
    }
    else
    {
        cout << "The strings are not isomorphic." << endl;
    }

    return 0;
}
/*
Time complexity: Let m be the length of str1 and n be the length of str2. The time complexity of the isIsomorphic function is O(m) because the function iterates through the strings once to check for isomorphism.

Space complexity: The space complexity is also O(m) because of the unordered maps um and memo which can potentially store up to m unique characters from str1 and str2.
*/