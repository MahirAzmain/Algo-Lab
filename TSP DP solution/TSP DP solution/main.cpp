//
//  main.cpp
//  TSP DP solution
//
//  Created by Mahir Azmain Haque on 14/10/23.
//

#include <iostream>

using namespace std;

vector<vector<int>>dp;
vector<vector<int>>dist; // adjacent matrix.
int n; // Number of Nodes.
int call(int S,int i){
    //All the nodes have been visited exactly once.

    if(S==((1<<n)-1)){
        return dist[i][1];
    }

    // Subtree has been calculated.
    if(dp[S][i]!=-1) return dp[S][i];

    // Go to next unvisited node.
    int res = INT_MAX;
    for(int j=0;j<n;j++){
        if((S&(1<<j))==0){ // if j'th node is unvisited.
            res = min(res , dist[i][j]+call(S|(1<<j),j)); // mark j'th node as visited.
        }
    }
    return dp[S][i] = res;
}
int main(){
    cin>>n;
    dist.resize(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dist[i][j];
        }
    }
    dp.resize(1<<n,vector<int>(n,-1));
    cout<< call(1,1)<<endl;

}
/*
4
0 10 15 20
10 0 25 25
15 25 0 30
20 25 30 0
Output: 80
*/
