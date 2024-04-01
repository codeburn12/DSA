#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int isPalindrome(string S)
    {
        int i = 0;
        int j = S.length() - 1;
        while (i < j)
        {
            if (S[i++] != S[j--])
            {
                return 0;
            }
        }
        return 1;
    }
};

int main()
{
    Solution solution;
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int result = solution.isPalindrome(input);

    cout << "Is Palindrome: " << result << endl;

    return 0;
}

// Time Complexity: O(n/2) => O(n) where n is the length of the input string S
// Space Complexity: O(1) - only a constant amount of additional space is used
