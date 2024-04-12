#include <iostream>
using namespace std;

class Solution
{
public:
    int minSwap(int arr[], int n, int k)
    {
        // Count the number of elements less than or equal to k
        int lessThanK = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= k)
            {
                lessThanK++;
            }
        }

        // Count the number of elements greater than k within the first 'lessThanK' elements
        int greaterThanK = 0;
        for (int i = 0; i < lessThanK; i++)
        {
            if (arr[i] > k)
            {
                greaterThanK++;
            }
        }

        int minSwaps = greaterThanK, i = 0;
        int j = lessThanK;
        while (j < n)
        {
            if (arr[i] > k)
            {
                greaterThanK--; // Decrement count if element is moved out of the window
            }
            if (arr[j] > k)
            {
                greaterThanK++; // Increment count if element is moved into the window
            }
            minSwaps = min(minSwaps, greaterThanK);
            i++;
            j++;
        }
        return minSwaps; // Return the minimum number of swaps required
    }
};

int main()
{
    int n, k;
    cin >> n >> k; // Input the size of the array and the value k

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Input array elements
    }

    Solution obj;
    int result = obj.minSwap(arr, n, k); // Calculate minimum swaps required

    // Output the result
    cout << result << endl;
    return 0;
}

// Time Complexity (TC): O(n) - Linear time complexity where n is the size of the input array. The function iterates through the array once.
// Space Complexity (SC): O(1) - Constant space complexity as the function uses only a fixed number of variables regardless of input size.
