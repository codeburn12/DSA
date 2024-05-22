#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to find the first repeated character in a string
string firstRepChar(string s)
{
    // Create a vector to store the frequency of each character
    vector<int> vec(26, 0); // Initialize a vector of size 26 (for each alphabet letter) with 0

    // Iterate over each character in the string
    for (int i = 0; i < s.length(); i++)
    {
        // Check if the character has already been seen once
        if (vec[s[i] - 'a'] == 1)
        {
            return string(1, s[i]); // Return the first repeated character
        }
        else
        {
            vec[s[i] - 'a']++; // Increment the frequency of the character
        }
    }
    return "-1"; // Return "-1" if no repeated character is found
}

int main()
{
    string s;
    cin >> s;                        // Take input string from the user
    cout << firstRepChar(s) << endl; // Output the first repeated character or "-1"
    return 0;
}

/*
Time Complexity: O(n)
- We iterate over the string once, where n is the length of the string.
- Each operation inside the loop is O(1) since vector access and updates are constant time operations.

Space Complexity: O(1)
- We use a vector of fixed size 26, which is independent of the input size.
- No additional space is used that grows with the input size.
*/
