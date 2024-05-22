#include <iostream>
#include <algorithm>
using namespace std;

bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size); // O(n log n) time complexity due to sorting

    int start = 0, end = 1;
    while (end < size)
    {
        int diff = arr[end] - arr[start]; // Calculate the difference between current pair elements

        if (diff == n)
        {
            return true; // Return true if the difference is equal to n
        }
        else if (diff < n)
        {
            end++; // Move end pointer to increase the difference
        }
        else
        {
            start++; // Move start pointer to decrease the difference
            if (start == end)
            {
                end++; // Avoid same element pair
            }
        }
    }
    return false; // Return false if no pair with difference n is found
}

int main()
{
    int size, n;
    cin >> size; // Input size of the array
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i]; // Input array elements
    }
    cin >> n; // Input target difference

    // Call the findPair function and print the result
    cout << (findPair(arr, size, n) ? "Yes" : "No") << endl;

    return 0;
}

//  time complexity of the is O(n log n) due to sorting.
// space complexity of the code is O(n) because we are storing the input array of size n.