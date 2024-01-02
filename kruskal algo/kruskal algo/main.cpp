//
//  main.cpp
//  kruskal algo
//
//  Created by Mahir Azmain Haque on 11/9/23.
//

#include <iostream>
#include<stdlib.h>
#include<vector>
#include<list>
#include<algorithm>

using namespace std;
const int N=10000;
int parent[N];
int size[N];

void make_set(int v){
    parent[v]=v;
   size[v] = 1;
}
int find_set(int v){
    if(parent[v]==v) return v;
    return parent[v]=find_set(parent[v]);
}
void union_set(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(size[a]<size[b]) swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }
}

struct edge{
    int u,v,wt;
    bool operator<(const edge e){
        return wt<e.wt;
    }
};

vector<pair<int,int>> A;
vector<edge> edgelist;
vector<edge> edgelistMod;
int cost;
void kruskal_algo(int n,int e){
    for(int i=0;i<n;i++) make_set(i);

    sort(edgelist.begin(),edgelist.end());

    for(auto e: edgelist){
        if(find_set(e.u)!=find_set(e.v)){
            cost+=e.wt;
            A.push_back(make_pair(e.u,e.v));
            union_set(e.u,e.v);
        }
    }
}

/*
void second_best_mst(int n,int e){
    for(int i=0;i<n;i++) make_set(i);

    sort(edgelist.begin(),edgelist.end());
    auto it=edgelistMod.begin();
    for(auto e: edgelist){
        if(find_set(e.u)!=find_set(e.v)){
            cost+=e.wt;
            A.push_back(make_pair(e.u,e.v));
            union_set(e.u,e.v);
        }
        it++;
    }
}*/


int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge e;
        e.u=u;
        e.v=v;
        e.wt=w;
        edgelist.push_back(e);
        edgelistMod.push_back(e);
    }
    kruskal_algo(n,e);
    for(auto val:edgelist){
        cout<<val.u<<" "<<val.v<<" "<<val.wt<<endl;
    }
    cout<<cost<<endl;
    for(auto val: A){
        cout<<"( "<<val.first<<", "<<val.second<<" )"<<endl;
    }
}
