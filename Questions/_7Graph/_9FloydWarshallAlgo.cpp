#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &matrix)
    {
        int V = matrix.size(); // Number of vertices in the graph

        // Applying Floyd Warshall Algorithm
        // k is the intermediate vertex
        for (int k = 0; k < V; k++)
        {
            // i is the source vertex
            for (int i = 0; i < V; i++)
            {
                // j is the destination vertex
                for (int j = 0; j < V; j++)
                {
                    // If there is no direct path between i and j, set it to a large value
                    if (matrix[i][j] == -1)
                    {
                        matrix[i][j] = 1e8;
                    }
                    // Update the shortest distance between i and j using the intermediate vertex k
                    if (matrix[i][k] != 1e8 && matrix[k][j] != 1e8) // Ensure there is no overflow
                    { 
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }

        // Convert the large values back to -1 indicating no path
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (matrix[i][j] == 1e8)
                {
                    matrix[i][j] = -1;
                }
            }
        }

        return;
    }
};

// Main function to take input from user and execute the shortest_distance function
int main()
{
    int n;
    cin >> n; // Number of vertices
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j]; // Input the adjacency matrix
        }
    }

    Solution sol;
    sol.shortest_distance(matrix);

    // Output the modified adjacency matrix
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
The time complexity of the Floyd Warshall algorithm is O(V^3), where V is the number of vertices in the graph. This is because we have three nested loops, each running V times.

Space Complexity:
The space complexity of this algorithm is O(V^2), which is used for the adjacency matrix to store the distances between each pair of vertices.
*/
