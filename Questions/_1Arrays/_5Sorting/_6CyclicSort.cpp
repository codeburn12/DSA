#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr, int n)
    {
        int missing = 0, repeat = 0;

        // Putting each number at its correct place in the array(Cycle Sort)
        int i = 0;
        while (i < n)
        {
            if (arr[i] != arr[arr[i] - 1])
            {
                swap(arr[i], arr[arr[i] - 1]);
            }
            else
            {
                i++;
            }
        }

        // Finding the missing and repeated elements
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != i + 1)
            {
                repeat = arr[i];
                missing = i + 1;
            }
        }
        return {repeat, missing};
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution obj;
    vector<int> result = obj.findTwoElement(arr, n);

    cout << result[0] << "\n"
         << result[1] << endl;

    return 0;
}

// time complexity is O(n) because the array is traversed twice in separate loops.
// space complexity of this algorithm is O(1) because no extra space is used except for a few variables.