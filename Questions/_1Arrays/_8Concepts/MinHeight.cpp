#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {
        sort(arr, arr + n); // Sort the array to make calculations easier
        int minHeight, maxHeight;
        int diff = arr[n - 1] - arr[0]; // Initialize the difference with the maximum possible value

        for (int i = 1; i < n; i++)
        {
            if (arr[i] >= k)
            {                                                    // Check if the tower height is greater than or equal to k
                maxHeight = max(arr[i - 1] + k, arr[n - 1] - k); // Adjust the tallest tower height
                minHeight = min(arr[0] + k, arr[i] - k);         // Adjust the shortest tower height
                diff = min(diff, maxHeight - minHeight);         // Update the minimum difference
            }
        }

        return diff;
    }
};

int main()
{
    int n, k;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;

    Solution sol;
    int minDiff = sol.getMinDiff(arr, n, k);

    cout << minDiff << endl;

    return 0;
}

/*
Time Complexity (TC): O(n log n) due to sorting
Space Complexity (SC): O(1) since the algorithm uses only a few extra variables regardless of the input size
*/
