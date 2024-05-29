#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st; // Stack to keep track of opening brackets

        // Iterate through each character in the string
        for (auto c : s)
        {
            // If the character is an opening bracket, push it onto the stack
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                // If the stack is empty, it means there is no matching opening bracket
                if (st.empty())
                    return false;

                // Check if the top of the stack matches the current closing bracket
                if (st.top() == '(' && c != ')')
                    return false;
                if (st.top() == '{' && c != '}')
                    return false;
                if (st.top() == '[' && c != ']')
                    return false;

                // If it matches, pop the top of the stack
                st.pop();
            }
        }
        // If the stack is empty at the end, all brackets were matched
        return st.empty();
    }
};

int main()
{
    string input;
    cin >> input; // Take input from the user

    Solution sol;
    bool result = sol.isValid(input);

    cout << (result ? "true" : "false") << endl; // Output the result

    return 0;
}

/*
Time Complexity: O(n)
- We iterate through the string of length 'n' once, performing O(1) operations for each character.
- Therefore, the time complexity is O(n).

Space Complexity: O(n)
- In the worst case, all opening brackets are pushed onto the stack, which takes O(n) space.
- Therefore, the space complexity is O(n).
*/
