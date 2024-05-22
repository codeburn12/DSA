#include <iostream>
using namespace std;

class Solution
{
public:
    string removeConsecutiveCharacter(string S)
    {
        string ans;
        int i = 0;
        while (i < S.size())
        { 
            if (i == 0 || S[i] != S[i - 1])
            { // Checking if it's the first character or not consecutive.
                ans.push_back(S[i]);
                i++;
            }
            else
            {
                while (i < S.size() && S[i] == S[i - 1])
                { // Skipping consecutive characters.
                    i++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    string input;
    cin >> input; // Taking input from the user.

    Solution obj;
    string result = obj.removeConsecutiveCharacter(input);
    cout << result; // Output the result without any additional statements.
    return 0;
}

// Time complexity: O(n) where n is the length of the input string S.
// Space Complexity: The space used is proportional to the length of the input string, so it's also O(n).