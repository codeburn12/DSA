#include <iostream>
#include <vector>
using namespace std;
// Define the Solution class
class Solution
{
public:
    // Define the rowAndMaximumOnes function
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        // Initialize a vector of size 2 to store the result
        vector<int> vec(2);
        // Initialize a variable temp to store the maximum count of ones found
        int temp = 0;

        // Iterate through each row of the matrix
        for (int i = 0; i < mat.size(); i++)
        {
            // Initialize a variable count to count the number of ones in the current row
            int count = 0;
            // Iterate through each element in the current row
            for (int j = 0; j < mat[0].size(); j++)
            {
                // If the element is 1, increment the count
                if (mat[i][j] == 1)
                {
                    count += 1;
                }
            }
            // If the count of ones in the current row is greater than the previous maximum (temp)
            if (temp < count)
            {
                // Update the result vector with the current row index and count of ones
                vec[0] = i;
                vec[1] = count;
                // Update temp with the new maximum count of ones
                temp = count;
            }
        }

        // Return the result vector
        return vec;
    }
};

// Time Complexity: O(m*n) where m is the number of rows and n is the number of columns in the input matrix
// Space Complexity: O(1) since the extra space used is constant regardless of the input size
