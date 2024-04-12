#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to partition the array around the range [a, b] into three parts.
    void threeWayPartition(vector<int> &array, int a, int b)
    {
        int low = 0, mid = 0, high = array.size() - 1;
        while (mid <= high)
        {
            if (array[mid] < a)
            {
                swap(array[low], array[mid]);
                low++;
                mid++;
            }
            else if (array[mid] >= a && array[mid] <= b)
            {
                mid++;
            }
            else
            {
                swap(array[mid], array[high]);
                high--;
            }
        }
        return;
    }
};

int main()
{
    int n;
    cin >> n; // Input the size of the array

    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i]; // Input array elements
    }

    int a, b;
    cin >> a >> b; // Input the range [a, b]

    Solution obj;
    obj.threeWayPartition(array, a, b); // Perform three-way partitioning

    // Output the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}

// Time Complexity (TC): O(n) - Linear time complexity as the function iterates through each element of the array exactly once.
// Space Complexity (SC): O(1) - Constant space complexity as the function uses a fixed number of integer variables regardless of input size.
