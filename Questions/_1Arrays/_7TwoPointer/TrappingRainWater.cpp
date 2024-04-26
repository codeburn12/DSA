#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int start = 0, end = height.size() - 1, leftMax = 0, rightMax = 0, ans = 0;

        // Logic:
        // We use two pointers, start and end, initialized at the beginning and end of the array.
        // We also maintain leftMax and rightMax to keep track of the maximum height encountered from left and right.
        // We move the pointers inward and calculate trapped water at each step.

        while (start < end)
        {
            if (height[start] <= height[end])
            {
                if (height[start] >= leftMax)
                {
                    leftMax = height[start];
                }
                else
                {
                    ans += leftMax - height[start];
                }
                start++;
            }
            else
            {
                if (height[end] >= rightMax)
                {
                    rightMax = height[end];
                }
                else
                {
                    ans += rightMax - height[end];
                }
                end--;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> height;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        height.push_back(element);
    }

    Solution obj;
    int trappedWater = obj.trap(height);
    cout << trappedWater << endl;

    return 0;
}

// Time Complexity: O(n), where n is the size of the input vector height
// Space Complexity: O(1), since only a constant amount of extra space is used