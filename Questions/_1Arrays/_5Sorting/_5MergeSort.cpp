#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to merge two halves of the array
    void merge(int arr[], int l, int m, int r)
    {
        // Calculate lengths of the two halves
        int leftArrayLen = m - l + 1;
        int rightArrayLen = r - m;

        // Create temporary arrays for left and right halves
        int leftArray[leftArrayLen], rightArray[rightArrayLen];

        // Copy data to temporary arrays leftArray and rightArray
        for (int i = 0; i < leftArrayLen; i++)
        {
            leftArray[i] = arr[l + i];
        }
        for (int i = 0; i < rightArrayLen; i++)
        {
            rightArray[i] = arr[m + 1 + i];
        }

        // Initial indexes for leftArray, rightArray, and merged array
        int i = 0, j = 0, k = l;

        // Merge the temporary arrays back into arr[l..r]
        while (i < leftArrayLen && j < rightArrayLen)
        {
            if (leftArray[i] <= rightArray[j])
            {
                arr[k] = leftArray[i++];
            }
            else
            {
                arr[k] = rightArray[j++];
            }
            k++;
        }

        // Copy any remaining elements of leftArray, if any
        while (i < leftArrayLen)
        {
            arr[k] = leftArray[i++];
            k++;
        }

        // Copy any remaining elements of rightArray, if any
        while (j < rightArrayLen)
        {
            arr[k] = rightArray[j++];
            k++;
        }
    }

    // Function to implement merge sort
    void mergeSort(int arr[], int l, int r)
    {
        if (l < r)
        {
            // Find the middle point
            int mid = l + (r - l) / 2;

            // Recursively sort the first and second halves
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);

            // Merge the sorted halves
            merge(arr, l, mid, r);
        }
    }
};

int main()
{
    int n;
    cin >> n; // Input size of array
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Input elements of array
    }

    Solution ob;
    ob.mergeSort(arr, 0, n - 1); // Call mergeSort function

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // Output sorted array
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:
- The time complexity of merge sort is O(n log n) in all three cases (worst, average, and best) because it always divides the array into two halves and takes linear time to merge two halves.

Space Complexity:
- The space complexity of merge sort is O(n) due to the temporary arrays used for merging. This includes the space taken by the call stack during recursion.
*/
