#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // Get the number of rows and columns in the matrix
        int m = matrix.size();
        int n = matrix[0].size();

        // Initialize start and end for binary search
        int start = 0;
        int end = m * n - 1;

        // Binary search
        while (start <= end)
        {
            // Calculate the middle index
            int mid = start + (end - start) / 2;
            // Convert the middle index to row and column indices
            int row = mid / n;
            int col = mid % n;

            // Check if the middle element is the target
            if (matrix[row][col] == target)
            {
                return true;
            }
            // If the middle element is less than the target, move to the right half
            else if (matrix[row][col] < target)
            {
                start = mid + 1;
            }
            // If the middle element is greater than the target, move to the left half
            else
            {
                end = mid - 1;
            }
        }
        // Target not found
        return false;
    }
};

int main()
{
    // Input matrix dimensions and elements from the user
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    cout << "Enter matrix elements row-wise:" << endl;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    // Input target value from the user
    int target;
    cout << "Enter the target value: ";
    cin >> target;

    // Create an instance of the Solution class and search for the target in the matrix
    Solution sol;
    bool found = sol.searchMatrix(matrix, target);

    // Output the result
    if (found)
    {
        cout << "Target found in the matrix." << endl;
    }
    else
    {
        cout << "Target not found in the matrix." << endl;
    }

    return 0;
}

/*
Time complexity: O(log(m×n)), where m is the number of rows and n is the number of columns in the matrix. This is because we perform binary search on an array of size m×n.

Space complexity: O(1), as we use only a constant amount of extra space regardless of the input size.
*/