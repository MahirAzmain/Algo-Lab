
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int totalnode, node1, node2, weight;
vector<vector<pair<int, int>>> Adjlist;
vector<int> visited;
priority_queue<pair<int, pair<int, int>>> pq;

void addedge(vector<vector<pair<int, int>>>& Adjlist, int node1, int node2, int weight) {
    Adjlist[node1].push_back({node2, weight});
    Adjlist[node2].push_back({node1, weight}); // Add this line for an undirected graph
}

int process(vector<vector<pair<int, int>>>& Adjlist, int vtx) {
    visited[vtx] = 1;
    for (int j = 0; j < Adjlist[vtx].size(); j++) {
        pair<int, int> v = Adjlist[vtx][j];
        if (!visited[v.first]) {
            pq.push(make_pair(-v.second, make_pair(-v.first, -vtx)));
        }
    }
    return 0;
}

int main() {
    int edge;

    cin >> totalnode >> edge;
    Adjlist.resize(totalnode); // Resize the adjacency list here

    int a, b, k;
    for (int i = 0; i < edge; i++) {
        cin >> a >> b >> k;
        addedge(Adjlist, a, b, k);
    }

    visited.assign(totalnode, 0);
    int source;
    cout << "enter source node:";
    cin >> source;
    process(Adjlist, source);
    int mst_cost = 0;
    while (!pq.empty()) {
        pair<int, pair<int, int>> frnt = pq.top();
        pq.pop();
        int v, w, u;

        static_cast<void>(v = -frnt.second.first), static_cast<void>(w = -frnt.first), u = -frnt.second.second;
        if (!visited[v]) {
            mst_cost += w;
            cout << u << "->" << v << "(" << w << ")->";
            process(Adjlist, v);
        }
        cout << endl;
    }

    cout << "mst cost: " << mst_cost << endl;
    return 0;
}
