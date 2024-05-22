#include <iostream>
#include <string>
using namespace std;

bool isRotated(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return false; // Strings must have equal length to be rotations of each other
    }

    string concatenated = s1 + s1;                // Concatenate s1 with itself
    return concatenated.find(s2) != string::npos; // Check if s2 is a substring of concatenated s1
}

int main()
{
    string s1, s2;
    cout << "Enter string s1: ";
    cin >> s1;
    cout << "Enter string s2: ";
    cin >> s2;

    bool result = isRotated(s1, s2);

    cout << "Is s2 a rotated version of s1? " << (result ? "Yes" : "No") << endl;

    return 0;
}

// Time Complexity: O(n+m) where n is the length of s1, m is the length of s2
// Space Complexity: O(n+m) for creating the concatenated string, where n is the length of s1, m is the length of s2
