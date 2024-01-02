//
//  main.cpp
//  printshortestpathfloydwarshall
//
//  Created by Mahir Azmain Haque on 3/10/23.
//
// it was given as a lab task
#include <iostream>

using namespace std;

const int INF = 1e5;
const int N = 1e2;
int graph[N][N];
int nex[N][N];

void initializeGraph(){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==j)    graph[i][j]=0;
            else graph[i][j]= INF;
        }
    }
}

void constructPath(int v){
    int d[v+1][v+1];
    for(int i=0; i<v+1; i++){
        for(int j=0; j<v+1; j++){
            d[i][j] = graph[i][j];
            nex[i][j] = j;
        }
    }

    for(int k=0; k<v+1; k++){
        for(int i=0; i<v+1; i++){
            for(int j=0; j<v+1; j++){
                if(d[i][k] + d[k][j]<d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    nex[i][j] = nex[i][k];
                }
            }
        }
    }
}

void findPath(int i, int j){
    vector<int>path;
    path.push_back(i);
    while(i!=j){
        i = nex[i][j];
        path.push_back(i);
    }
    cout<< "The path is: " << endl;
    for(int m=0; m<path.size(); m++){
        cout<< path[m] << " ";
    }
    cout<< endl;
}


int main()
{
    initializeGraph();
    int v,e;
    cin>>v>>e;
    for(int i=0; i<e; i++){
        int u1,v1,w;
        cin>>u1>>v1>>w;
        graph[u1][v1] = w;
    }
    constructPath(v);
    int s,d;
    cin>>s>>d;
    findPath(s,d);
}
