#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int>adj[],int v, int s){
    bool isVisited[v];
    for(int i = 0; i < v; i++ ){
        isVisited[i] = false;
    }
    queue<int> q;
    isVisited[s] = true;
    q.push(s);
    while(q.empty() == false){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int x : adj[u]){
            if(isVisited[x] == false){
                isVisited[x] = true;
                q.push(x);
            }
        }
    }

}
void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    int v = 5;
    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    addEdge(adj,2,4);
    addEdge(adj,3,4);
    bfs(adj,v,0);
}