#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Create a visited array to keep track of visited nodes
        vector<bool> vis(V, false);
        // Loop through all nodes to handle disconnected graph components
        for (int node = 0; node < V; node++)
        {
            // If the node is not visited, start BFS traversal from that node
            if (!vis[node])
            {
                // If a cycle is detected, return true
                if (bfs(node, vis, adj))
                    return true;
            }
        }
        // If no cycle is detected in any component, return false
        return false;
    }

    bool bfs(int i, vector<bool> &vis, vector<int> adj[])
    {
        // Mark the current node as visited
        vis[i] = true;
        // Create a queue for BFS where each element is a pair of node and its parent
        queue<pair<int, int>> q;
        q.push({i, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            // Iterate through all adjacent nodes
            for (auto currentNode : adj[node])
            {
                // If the adjacent node is not visited, mark it visited and push to queue
                if (!vis[currentNode])
                {
                    vis[currentNode] = true;
                    q.push({currentNode, node});
                }
                // If the adjacent node is visited and not parent of current node, cycle detected
                else if (currentNode != parent)
                {
                    return true;
                }
            }
        }
        // No cycle detected from the current node
        return false;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;
    bool result = obj.isCycle(V, adj);
    cout << (result ? "Cycle detected" : "No cycle detected") << endl;

    return 0;
}

/*
Time Complexity:
- The time complexity is O(V + E), where V is the number of vertices and E is the number of edges. This is because each node and each edge is processed once in the BFS traversal.

Space Complexity:
- The space complexity is O(V), which is used for the visited array and the BFS queue.
*/
