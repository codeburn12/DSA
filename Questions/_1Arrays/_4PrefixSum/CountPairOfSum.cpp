#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        unordered_map<int, int> um;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (um.find(k - arr[i]) != um.end())
            {
                ans += um[k - arr[i]];
            }
            um[arr[i]]++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    int result = sol.getPairsCount(arr, n, k);
    cout << result << endl;

    return 0;
}

// Time Complexity (tc): The time complexity of this algorithm remains O(n), where n is the size of the input array. This is because we still iterate through the array once to calculate the pairs count.
// Space Complexity(sc) : The space complexity also remains O(n) due to the unordered map um, which stores the frequency of elements encountered in the array.
