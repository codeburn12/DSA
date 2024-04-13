#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 return a[0] < b[0];
             });
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= ans.back()[1])
            {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    Solution sol;
    vector<vector<int>> mergedIntervals = sol.merge(intervals);
    for (const auto &interval : mergedIntervals)
    {
        cout << interval[0] << " " << interval[1] << endl;
    }

    return 0;
}

/*
Time Complexity (TC): O(n log n) due to sorting
Space Complexity (SC): O(n) for storing the merged intervals
*/
