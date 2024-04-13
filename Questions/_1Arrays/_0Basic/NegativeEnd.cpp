#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to segregate positive and negative elements in an array
    void segregateElements(int arr[], int n)
    {
        int left = 0, right = n - 1;

        while (left <= right)
        {
            if (arr[left] < 0 && arr[right] >= 0)
            {
                swap(arr[left], arr[right]); // Swap negative element on left side and positive element on right side
                left++;
                right--;
            }
            else
            {
                if (arr[left] >= 0)
                {
                    left++; // Move left pointer if element at left is positive
                }
                if (arr[right] < 0)
                {
                    right--; // Move right pointer if element at right is negative
                }
            }
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
        cin >> arr[i]; // Input array elements
    }

    Solution obj;
    obj.segregateElements(arr, n); // Segregate positive and negative elements

    // Output the segregated array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// Time Complexity (TC): O(N) - Where N is the size of the array. The function iterates through the array once to segregate elements based on their sign.
// Space Complexity (SC): O(1) - Constant space complexity. The function uses a fixed amount of extra space regardless of the input size.
