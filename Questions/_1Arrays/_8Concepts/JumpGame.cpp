#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minJumps(int nums[], int n)
    {
        // Initialize variables to track the farthest point we can reach, the current point, and the number of jumps
        int farthest = 0, current = 0, jump = 0;

        // Iterate through the array until the second last element
        for (int i = 0; i < n - 1; i++)
        {
            // Update the farthest point we can reach from the current index
            farthest = max(farthest, nums[i] + i);

            // If we have reached the end of the current jump
            if (i == current)
            {
                // Increment the number of jumps
                jump++;
                // Move the current point to the farthest point we can reach
                current = farthest;
            }

            // If at any point we can't move forward, return -1
            if (i >= farthest)
            {
                return -1; // It is not possible to move forward anymore
            }
        }

        // Return the number of jumps needed to reach the end
        return jump;
    }
};

int main()
{
    int n;
    cin >> n; // Read the number of elements in the array

    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i]; // Read each element of the array
    }

    Solution sol;
    int minJumps = sol.minJumps(nums, n); // Calculate the minimum number of jumps needed

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
- The algorithm iterates through the array once, making it linear in time complexity.

Space Complexity (SC): O(1)
- The algorithm uses a constant amount of extra space regardless of the input size.
*/
