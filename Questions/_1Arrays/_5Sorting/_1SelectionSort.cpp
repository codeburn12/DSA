#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to perform selection sort on the array
    void selectionSort(int arr[], int n)
    {
        // Iterate over each element in the array except the last one
        for (int i = 0; i < n - 1; i++)
        {
            // Assume the current index is the minimum
            int minIdx = i;

            // Iterate over the unsorted part of the array
            for (int j = i + 1; j < n; j++)
            {
                // If the current element is smaller than the current minimum, update minIdx
                if (arr[j] < arr[minIdx])
                {
                    minIdx = j;
                }
            }

            // Swap the found minimum element with the first element of the unsorted part
            swap(arr[i], arr[minIdx]);
        }
    }

    // Function to swap two elements in the array
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
};

int main()
{
    int n;
    cin >> n; // Read the size of the array
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Read array elements
    }

    Solution sol;
    sol.selectionSort(arr, n); // Sort the array using selection sort

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // Print sorted array
    }

    return 0;
}

/*
Time Complexity:
- The time complexity of the selection sort algorithm is O(n^2) in all cases (best, average, and worst) because it always scans the remaining elements to find the minimum element.

Space Complexity:
- The space complexity of the selection sort algorithm is O(1) because it sorts the array in place without requiring any additional storage.
*/
