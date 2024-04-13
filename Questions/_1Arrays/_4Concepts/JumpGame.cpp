#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minJumps(int nums[], int n)
    {
        int farthest = 0, current = 0, jump = 0;
        for (int i = 0; i < n - 1; i++)
        {
            farthest = max(farthest, nums[i] + i);
            if (i == current)
            {
                jump++;
                current = farthest;
            }
            if (i >= farthest)
            {
                return -1; // If we can't move forward anymore, return -1
            }
        }
        return jump;
    }
};

int main()
{
    int n;
    cin >> n;

    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution sol;
    int minJumps = sol.minJumps(nums, n);

    if (minJumps == -1)
    {
        cout << "It is not possible to reach the end of the array." << endl;
    }
    else
    {
        cout << "Minimum number of jumps needed: " << minJumps << endl;
    }

    return 0;
}

/*
Time Complexity (TC): O(n)
Space Complexity (SC): O(1)
*/
