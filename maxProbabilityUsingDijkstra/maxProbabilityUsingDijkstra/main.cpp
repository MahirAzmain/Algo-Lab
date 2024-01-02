//
//  main.cpp
//  maxProbabilityUsingDijkstra
//
//  Created by Mahir Azmain Haque on 3/10/23.
//


// finding maximum probability
#include<iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e3;
vector<pair<int, long double>> g[N];

vector<long double> dijkstra(int s, int n) {
  priority_queue<pair<long double, int>>q;
  vector<long double> d(n + 1, 0);
  vector<bool> vis(n + 1, 0);
  q.push({1, s});
  d[s] = 1;
  while(!q.empty()) {
    auto x = q.top();
    q.pop();
    int u = x.second;
    if(vis[u]) continue;
    vis[u] = 1;
    for(auto y: g[u]) {
      int v = y.first;
      long double w = y.second;
      if(d[u]*w>d[v]){
        d[v]=d[u]*w;
        q.push({d[v],v});
      }
    }
  }
  return d;
}

int main(){
    int n,e;
    cin>>n>>e;
    while(e--){
        int v1,v2;
        cin>>v1>>v2;
        long double w;
        cin>>w;
        g[v1].push_back({v2,w});
        g[v2].push_back({v1,w});
    }
    int s;
    cin>>s;
    int t;
    cin>>t;
    vector<long double>distance = dijkstra(s,n);
    cout<< distance[t] << endl;
}
