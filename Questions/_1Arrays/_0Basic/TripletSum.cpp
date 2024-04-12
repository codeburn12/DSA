#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Function to find if there exists a triplet in the array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A, A + n); // Sort the array in ascending order

        for (int i = 0; i <= n - 3; i++)
        {
            int first = i + 1;
            int last = n - 1;

            // Use two-pointer technique to find the triplet sum
            while (first <= last - 1)
            {
                int sum = A[i] + A[first] + A[last];
                if (sum == X)
                {
                    return true; // Triplet found
                }
                else if (sum < X)
                {
                    first++; // Increase the first pointer
                }
                else
                {
                    last--; // Decrease the last pointer
                }
            }
        }
        return false; // Triplet not found
    }
};

int main()
{
    int n, X;
    cin >> n >> X; // Input the size of the array and the target sum X

    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i]; // Input array elements
    }

    Solution obj;
    bool result = obj.find3Numbers(A, n, X); // Check if a triplet exists with sum X

    // Output the result
    cout << (result ? "Yes" : "No") << endl;
    return 0;
}

// Time Complexity (TC): O(n^2) - Quadratic time complexity due to nested loops and sorting. The function sorts the array in O(n log n) time and then iterates through the array with two nested loops, each taking O(n) time.
// Space Complexity (SC): O(1) - Constant space complexity. The function uses only a few integer variables and doesn't require any additional data structures that depend on the input size.
