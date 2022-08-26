#include<bits/stdc++.h>
using namespace std;
void DFS(vector<int>adj[],vector<bool>&isvisited,vector<int>&compnum,int count,int s){
    isvisited[s] = true;
    compnum[s] = count;
    for(int x : adj[s]){
        if(isvisited[x] == false){
            DFS(adj,isvisited,compnum,count,x);
        }
    }
}
void DFSComp(vector<int>adj[], int v){
    vector<bool>isvisited(v,false);
    vector<int>compnum(v,0);
    int count = 0;
    for(int i = 0; i < v; i++){
       
       if(isvisited[i] == false){
           count++;
           DFS(adj,isvisited,compnum,count,i);
       }
    }
    for(int i = 0; i < v; i++){
        printf("%d: %d\n",i,compnum[i]);
    }
}
void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    int v,e;
    cin >> v >> e;
    vector<int>adj[v];
    for(int i = 0; i < e; i++){
        int p,q;
        cin >> p >> q;
        addEdge(adj,p,q);
    }
    DFSComp(adj,v);
}