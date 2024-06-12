#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n)
    {
        // Outer loop to traverse through the entire array
        for (int i = 0; i < n - 1; i++)
        {
            // Inner loop to compare adjacent elements
            for (int j = 0; j < n - i - 1; j++)
            {
                // If the current element is greater than the next element, swap them
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
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
    // Taking input for the size of the array
    cin >> n;
    int arr[n];
    // Taking input for the elements of the array
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Creating an object of the Solution class
    Solution obj;
    // Calling the bubbleSort function to sort the array
    obj.bubbleSort(arr, n);

    // Outputting the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
Time Complexity:
- Best Case: O(n) [When the array is already sorted]
- Average Case: O(n^2) [When the array elements are in random order]
- Worst Case: O(n^2) [When the array is sorted in reverse order]

Space Complexity:
- O(1) [Only a constant amount of extra space is used for variables]
*/
