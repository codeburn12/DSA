#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    int minSwaps(string s)
    {
        int len = s.length();
        if (len % 2 != 0)
        { // If the length of the string is odd, it's impossible to balance brackets
            return -1;
        }

        stack<char> st; // Stack to keep track of opening brackets
        int cnt = 0;    // Counter for unbalanced brackets

        for (auto c : s)
        {
            if (c == '[')
            { // If it's an opening bracket, push it onto the stack
                st.push(c);
            }
            else if (c == ']' && !st.empty())
            {             // If it's a closing bracket and there's a corresponding opening bracket
                st.pop(); // Pop the opening bracket from the stack
            }
            else
            {                 // If it's a closing bracket with no corresponding opening bracket
                st.push('['); // Push an opening bracket onto the stack to balance it
                cnt++;        // Increment the counter for unbalanced brackets
            }
        }

        cnt += st.size() / 2; // Add half of the remaining unmatched opening brackets to the counter
        return cnt / 2;       // Return half of the total number of unbalanced brackets, which represents the minimum swaps needed
    }
};

int main()
{
    Solution sol;
    string input;
    cout << "Enter a string of square brackets ([ and ]): ";
    cin >> input;
    int swaps = sol.minSwaps(input);
    if (swaps == -1)
    {
        cout << "The input string has an odd length, so it's impossible to balance the brackets.";
    }
    else
    {
        cout << "Minimum swaps needed to balance the brackets: " << swaps;
    }
    return 0;
}
// time complexity of O(n), where n is the length of the input string, because it iterates through the string once. 
// The space complexity is also O(n) due to the stack used to store opening brackets.