#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat)
    {
        // Create a 1D vector to store all elements of the matrix
        vector<int> vec;

        // Traverse the matrix and push each element into the 1D vector
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                vec.push_back(Mat[i][j]);
            }
        }

        // Sort the 1D vector in ascending order
        sort(vec.begin(), vec.end());

        // Initialize a counter for the sorted vector
        int k = 0;

        // Update the matrix with the sorted values from the vector
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                Mat[i][j] = vec[k++];
            }
        }

        // Return the sorted matrix
        return Mat;
    }
};

// Time Complexity: O(N^2 log(N)) for sorting N^2 elements
// Space Complexity: O(N^2) for the input matrix and the 1D vector
