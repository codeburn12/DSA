#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        int key, j;

        // Loop over the array from the second element to the end
        for (int i = 1; i < n; i++)
        {
            // Select the current element as the key
            key = arr[i];
            // Initialize j to the index of the previous element
            j = i - 1;

            // Move elements of arr[0..i-1], that are greater than key,
            // to one position ahead of their current position
            while (j >= 0 && key < arr[j])
            {
                arr[j + 1] = arr[j];
                j--;
            }
            // Place the key at its correct position
            arr[j + 1] = key;
        }
    }
};

int main()
{
    int n;
    cin >> n; // Input the size of the array
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Input the elements of the array
    }

    Solution sol;
    sol.insertionSort(arr, n); // Call the insertion sort function

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // Output the sorted array
    }

    return 0;
}

/*
Time Complexity:
- Best Case: O(n) when the array is already sorted.
- Average and Worst Case: O(n^2) when the array is in reverse order.

Space Complexity:
- O(1) since we are using a constant amount of extra space.
*/
