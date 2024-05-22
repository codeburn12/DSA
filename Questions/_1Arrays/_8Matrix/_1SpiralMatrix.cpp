#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<int> spiral(vector<vector<int>> &ans)
    {
        vector<int> vec;
        int row = 0, rowSize = ans.size() - 1;
        int col = 0, colSize = ans[0].size() - 1;
        while (row <= rowSize && col <= colSize)
        {
            // Getting first row element each time
            for (int i = col; i <= colSize; i++)
            {
                vec.push_back(ans[row][i]);
            }
            row++;

            // Getting last column element each time
            for (int i = row; i <= rowSize; i++)
            {
                vec.push_back(ans[i][colSize]);
            }
            colSize--;

            if (row <= rowSize)
            {
                for (int i = colSize; i >= col; i--)
                {
                    vec.push_back(ans[rowSize][i]);
                }
                rowSize--;
            }

            if (col <= colSize)
            {
                for (int i = rowSize; i >= row; i--)
                {
                    vec.push_back(ans[i][col]);
                }
                col++;
            }
        }
        return vec;
    }
};

int main()
{
    Solution s;
    int row, col, num;
    cin >> row >> col;
    vector<vector<int>> vec;
    // vector<vector<int>> vec(row, vector<int>(col)); // for vec[i][j]


    for (int i = 0; i < row; i++)
    {
        vector<int> ele;
        for (int j = 0; j < col; j++)
        {
            cin >> num;
            ele.push_back(num);
            // vec[i][j] = num;
        }
        vec.push_back(ele);
    }

    vector<int> ans = s.spiral(vec);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}

// time complexity is O(min(m, n)^2) and the space complexity is O(m * n) for the given code, where m is the number of rows and n is the number of columns in the input 2D vector.