#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Create a queue to help with BFS
        queue<int> q;
        // Vector to store the BFS traversal order
        vector<int> ans;
        // Vector to keep track of visited nodes
        vector<bool> vis(V, false);

        // Start BFS from node 0 (assuming 0 as the starting node)
        q.push(0);
        vis[0] = true;

        // Continue BFS until the queue is empty
        while (!q.empty())
        {
            // Get the front node from the queue
            int node = q.front();
            q.pop();

            // Add this node to the BFS traversal order
            ans.push_back(node);

            // Iterate over all the adjacent nodes
            for (auto currentNode : adj[node])
            {
                // If the adjacent node is not visited, mark it visited and push it into the queue
                if (!vis[currentNode])
                {
                    vis[currentNode] = true;
                    q.push(currentNode);
                }
            }
        }
        return ans;
    }
};

int main()
{
    // Take input from user
    int V, E;
    cin >> V >> E;

    // Create an adjacency list
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Uncomment this line for an undirected graph
    }

    Solution sol;
    vector<int> bfsTraversal = sol.bfsOfGraph(V, adj);

    // Print the BFS traversal
    for (int i = 0; i < bfsTraversal.size(); i++)
    {
        cout << bfsTraversal[i] << " ";
    }

    return 0;
}

/*
Time Complexity: O(V + E)
- V is the number of vertices, and E is the number of edges.
- Each vertex is visited once, and each edge is considered once.

Space Complexity: O(V)
- Space is required for the visited array, the queue, and the result vector.
*/
