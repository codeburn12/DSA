#include <iostream>
using namespace std;

void rotate(int arr[], int n)
{
    int temp = arr[0], next;
    for (int i = 1; i < n; i++)
    {
        next = arr[i]; // Store the next element to be rotated
        arr[i] = temp; // Move the current element to its rotated position
        temp = next;   // Update temp for the next iteration
    }
    arr[0] = temp; // Move the last element to the first position to complete the rotation
    return;
}

int main()
{
    int n;
    cin >> n; // Input the size of the array

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Input array elements
    }

    rotate(arr, n); // Rotate the array

    // Output the rotated array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// Time Complexity (TC): O(N) - Where N is the size of the array. The function iterates through the array once to perform the rotation.
// Space Complexity (SC): O(1) - Constant space complexity. The function uses a fixed amount of extra space regardless of the input size.
