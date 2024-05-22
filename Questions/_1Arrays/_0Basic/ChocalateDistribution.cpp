#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;

class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        sort(a.begin(), a.end()); // Sorting the array (time complexity: O(n log n))

        long long start = 0, end = m - 1, ans = INT_MAX; // Initialize pointers and answer variable

        // Sliding window approach to find the minimum difference
        while (end < n)
        {
            long long diff = a[end] - a[start]; // Calculate the difference
            ans = min(ans, diff);               // Update the minimum difference
            start++;                            // Move the window
            end++;
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    vector<long long> a;
    long long n, m, temp;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }

    cin >> m;

    long long result = obj.findMinDiff(a, n, m);
    cout << result << endl;

    return 0;
}
// time complexity: Sorting the array takes O(n log n) time, where n is the size of the array. The while loop runs in O(n) time because it iterates through the array once. Overall, the time complexity is O(n log n) due to the sorting operation dominating the time complexity.

// space complexity : The space complexity is O(n) because we store the input array of size n.Other variables and data structures used have constant space requirements.