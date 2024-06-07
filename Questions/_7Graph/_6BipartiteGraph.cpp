#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    // Function to check if the given graph is bipartite
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();       // Number of nodes in the graph
        vector<int> colored(n, -1); // Vector to store the color of each node, initialized to -1 (uncolored)

        // Iterate through each node to handle disconnected components
        for (int i = 0; i < n; i++)
        {
            // If the node is uncolored, perform BFS from that node
            if (colored[i] == -1 && !bfs(i, 0, colored, graph))
            {
                return false; // If BFS finds a conflict, the graph is not bipartite
            }
        }
        return true; // If no conflicts are found, the graph is bipartite
    }

    // BFS function to color the graph and check for bipartiteness
    bool bfs(int node, int color, vector<int> &colored, vector<vector<int>> &graph)
    {
        queue<pair<int, int>> q; // Queue for BFS, stores pairs of (node, color)
        q.push({node, color});   // Start BFS from the given node with the given color
        colored[node] = color;   // Color the starting node

        // Perform BFS
        while (!q.empty())
        {
            int currentNode = q.front().first;   // Get the current node
            int currentColor = q.front().second; // Get the current color
            q.pop();

            // Iterate through adjacent nodes
            for (auto adjNode : graph[currentNode])
            {
                // If the adjacent node is uncolored, color it with the opposite color and add to queue
                if (colored[adjNode] == -1)
                {
                    colored[adjNode] = !currentColor;
                    q.push({adjNode, !currentColor});
                }
                // If the adjacent node is colored with the same color, graph is not bipartite
                else if (colored[adjNode] == currentColor)
                {
                    return false;
                }
            }
        }
        return true; // If no conflicts are found, the subgraph is bipartite
    }
};

int main()
{
    int n;
    cin >> n; // Number of nodes in the graph
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; ++i)
    {
        int m;
        cin >> m; // Number of edges for node i
        graph[i].resize(m);
        for (int j = 0; j < m; ++j)
        {
            cin >> graph[i][j]; // Input the adjacent nodes
        }
    }

    Solution sol;
    bool result = sol.isBipartite(graph);
    cout << (result ? "true" : "false") << endl; // Output the result
    return 0;
}

/*
Time Complexity:
The time complexity is O(V + E), where V is the number of vertices and E is the number of edges.
This is because each vertex and edge is processed at most once.

Space Complexity:
The space complexity is O(V), where V is the number of vertices.
This is for the color array and the queue used in BFS.
*/
