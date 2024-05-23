#include <iostream>
using namespace std;

class Solution
{
public:
    int inSequence(int A, int B, int C)
    {
        // If A is equal to B and the common difference is zero,
        // it means we are already at the desired number in the sequence
        if (A == B && C == 0)
        {
            return 1;
        }

        // Calculate the difference between B and A
        int diff = B - A;

        // Check if C is not zero and if diff is a multiple of C
        // Also, ensure the number of steps (diff / C) is non-negative
        if (C != 0 && diff % C == 0 && diff / C >= 0)
        {
            return 1;
        }

        // If none of the conditions are met, B is not in the sequence
        return 0;
    }
};

int main()
{
    // Create a Solution object
    Solution sol;

    // Variables to hold user input
    int A, B, C;

    // Taking input directly from the user
    cin >> A >> B >> C;

    // Call the inSequence method and output the result
    cout << sol.inSequence(A, B, C) << endl;

    return 0;
}

/*
Time Complexity: O(1)
- The solution performs a constant amount of work regardless of the input values. The operations are basic arithmetic checks and a single division/modulus operation.

Space Complexity: O(1)
- The solution uses a constant amount of space. No additional data structures are used that grow with the input size.
*/
