#include<bits/stdc++.h>
using namespace std;
#define white 0
#define gray 1
#define black 2
void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
}
bool DFSCYCLE(vector<int>adj[], int s,int visited[], int v){
    visited[s] = gray;
    for(int x: adj[s]){
      if(visited[x] == white){
          if(DFSCYCLE(adj,x,visited,v)) return true;
      }
      else if(visited[x] == gray) return true;
    }
    visited[s] = black;
    return false;
}
bool DFS(vector<int>adj[],int v){
    int visited[v+1];
    for(int i = 1; i <= v; i++){
        visited[i] = white;
    }
    for(int i = 1; i <= v; i++){
        if(visited[i] == white){
            if(DFSCYCLE(adj,i,visited,v)) return true;
        }
    }
    return false;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int>adj[n+1];
    for(int i = 1; i <= m; i++){
        int a,b; 
        cin >> a>> b; 
        addEdge(adj,a,b);
    }
    if(DFS(adj,n)) cout<<"YES\n";
    else cout<<"No\n";
}