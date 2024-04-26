#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Function to merge two sorted arrays in-place
    void merge(vector<int> &arr1, int m, vector<int> &arr2, int n)
    {
        int i = m - 1, j = 0; // Start from the end of arr1 and the beginning of arr2

        // Merge elements from arr2 into arr1 in sorted order
        while (i >= 0 && j < n)
        {
            if (arr1[i] >= arr2[j])
            {
                swap(arr1[i], arr2[j]); // Swap elements if necessary
                i--;
                j++;
            }
            else
            {
                j++;
            }
        }

        sort(arr2.begin(), arr2.end()); // Sort arr2 after merging

        j = 0;
        for (int i = m; i < m + n; i++)
        {
            arr1[i] = arr2[j++]; // Copy elements from sorted arr2 to the end of arr1
        }

        sort(arr1.begin(), arr1.end()); // Sort arr1 after merging
    }
};

int main()
{
    int m, n;
    cin >> m >> n; // Input the sizes of arr1 and arr2

    vector<int> arr1(m + n), arr2(n);

    for (int i = 0; i < m; i++)
    {
        cin >> arr1[i]; // Input elements of arr1
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i]; // Input elements of arr2
    }

    Solution obj;
    obj.merge(arr1, m, arr2, n); // Merge arr1 and arr2

    for (int num : arr1)
    {
        cout << num << " "; // Output merged array
    }
    cout << endl;

    return 0;
}

// Time Complexity (TC): O((m + n) log (m + n)) - Due to sorting operations on arr1 and arr2.
// Space Complexity (SC): O(1) - Constant space complexity as no additional space is used except for a few variables regardless of input size.
