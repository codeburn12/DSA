#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

class Solution
{
public:
    // Function to find the shortest distance of all the vertices from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Initialize the distance vector with infinity.
        vector<int> dist(V, INT_MAX);
        // Min-heap to store (distance, vertex) pairs.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        // Distance to the source is 0.
        dist[S] = 0;
        // Push the source vertex into the heap.
        q.push({0, S});

        // While the heap is not empty.
        while (!q.empty())
        {
            // Get the vertex with the smallest distance.
            int distTill = q.top().first;
            int node = q.top().second;
            q.pop();

            // Iterate through all adjacent vertices.
            for (auto currentNode : adj[node])
            {
                // If a shorter path to the current node is found.
                if (distTill + currentNode[1] < dist[currentNode[0]])
                {
                    // Update the distance.
                    dist[currentNode[0]] = distTill + currentNode[1];
                    // Push the updated distance and vertex into the heap.
                    q.push({dist[currentNode[0]], currentNode[0]});
                }
            }
        }
        // Return the computed shortest distances.
        return dist;
    }
};

int main()
{
    int V, E, S;
    cin >> V >> E >> S;

    vector<vector<int>> adj[V];
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // For undirected graph. Remove this line for directed graph.
    }

    Solution sol;
    vector<int> distances = sol.dijkstra(V, adj, S);

    for (int i = 0; i < V; ++i)
    {
        cout << distances[i] << " ";
    }

    return 0;
}

/*
Time Complexity:
- The priority queue operations (insertion and extraction) take O(log V) time.
- Each vertex is processed once, and each edge is processed once.
- Therefore, the overall time complexity is O((V + E) log V), where V is the number of vertices and E is the number of edges.

Space Complexity:
- The space complexity is O(V + E) for the adjacency list representation of the graph.
- The priority queue can hold at most V vertices, so the space complexity for the priority queue is O(V).
- Thus, the overall space complexity is O(V + E).
*/
