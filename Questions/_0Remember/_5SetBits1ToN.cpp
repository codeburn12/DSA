#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to return the sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Base case: if n is 0, there are no set bits.
        if (n == 0)
        {
            return 0;
        }

        // Find the largest power of 2 (2^x) less than or equal to n.
        int largestPowerOf2InRangeOfN = 0;
        while ((1 << largestPowerOf2InRangeOfN) <= n)
        {
            largestPowerOf2InRangeOfN++;
        }
        largestPowerOf2InRangeOfN -= 1; // Decrement to get the actual power.

        // Count the number of set bits in numbers from 1 to the largest power of 2 less than or equal to n.
        // setBitsTillLargestPowerOf2InRangeOfN gives the total count of set bits for the range 1 to (2^largestPowerOf2InRangeOfN) - 1.
        int setBitsTillLargestPowerOf2InRangeOfN = (1 << (largestPowerOf2InRangeOfN - 1)) * largestPowerOf2InRangeOfN;

        // Count the most significant bits from the largest power of 2 to n.
        int mostSignificantBitsFromLargestPowerOf2InRangeOfN_To_N = n - (1 << largestPowerOf2InRangeOfN) + 1;

        // Count the set bits in the rest of the numbers (from largest power of 2 to n).
        int restBits = n - (1 << largestPowerOf2InRangeOfN);

        // Sum the results from the three parts to get the final count of set bits.
        int ans = setBitsTillLargestPowerOf2InRangeOfN + mostSignificantBitsFromLargestPowerOf2InRangeOfN_To_N + countSetBits(restBits);

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution solution;
    cout << solution.countSetBits(n) << endl;
    return 0;
}

// Time Complexity: O(log n)
// The time complexity is O(log n) because in each recursive step, the problem size reduces by approximately half.
// This results in at most log2(n) recursive calls.

// Space Complexity: O(log n)
// The space complexity is also O(log n) due to the recursive call stack. In the worst case, the depth of the recursion is log2(n).
