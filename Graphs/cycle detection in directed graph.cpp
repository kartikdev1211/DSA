#include<bits/stdc++.h>
using namespace std;
bool checkCycle(int node,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited,unordered_map<int,list<int>>&adj){
    visited[node]=1;
    dfsVisited[node]=1;
    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            bool cycleDetected=checkCycle(neighbour,visited,dfsVisited,adj);
            if(cycleDetected){
                return true;
            }else if(dfsVisited[neighbour]){
                return true;
            }
        }
    }
    dfsVisited[node]=0;
    return false;
}
int detectCycleInDirectedGraph(int n,vector<pair<int,int>>&edges){
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
    }
    unordered_map<int,bool>visited;
    unordered_map<int,bool>dfsVisited;
    for(int i=0;i<=n;i++){
        if(!visited[i]){
            bool cycleFound=checkCycle(i,visited,dfsVisited,adj);
            if(cycleFound){
                return true;
            }
        }
    }
    return false;
}