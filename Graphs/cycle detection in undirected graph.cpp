#include<bits/stdc++.h>
using namespace std;
bool isCyclicBFS(int src,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj){
    unordered_map<int,int>parent;
    parent[src]=-1;
    visited[src]=1;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto neighbour:adj[front]){
            if(visited[neighbour]==1&&neighbour!=parent[front]){
                return true;
            }else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=1;
                parent[neighbour]=front;
            }
        }
    }
    return false;
}
bool isCyclicDFS(int node,int parent, unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj){
    visited[node]=true;
    for(auto i:adj[node]){
        if(!visited[i]){
            bool cycleDetected=isCyclicDFS(i,node,visited,adj);
            if(cycleDetected){
                return true;
            }
        }else if(i!=parent){
            return true;
        }
    }
    return false;
}
string cycleDetection(vector<vector<int>>&edges,int n,int m){
    // create adjList
    unordered_map<int,list<int>>adj;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[1][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int,bool>visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=isCyclicBFS(i,visited,adj);
            bool ans1=isCyclicDFS(i,-1,visited,adj);
            if(ans1==1){
                return "Yes";
            }
        }
    }
    return "No";
}