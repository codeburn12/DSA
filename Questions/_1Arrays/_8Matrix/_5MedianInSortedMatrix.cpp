#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to count the number of elements in a row less than or equal to 'mid'
    int cntN(vector<int> &row, int mid)
    {
        int low = 0, high = row.size() - 1;
        while (low <= high)
        {
            int md = low + (high - low) / 2;
            if (row[md] <= mid)
                low = md + 1;
            else
                high = md - 1;
        }
        return low; // Return the count of elements less than or equal to 'mid'
    }

    // Function to find the median of the given matrix
    int median(vector<vector<int>> &matrix, int R, int C)
    {
        int median = (R * C) / 2, low = 1, high = 2000;
        while (low <= high)
        {
            int cnt = 0;
            int mid = low + (high - low) / 2;
            // Count the number of elements less than or equal to 'mid' in each row
            for (int i = 0; i < R; i++)
            {
                cnt += cntN(matrix[i], mid);
            }
            // If the count is less than or equal to the desired median, update 'low'
            if (cnt <= median)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low; // Return the median value
    }
};

int main()
{
    int R, C;
    cin >> R >> C; // Input number of rows and columns

    vector<vector<int>> matrix(R, vector<int>(C)); // Create a matrix of size R x C

    // Input elements of the matrix
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> matrix[i][j];
        }
    }

    Solution obj;                          // Create an object of the Solution class
    int result = obj.median(matrix, R, C); // Calculate the median using the median function
    cout << "Median: " << result << endl;  // Output the median

    return 0;
}

/*
Time Complexity:
- The binary search in cntN function takes O(log(M)) time, where M is the number of elements in a row.
- The median function performs binary search in the range [1, 2000] which takes O(log(2000)) = O(1) time.
- Inside the while loop of median function, we iterate through all R rows, and in each iteration, we perform a binary search which takes O(log(M)) time.
- Thus, the overall time complexity is O(R * log(M)).

Space Complexity:
- The space complexity is O(R * C) to store the input matrix elements.
- The additional space used by variables and function calls is negligible compared to the input matrix.
- Hence, the overall space complexity is O(R * C).
*/
