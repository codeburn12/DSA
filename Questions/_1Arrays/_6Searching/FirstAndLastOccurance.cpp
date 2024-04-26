#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        // Geting index of first occurrence of target
        int start = 0, end = nums.size() - 1, firstIndex = -1, lastIndex = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                firstIndex = mid;
                end = mid - 1; // Search space shortened to get minimum index
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        // Geting index of last occurrence of target
        start = 0;
        end = nums.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                lastIndex = mid;
                start = mid + 1; // Search space shortened to get maximum index
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return {firstIndex, lastIndex};
    }
};

int main()
{
    vector<int> nums;
    int n, target;
    cin >> n; // Input size of the array
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num; // Input elements of the array
        nums.push_back(num);
    }
    cin >> target; // Input the target value

    Solution obj;
    vector<int> result = obj.searchRange(nums, target);

    cout << "Output: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
// Time Complexity : The time complexity of each binary search is O(log n), where n is the size of the input array.Since we perform two binary searches independently, the overall time complexity remains O(log n).
// Space Complexity: The space complexity of the code is O(1) because no additional space is used that depends on the size of the input array or target element.
