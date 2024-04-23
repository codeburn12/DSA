#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rearrange(int arr[], int n)
    {
        vector<int> positive;
        vector<int> negative;
        int p = 0;
        int k = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= 0)
            {
                positive.push_back(arr[i]);
            }
            else
            {
                negative.push_back(arr[i]);
            }
        }

        int i = 0;
        while (p < positive.size() && k < negative.size())
        {
            if (i % 2 == 0)
            {
                arr[i] = positive[p];
                p++;
            }
            else
            {
                arr[i] = negative[k];
                k++;
            }
            i++;
        }

        while (p < positive.size())
        {
            arr[i] = positive[p];
            p++;
            i++;
        }

        while (k < negative.size())
        {
            arr[i] = negative[k];
            k++;
            i++;
        }

        return;
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

    Solution solution;
    solution.rearrange(arr, n);

    // Output the rearranged array without using a statement
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
// time complexity of O(N)
// space complexity is O(N)