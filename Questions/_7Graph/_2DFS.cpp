#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Initialize a vector to store the DFS traversal result
        vector<int> ans;
        // Initialize a vector to keep track of visited nodes
        vector<bool> vis(V, false);
        // Perform DFS for each node to ensure all components are covered
        for (int node = 0; node < V; node++)
        {
            if (!vis[node])
            {
                // Call the recursive DFS function if the node is not visited
                dfs(node, ans, adj, vis);
            }
        }
        return ans;
    }

private:
    // Recursive function to perform DFS
    void dfs(int node, vector<int> &ans, vector<int> adj[], vector<bool> &vis)
    {
        // Mark the current node as visited
        vis[node] = true;
        // Add the current node to the DFS result
        ans.push_back(node);
        // Recur for all the vertices adjacent to this vertex
        for (auto currentNode : adj[node])
        {
            if (!vis[currentNode])
            {
                // Call DFS for the unvisited adjacent node
                dfs(currentNode, ans, adj, vis);
            }
        }
    }
};

int main()
{
    int V, E;
    cin >> V >> E;      // Input the number of vertices and edges
    vector<int> adj[V]; // Adjacency list to store the graph
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;       // Input each edge
        adj[u].push_back(v); // Add edge u -> v
        adj[v].push_back(u); // Add edge v -> u (remove this line if the graph is directed)
    }

    Solution obj;
    vector<int> result = obj.dfsOfGraph(V, adj);
    for (int i : result)
    {
        cout << i << " "; // Output the DFS traversal
    }
    cout << endl;
    return 0;
}

/*
Time Complexity:
- The time complexity of the DFS traversal is O(V + E), where V is the number of vertices and E is the number of edges. This is because we visit every vertex and explore every edge once.

Space Complexity:
- The space complexity is O(V) due to the space required for the 'vis' vector to keep track of visited nodes and the recursion stack in the worst case.

*/
