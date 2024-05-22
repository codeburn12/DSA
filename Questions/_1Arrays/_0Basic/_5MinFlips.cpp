
#include <iostream>
#include <algorithm>
using namespace std;

int minFlips(string s)
{
    int flipsStartWithZero = 0; // Count flips needed if starting with 0
    int flipsStartWithOne = 0;  // Count flips needed if starting with 1

    // Calculate flips needed to start with 0
    for (int i = 0; i < s.length(); i++)
    {
        if (i % 2 == 0)
        { // Even index should have 0
            if (s[i] != '0')
            {
                flipsStartWithZero++;
            }
        }
        else
        { // Odd index should have 1
            if (s[i] != '1')
            {
                flipsStartWithZero++;
            }
        }
    }

    // Calculate flips needed to start with 1
    for (int i = 0; i < s.length(); i++)
    {
        if (i % 2 == 0)
        { // Even index should have 1
            if (s[i] != '1')
            {
                flipsStartWithOne++;
            }
        }
        else
        { // Odd index should have 0
            if (s[i] != '0')
            {
                flipsStartWithOne++;
            }
        }
    }

    // Return the minimum flips needed
    return min(flipsStartWithZero, flipsStartWithOne);
}

int main()
{
    string s;
    cin >> s;
    cout << minFlips(s) << endl;
    return 0;
}

/*
 * The function minFlips calculates the minimum number of flips required to make a binary string alternate starting either with '0' or '1'.
 *
 * Time Complexity: O(n), where n is the length of the string. This is because we iterate through the string twice.
 *
 * Space Complexity: O(1), as we are using a constant amount of extra space.
 */
