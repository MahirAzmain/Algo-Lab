//
//  main.cpp
//  TSP for dp and minimum city
//
//  Created by Mahir Azmain Haque on 16/10/23.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

const int INF = 1e9;

int tsp(int mask, int pos, std::vector<std::vector<int>>& graph, std::vector<std::vector<int>>& dp) {
    int n = graph.size();

    if (mask == (1 << n) - 1) {
        return graph[pos][0];
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;
    for (int next = 0; next < n; ++next) {
        if ((mask & (1 << next)) == 0 && graph[pos][next] > 0) {
            int new_mask = mask | (1 << next);
            ans = std::min(ans, graph[pos][next] + tsp(new_mask, next, graph, dp));
        }
    }

    dp[mask][pos] = ans;
    return ans;
}

int main() {
    int n = 6;
   std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));
   // Input edges and weights
    int edges[][3] = {
        {1, 2, 2},
        {1, 3, 4},
        {2, 4, 3},
        {4, 5, 2},
        {4, 6, 3},
        {4, 3, 1},
        {3, 6, 5},
        {5, 6, 4},
        {5, 2, 3},
        {4, 1, 4}
    };

    int numEdges = sizeof(edges) / sizeof(edges[0]);

    for (int i = 0; i < numEdges; i++) {
        int node1 = edges[i][0];
        int node2 = edges[i][1];
        int weight = edges[i][2];

        // Assuming 1-based indexing for nodes, if 0-based, you'd use (node1 - 1) and (node2 - 1)
        graph[node1 - 1][node2 - 1] = weight;
        graph[node2 - 1][node1 - 1] = weight;  // Assuming an undirected graph
    }

    // Print the adjacency matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << graph[i][j] << " ";
            }
            std::cout << std::endl;
        }
    std::vector<std::vector<int>> dp(1 << n, std::vector<int>(n, -1));

    int mask = 1;
    int start = 0;

    int minCost = tsp(mask, start, graph, dp);

    std::cout << "Minimum cost for TSP: " << minCost << std::endl;

    return 0;
}




/*
 1 2 2
 1 3 4
 2 4 3
 4 5 2
 4 6 3
 4 3 1
 3 6 5
 5 6 4
 5 2 3
 4 1 4
 */
