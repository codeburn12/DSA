#include <iostream>
#include <utility>
#include <climits>

using namespace std;

class Solution
{
public:
    pair<long long, long long> getMinMax(long long a[], int n)
    {
        long long maxi = LLONG_MIN, mini = LLONG_MAX; // Use LLONG_MIN and LLONG_MAX for long long types
        for (int i = 0; i < n; i++)
        {
            if (a[i] > maxi)
            {
                maxi = a[i];
            }
            if (a[i] < mini)
            {
                mini = a[i];
            }
        }
        return {mini, maxi};
    }
};

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    long long arr[n];
    cout << "Enter " << n << " elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    pair<long long, long long> result = obj.getMinMax(arr, n);

    cout << "Minimum element: " << result.first << endl;
    cout << "Maximum element: " << result.second << endl;

    return 0;
}

// Space Complexity : O(1) - Only a few extra variables are used.
// Time Complexity : O(N) - Where N is the size of the array, as we need to iterate through all elements once to find the minimum and maximum.
