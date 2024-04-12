#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to sort an array of 0s, 1s, and 2s in O(n) time and O(1) space
    void sort012(int array[], int n)
    {
        // Initialize three pointers: low, mid, and high
        int low = 0, mid = 0, high = n - 1;

        // Loop until mid crosses the high pointer
        while (mid <= high)
        {
            // If the element at mid is 0, swap it with the element at low and move both pointers
            if (array[mid] == 0)
            {
                swap(array[low], array[mid]);
                low++;
                mid++;
            }
            // If the element at mid is 1, move mid pointer to the next element
            else if (array[mid] == 1)
            {
                mid++;
            }
            // If the element at mid is 2, swap it with the element at high and move high pointer backward
            else
            {
                swap(array[mid], array[high]);
                high--;
            }
        }
        // Sorting is complete
        return;
    }
};

int main()
{
    int n;
    cin >> n; // Input the size of the array

    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i]; // Input array elements
    }

    Solution obj;
    obj.sort012(array, n); // Sort the array

    // Output the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}

// Time Complexity (TC): O(n) - Linear time complexity as the function iterates through each element of the array exactly once.
// Space Complexity (SC): O(1) - Constant space complexity as the function uses a fixed number of integer variables regardless of input size.
