#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

class Solution
{
public:
    // Prims Algo Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // Vector to check if a node has been visited
        vector<bool> vis(V, false);

        // Min-heap (priority queue) to store {weight, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        // Start with node 0 with weight 0
        q.push({0, 0});
        int sum = 0; // Initialize sum of weights of MST

        while (!q.empty())
        {
            // Extract the node with the minimum weight
            int node = q.top().second;
            int wt = q.top().first;
            q.pop();

            // If the node is already visited, skip it
            if (vis[node])
                continue;

            // Mark the node as visited
            vis[node] = true;

            // Add the edge's weight to the sum
            sum += wt;

            // Traverse all adjacent nodes
            for (auto currentNode : adj[node])
            {
                // If the adjacent node is not visited, push it to the priority queue
                if (!vis[currentNode[0]])
                {
                    q.push({currentNode[1], currentNode[0]});
                }
            }
        }

        return sum; // Return the sum of weights of MST
    }

    // Kruskal Algo
};

int main()
{
    int V;
    cin >> V;
    vector<vector<int>> adj[V];
    for (int i = 0; i < V; ++i)
    {
        int u, v, w;
        while (cin >> u >> v >> w)
        {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // Assuming undirected graph
        }
    }

    Solution sol;
    cout << sol.spanningTree(V, adj) << endl;

    return 0;
}

/*
Time Complexity:
- The time complexity is O(E log V), where E is the number of edges and V is the number of vertices.
- This is because each edge is processed once and insertion/deletion operations on the priority queue take O(log V) time.

Space Complexity:
- The space complexity is O(V + E), where V is the number of vertices and E is the number of edges.
- O(V) for the visited array and the priority queue can store up to O(E) edges in the worst case.
*/
