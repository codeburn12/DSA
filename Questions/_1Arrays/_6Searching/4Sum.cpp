#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // Sorting the input array

        // Loop through the array to find four elements summing up to the target
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; // Skip duplicate elements

            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue; // Skip duplicate elements

                int remain = target - nums[i] - nums[j];
                int left = j + 1, right = n - 1;

                while (left < right)
                {
                    int sum = nums[left] + nums[right];
                    if (sum == remain)
                    {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        // Skip duplicate elements
                        while (left < right && nums[left] == nums[left - 1])
                            left++;
                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                    else if (sum < remain)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums;
    int size, num, target;

    // Input size of the array and elements from the user
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> num;
        nums.push_back(num);
    }

    // Input target value from the user
    cin >> target;

    // Create an instance of the Solution class
    Solution obj;

    // Call the fourSum function and display the result
    vector<vector<int>> result = obj.fourSum(nums, target);
    for (auto vec : result)
    {
        cout << "[";
        for (int num : vec)
        {
            cout << num << ", ";
        }
        cout << "], ";
    }
    cout << endl;

    return 0;
}

// The time complexity is O(n^3) due to nested loops
// space complexity is O(n^2) as no extra space is used apart from the input and output arrays.