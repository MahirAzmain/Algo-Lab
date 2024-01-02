//
//  main.cpp
//  printNegativeCycleUsingFloydWarshall
//
//  Created by Mahir Azmain Haque on 3/10/23.
//

#include <iostream>
#include<climits>
#include <set>

using namespace std;

const int INF = 1e5;
const int N = 1e3;
int graph[N][N];
int pred[N][N];

void initializeGraph(){
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if(i==j)    graph[i][j]=0;
            else    graph[i][j] = INF;
        }
    }
}

void printNegativeCyclePath(int v){
    int d[N][N];
    for (int i = 0; i < v; ++i)
    {
        for (int j = 0; j < v; ++j)
        {
            d[i][j] = graph[i][j];
        }
    }

    for (int i = 0; i < v; ++i)
    {
        for (int j = 0; j < v; ++j)
        {
            for (int k = 0; k < v; ++k)
            {
                if(d[j][i]+d[i][k]<d[j][k]){
                    d[j][k] = d[j][i] + d[i][k];
                    pred[j][k] = pred[i][k];
                }
            }
        }
    }
    set<int> s;
    for (int i = 0; i < v; ++i)
    {
        if(d[i][i]<0){
            s.insert(i);
        }
    }

    for(int node : s){
        int curr = node;
        vector<int> cycle;
        while(true){
            cycle.push_back(curr);
            if(curr==node && cycle.size()>1){
                break;
            }
            curr = pred[node][curr];
        }
        reverse(cycle.begin(),cycle.end());
        for (int i = 0; i < cycle.size(); ++i)
        {
            cout<< cycle[i]<< " ";
        }
        cout<< endl;
    }

}

int main(){
    initializeGraph();
    int v,e;
    cin>>v>>e;
    for (int i = 0; i < e; ++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v] = w;
        
    }
    printNegativeCyclePath(v);

    return 0;
}
