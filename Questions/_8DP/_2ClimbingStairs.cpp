#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        // Initialize a dp array for memoization with size n+1 and all values set to -1
        vector<int> dp(n + 1, -1);

        // Uncomment one of the following lines to use a specific approach:
        // return memoization(dp, n); // Use memoization
        // return tabulation(n);      // Use tabulation
        return spaceOptimization(n); // Use space optimization
    }

    // Memoization approach (Top-Down)
    int memoization(vector<int> &dp, int n)
    {
        // Base cases: if n is 0 or 1, there's only one way to climb the stairs
        if (n == 0 || n == 1)
        {
            return 1;
        }

        // If the value has already been computed, return it
        if (dp[n] != -1)
        {
            return dp[n];
        }

        // Recursively calculate the number of ways to climb n-1 and n-2 stairs
        int one = memoization(dp, n - 1);
        int two = memoization(dp, n - 2);

        // Store the result in the dp array and return it
        return dp[n] = one + two;
    }

    // Tabulation approach (Bottom-Up)
    int tabulation(int n)
    {
        // If there's only one stair, there's only one way to climb it
        if (n == 1)
        {
            return 1;
        }

        // Initialize a dp array with size n+1
        vector<int> dp(n + 1, -1);

        // Base cases
        dp[0] = 1;
        dp[1] = 1;

        // Fill the dp array using the bottom-up approach
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // Return the result for n stairs
        return dp[n];
    }

    // Space Optimization approach
    int spaceOptimization(int n)
    {
        // If there's only one stair, there's only one way to climb it
        if (n == 1)
        {
            return 1;
        }

        // Initialize two variables to store the results for the last two steps
        int prev1 = 1;
        int prev2 = 1;

        // Calculate the number of ways to climb the stairs using two variables
        for (int i = 2; i <= n; i++)
        {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        // Return the result for n stairs
        return prev1;
    }
};

int main()
{
    // Read the input value
    int n;
    cin >> n;

    // Create an instance of the Solution class
    Solution sol;

    // Call the climbStairs function and print the result
    cout << sol.climbStairs(n) << endl;

    return 0;
}

/*
Time Complexity:
- Memoization: O(n) because each state is computed only once.
- Tabulation: O(n) because we iterate from 0 to n.
- Space Optimization: O(n) because we iterate from 0 to n.

Space Complexity:
- Memoization: O(n) for the dp array and O(n) for the recursion stack.
- Tabulation: O(n) for the dp array.
- Space Optimization: O(1) since we use only two variables.
*/
