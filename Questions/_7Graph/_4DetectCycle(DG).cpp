#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // Initialize a vector to store the indegree of each vertex
        vector<int> indegree(V, 0);

        // Calculate the indegree of each vertex
        for (int node = 0; node < V; node++)
        {
            for (auto currentNode : adj[node])
            {
                indegree[currentNode]++;
            }
        }

        // Create a queue to store vertices with indegree 0
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Process vertices with indegree 0 and reduce the indegree of their neighbors
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto currentNode : adj[node])
            {
                if (--indegree[currentNode] == 0)
                {
                    q.push(currentNode);
                }
            }
        }

        // Check if there is any vertex with non-zero indegree
        int sum = 0;
        for (int i = 0; i < V; i++)
        {
            sum += indegree[i];
        }

        // If sum is not 0, there is a cycle
        return sum != 0;
    }
};

int main()
{
    // Input the number of vertices
    int V;
    cin >> V;

    // Input the adjacency list
    vector<int> adj[V];
    for (int i = 0; i < V; i++)
    {
        int num_neighbors;
        cin >> num_neighbors;
        for (int j = 0; j < num_neighbors; j++)
        {
            int neighbor;
            cin >> neighbor;
            adj[i].push_back(neighbor);
        }
    }

    // Create an instance of the Solution class and call the isCyclic function
    Solution sol;
    bool hasCycle = sol.isCyclic(V, adj);

    // Output the result
    cout << (hasCycle ? "Graph contains a cycle" : "Graph doesn't contain a cycle") << endl;

    return 0;
}

/*
Time Complexity: O(V + E)
- V is the number of vertices and E is the number of edges.
- Calculating indegree takes O(E) time.
- Processing each vertex and edge in the queue takes O(V + E) time.

Space Complexity: O(V)
- The indegree vector and queue both require O(V) space.
*/
