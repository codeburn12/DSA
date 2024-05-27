#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to calculate GCD of two numbers using Euclidean algorithm
    long long calculateGCD(long long a, long long b)
    {
        // Base case: if b is 0, gcd is a
        if (b == 0)
        {
            return a;
        }
        else
        {
            // Recursive call: gcd(b, a % b)
            return calculateGCD(b, a % b);
        }
    }

    // Function to calculate LCM of two numbers
    long long calculateLCM(long long a, long long b)
    {
        // LCM formula: (a * b) / GCD(a, b)
        return (a * b) / calculateGCD(a, b);
    }

    // Function to return both LCM and GCD of two numbers
    vector<long long> lcmAndGcd(long long A, long long B)
    {
        // Return a vector containing LCM and GCD
        return {calculateLCM(A, B), calculateGCD(A, B)};
    }
};

int main()
{
    long long A, B;
    // Take input from user without any statement
    cin >> A >> B;

    Solution sol;
    // Get the LCM and GCD
    vector<long long> result = sol.lcmAndGcd(A, B);

    // Output the results
    cout << result[0] << " " << result[1];

    return 0;
}

/*
Time Complexity:
- The `calculateGCD` function has a time complexity of O(log(min(a, b))) due to the Euclidean algorithm.
- The `calculateLCM` function calls the `calculateGCD` function and performs constant time arithmetic operations, so its time complexity is also O(log(min(a, b))).
- The `lcmAndGcd` function combines these calls and performs constant time operations, so its overall time complexity is O(log(min(a, b))).

Space Complexity:
- The space complexity is O(1) as we are using a fixed amount of extra space regardless of the input size.
- The recursive calls in `calculateGCD` use stack space, but this is also O(log(min(a, b))) in the worst case.
*/
