#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = prices[0], maxi = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            int diff = prices[i] - mini;
            maxi = max(maxi, diff);
            mini = min(mini, prices[i]);
        }
        return maxi;
    }
};

int main()
{
    int n;
    cin >> n; // Input the size of the prices array

    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i]; // Input array elements (prices)
    }

    Solution solution;
    int result = solution.maxProfit(prices); // Call the maxProfit function

    return result; // Output the result without any statement
}
// TC (Time Complexity): The time complexity of this code is O(n), where n is the size of the prices array. This is because we traverse the array once to calculate the maximum profit.
// SC (Space Complexity): The space complexity is O(1) as we use only a constant amount of extra space for variables (mini, maxi, diff, i) regardless of the input size.