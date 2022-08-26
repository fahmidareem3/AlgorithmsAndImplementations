#include <bits/stdc++.h>
using namespace std;


void addEdge(vector<int>adj[],int a, int b){
    adj[a].push_back(b);
    adj[b].push_back(a);
}
int ans = 0;
int x;

void DFSUtil(vector<int>adj[],int count ,vector<bool>&visited,int src,int &maxCount ){
    
    visited[src]= true;
    count++;
    
    for(auto v : adj[src]){
       
        if(visited[v ] == false){
            if(count >= maxCount){
                maxCount = count;
                x = v;
            }
            DFSUtil(adj,count,visited,v,maxCount);
        }
         
    }
}
void DFS(vector<int>adj[],int src,int &maxCount ,int nodes){
    
    vector<bool> visited(nodes,false);
    int count = 0;
    DFSUtil(adj,count+1,visited,src,maxCount);
}
int diameter(vector<int>adj[],int nodes){
    int maxCount = INT_MIN;
    DFS(adj,0,maxCount,nodes);
    DFS(adj,x,maxCount,nodes);
    return maxCount;
}

int main(){

    int nodes; 
    cin >> nodes;

    vector<int>adj[nodes];
    
    int edges = nodes-1;
    while(edges--){
        int n1,n2;
        cin >> n1 >> n2;
        addEdge(adj,n1,n2);
    }
    ans = diameter(adj,nodes);
    cout<<ans -1 <<endl;
}