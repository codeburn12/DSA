#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;

        // Iterate through all possible bitmasks representing subsets
        for (int i = 0; i < (1 << nums.size()); i++)
        {
            vector<int> ans;

            // Check each bit of the current bitmask
            for (int j = 0; j < nums.size(); j++)
            {
                // If j-th bit of the bitmask is set, include nums[j] in the subset
                if (i & (1 << j))
                {
                    ans.push_back(nums[j]);
                }
            }

            // Add the current subset to the result
            res.push_back(ans);
        }

        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> nums;

    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter " << n << " elements separated by spaces: ";
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    vector<vector<int>> subsets = solution.subsets(nums);

    // Print all subsets
    for (const auto &subset : subsets)
    {
        cout << "[";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
/*
Time Complexity: The time complexity of this solution is𝑂(2^𝑁*𝑁) where is the number of elements in the input vector nums. This is because there are
2^𝑁 possible subsets, and for each subset, we perform 𝑂(𝑁) operations to construct it.

Space Complexity: The space complexity of this solution is also 𝑂(2^𝑁*𝑁)
*/