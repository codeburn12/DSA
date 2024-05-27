#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to calculate the nth Fibonacci number modulo 1000000007
    int nthFibonacci(int n)
    {
        const int MOD = 1000000007; // Define the modulo value as a constant

        // Base cases: return n if n is 0 or 1
        if (n <= 1)
        {
            return n;
        }

        int a = 0; // Initialize a to store F(0)
        int b = 1; // Initialize b to store F(1)

        // Loop to calculate the nth Fibonacci number
        for (int i = 2; i <= n; i++)
        {
            int c = (a + b) % MOD; // Calculate the next Fibonacci number modulo MOD
            a = b;                 // Update a to the previous b
            b = c;                 // Update b to the new Fibonacci number
        }

        // Return the nth Fibonacci number
        return b;
    }
};

int main()
{
    int n;    // Variable to store the user input
    cin >> n; // Take input from the user

    Solution sol;                        // Create an instance of the Solution class
    cout << sol.nthFibonacci(n) << endl; // Call the nthFibonacci function and print the result

    return 0; // Return 0 to indicate successful execution
}

/*
Time Complexity: O(n)
The function calculates the Fibonacci number iteratively up to n, so it runs in linear time relative to n.

Space Complexity: O(1)
The function uses a constant amount of space, regardless of the input size n.
*/
