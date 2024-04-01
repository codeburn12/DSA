#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
};

int main()
{
    Solution solution;
    vector<char> input;
    char c;

    cout << "Enter characters (press Enter after each character, type 'done' to finish):" << endl;
    while (cin >> c && c != 'd')
    {
        input.push_back(c);
    }

    solution.reverseString(input);

    return 0;
}

// Time Complexity: O(n) where n is the length of the input vector s
// Space Complexity: O(1) - no additional space is used other than the input vector
