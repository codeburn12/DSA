#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // Initialize indegree vector to store the indegree of each vertex
        vector<int> indegree(V, 0);
        // Initialize ans vector to store the topological order
        vector<int> ans;

        // Calculate the indegree of each vertex
        for (int node = 0; node < V; node++)
        {
            for (auto currentNode : adj[node])
            {
                indegree[currentNode]++;
            }
        }

        // Initialize a queue to store vertices with 0 indegree
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Process the vertices in the queue
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            // Decrease the indegree of adjacent vertices and
            // push them to the queue if their indegree becomes 0
            for (auto currentNode : adj[node])
            {
                if (--indegree[currentNode] == 0)
                {
                    q.push(currentNode);
                }
            }
        }

        // Return the topological order
        return ans;
    }
};

int main()
{
    int V, E;
    cin >> V >> E; // Input number of vertices and edges
    vector<int> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v; // Input each edge (u -> v)
        adj[u].push_back(v);
    }

    Solution sol;
    vector<int> topoOrder = sol.topoSort(V, adj);

    for (int i : topoOrder)
    {
        cout << i << " "; // Output the topological order
    }

    return 0;
}

/*
Time Complexity: O(V + E)
- Calculating the indegree of each vertex takes O(E) time.
- Pushing and popping vertices from the queue takes O(V) time.
- Traversing the adjacency list takes O(E) time.

Space Complexity: O(V + E)
- Storing the graph in an adjacency list takes O(V + E) space.
- Storing the indegree vector takes O(V) space.
- The queue can take up to O(V) space.
*/
