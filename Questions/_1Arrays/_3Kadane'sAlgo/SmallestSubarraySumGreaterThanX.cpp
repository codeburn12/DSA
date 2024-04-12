#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n)
    {
        long long maxi = arr[0], sum = 0; // Initialize variables for maximum sum and current sum

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];         // Add current element to sum
            maxi = max(maxi, sum); // Update maximum sum if needed

            if (sum < 0)
            {
                sum = 0; // Reset sum if it becomes negative
            }
        }
        return maxi; // Return maximum sum
    }
};

int main()
{
    int n;
    cin >> n; // Input the size of the array

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Input array elements
    }

    Solution obj;
    long long result = obj.maxSubarraySum(arr, n); // Calculate maximum subarray sum

    // Output the result
    cout << result << endl;
    return 0;
}

// Time Complexity (TC): O(n) - Linear time complexity where n is the size of the input array. The function iterates through the array once.
// Space Complexity (SC): O(1) - Constant space complexity as the function uses a fixed number of variables regardless of input size.
