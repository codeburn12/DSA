#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        // Uncomment the method you want to use

        // Memoization
        // vector<int> vec(n + 1, -1);
        // return memoize(n, vec);

        // Tabulation
        // return tabulation(n);

        // Space Optimized
        return spaceOptimized(n);
    }

    // Memoization approach
    int memoize(int n, vector<int> &vec)
    {
        if (n <= 1)
            return n; // Base cases: fib(0) = 0, fib(1) = 1

        if (vec[n] != -1)
            return vec[n]; // Return already computed value

        return vec[n] = memoize(n - 1, vec) + memoize(n - 2, vec); // Recursively compute fib(n)
    }

    // Tabulation approach
    int tabulation(int n)
    {
        if (n <= 1)
            return n; // Base cases: fib(0) = 0, fib(1) = 1

        vector<int> dp(n + 1, -1); // Initialize DP array

        dp[0] = 0; // Base case
        dp[1] = 1; // Base case

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2]; // Fill DP table
        }

        return dp[n]; // Return result
    }

    // Space Optimized approach
    int spaceOptimized(int n)
    {
        if (n <= 1)
            return n; // Base cases: fib(0) = 0, fib(1) = 1

        int prev1 = 1; // Previous value fib(n-1)
        int prev2 = 0; // Previous value fib(n-2)

        for (int i = 2; i <= n; i++)
        {
            int curr = prev1 + prev2; // Current value fib(n)
            prev2 = prev1;            // Update prev2 to fib(n-1)
            prev1 = curr;             // Update prev1 to fib(n)
        }

        return prev1; // Return result
    }
};

int main()
{
    int n;
    cin >> n; // Take input from user
    Solution solution;
    cout << solution.fib(n) << endl; // Print the Fibonacci number
    return 0;
}

/*
Time and Space Complexities:
1. Memoization:
   - Time Complexity: O(n) - Each value from 0 to n is computed once.
   - Space Complexity: O(n) - Additional space for the memoization array.

2. Tabulation:
   - Time Complexity: O(n) - Single loop from 2 to n.
   - Space Complexity: O(n) - Additional space for the DP array.

3. Space Optimized:
   - Time Complexity: O(n) - Single loop from 2 to n.
   - Space Complexity: O(1) - Constant space usage for variables.
*/
