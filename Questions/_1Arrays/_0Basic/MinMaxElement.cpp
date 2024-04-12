#include <iostream>
#include <utility>
#include <climits>
using namespace std;

class Solution
{
public:
    // Function to find the minimum and maximum elements in an array
    pair<long long, long long> getMinMax(long long a[], int n)
    {
        long long maxi = 1, mini = INT_MAX; // Initialize maxi to 1 and mini to the largest possible integer value
        for (int i = 0; i < n; i++)
        {
            if (a[i] > maxi)
            {
                maxi = a[i]; // Update maxi if the current element is greater
            }
            if (a[i] < mini)
            {
                mini = a[i]; // Update mini if the current element is smaller
            }
        }
        return {mini, maxi}; // Return a pair containing the minimum and maximum elements
    }
};

int main()
{
    int n;
    cin >> n; // Input the size of the array

    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Input array elements
    }

    Solution obj;
    pair<long long, long long> result = obj.getMinMax(arr, n); // Get the minimum and maximum elements

    cout << "Minimum element: " << result.first << endl;  // Output the minimum element
    cout << "Maximum element: " << result.second << endl; // Output the maximum element

    return 0;
}

// Time Complexity (TC): O(N) - Where N is the size of the array, as we need to iterate through all elements once to find the minimum and maximum.
// Space Complexity (SC): O(1) - Only a few extra variables (maxi, mini) are used, and they don't depend on the size of the input array.
