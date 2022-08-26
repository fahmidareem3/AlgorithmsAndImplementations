#include<bits/stdc++.h>
using namespace std;
#define white 0
#define gray 1
#define black 2
void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
bool cycleundirected(vector<int>adj[], int source, int visited[], int parent){
    visited[source] = gray;
    for(int x: adj[source]){
        if(visited[x] == white){
            if(cycleundirected(adj,x,visited,source)){
                return true;
            }
         }
       else if(x != parent) return true;
    }
    visited[source] = black;
    return false;
}
bool DFS(vector<int>adj[],int v){
    int visited[v+1];
    for(int i = 1; i <= v; i++){
        visited[i] = white;
    }
    for(int i = 1; i <= v; i++){
        if(visited[i] == white){
            if(cycleundirected(adj,i,visited,-1)) return true;
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