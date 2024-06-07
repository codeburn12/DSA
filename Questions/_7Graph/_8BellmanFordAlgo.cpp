#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        // Initialize distance vector with a large value (infinity)
        vector<int> dist(V, 1e8);
        // Set the distance to the source vertex as 0
        dist[S] = 0;

        // Relax all edges (V-1) times
        for (int i = 0; i < V - 1; i++)
        {
            for (auto e : edges)
            {
                int u = e[0], v = e[1], currentDist = e[2];
                // If the current distance to u is not infinity and
                // the new calculated distance is smaller, update it
                if (dist[u] != 1e8 && dist[u] + currentDist < dist[v])
                {
                    dist[v] = dist[u] + currentDist;
                }
            }
        }

        // Check for negative-weight cycles
        for (auto e : edges)
        {
            int u = e[0], v = e[1], currentDist = e[2];
            // If we can still relax an edge, then there is a negative cycle
            if (dist[u] != 1e8 && dist[u] + currentDist < dist[v])
            {
                return {-1}; // Return -1 indicating a negative cycle
            }
        }

        // Return the distance array
        return dist;
    }
};

int main()
{
    int V, E, S;
    cin >> V >> E >> S;

    vector<vector<int>> edges(E, vector<int>(3));
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    Solution sol;
    vector<int> result = sol.bellman_ford(V, edges, S);

    for (int dist : result)
    {
        cout << dist << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:
- The time complexity of the Bellman-Ford algorithm is O(V * E), where V is the number of vertices and E is the number of edges.
  This is because we relax all the edges (V-1) times, and each relaxation takes O(1) time.

Space Complexity:
- The space complexity is O(V) for storing the distance array.
*/
