#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            // Partition the array around pivot and get pivot index
            int pi = partition(arr, low, high);

            // Recursively sort elements before partition and after partition
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
        return;
    }

private:
    int partition(int arr[], int low, int high)
    {
        // Choosing the rightmost element as pivot
        int pivotEle = arr[high];
        int i = low - 1; // Index of smaller element

        for (int j = low; j < high; j++)
        {
            // If current element is smaller than or equal to pivot
            if (arr[j] < pivotEle)
            {
                i++; // Increment index of smaller element
                swap(arr[j], arr[i]);
            }
        }
        // Swap the pivot element with the element at i+1 position
        swap(arr[i + 1], arr[high]);
        return i + 1; // Return the partitioning index
    }

    // Utility function to swap two elements
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
    cin >> n; // Input size of the array
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Input array elements
    }

    Solution sol;
    sol.quickSort(arr, 0, n - 1); // Call quickSort on the array

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // Output sorted array
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:
- Best case: O(n log n) when the pivot divides the array into two nearly equal halves.
- Average case: O(n log n) which occurs for a random set of elements.
- Worst case: O(n^2) when the pivot is always the smallest or largest element, i.e., the array is already sorted or reverse sorted.

Space Complexity:
- O(log n) due to the recursive call stack in the average and best case scenarios.
- O(n) in the worst case due to the depth of the recursive call stack.
*/
