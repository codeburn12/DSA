#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();   // Get the size of the input vector
        vector<int> ans(n, 1); // Initialize the answer vector with 1's of size n

        int curr = 1;
        // First pass: calculate the prefix product for each element
        for (int i = 0; i < n; i++)
        {
            ans[i] = curr;   // Assign the current prefix product to ans[i]
            curr *= nums[i]; // Update the current prefix product
        }

        curr = 1;
        // Second pass: calculate the suffix product for each element and multiply with the current value in ans
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] *= curr;  // Multiply the current suffix product to ans[i]
            curr *= nums[i]; // Update the current suffix product
        }

        return ans; // Return the result vector
    }
};

int main()
{
    int n;
    cin >> n; // Input the size of the vector

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // Input the elements of the vector
    }

    Solution sol;
    vector<int> result = sol.productExceptSelf(nums);

    for (int x : result)
    {
        cout << x << " "; // Output the result vector
    }

    return 0;
}

/*
Time Complexity: O(n)
- We traverse the array twice, once for the prefix product and once for the suffix product.
- Thus, the time complexity is O(n).

Space Complexity: O(1) (excluding the output array)
- The space complexity is O(1) because we use only a constant amount of extra space for variables `curr`.
- The space used for the output array `ans` is not considered extra space as it is required by the problem statement.
*/
