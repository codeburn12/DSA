#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isShuffledSubstring(string str1, string str2)
{
    if (str1.length() > str2.length())
    {
        return false; // If length of str1 is greater than str2, str1 cannot be a substring of shuffled str2
    }

    sort(str1.begin(), str1.end()); // Sort the characters of str1
    for (size_t i = 0; i <= str2.length() - str1.length(); ++i)
    {
        string sub = str2.substr(i, str1.length()); // Get substring of str2 of the same length as str1
        sort(sub.begin(), sub.end());               // Sort the characters of the substring
        if (sub == str1)
        {
            return true; // If the sorted substring matches the sorted str1, it's a match
        }
    }
    return false; // No match found
}

int main()
{
    string str1, str2;
    cout << "Enter string str1: ";
    cin >> str1;
    cout << "Enter string str2: ";
    cin >> str2;

    bool result = isShuffledSubstring(str1, str2);

    cout << (result ? "YES" : "NO") << endl;
    return 0;
}

// Time Complexity: O(m*n*log(n)) where m is the length of str1, n is the length of str2
// Space Complexity: O(n) for sorting the substring of str2, where n is the length of str2
