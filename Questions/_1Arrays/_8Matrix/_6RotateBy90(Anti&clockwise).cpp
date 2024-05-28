#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>> &matrix, int n)
    {
        // Step 1: Reverse each row of the matrix.
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }

        // Step 2: Take the transpose of the matrix.
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    // Function to rotate matrix clockwise by 90 degrees.
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        // Step 1: Take the transpose of the matrix.
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row of the matrix.
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main()
{
    int n;
    cin >> n; // Size of the matrix
    vector<vector<int>> matrix(n, vector<int>(n));

    // Input matrix elements
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    Solution sol;

    // Rotate anticlockwise by 90 degrees
    sol.rotateby90(matrix, n);
    cout << "Matrix rotated anticlockwise by 90 degrees:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Reset the matrix for clockwise rotation
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Rotate clockwise by 90 degrees
    sol.rotate(matrix);
    cout << "Matrix rotated clockwise by 90 degrees:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Time Complexity:
Both functions, `rotateby90` and `rotate`, involve two main steps. Each step has a time complexity of O(n^2), where n is the size of the matrix. Therefore, the overall time complexity for both functions is O(n^2).

Space Complexity:
The space complexity for both functions is O(1) as we are performing the operations in-place and not using any extra space proportional to the input size.
*/
