#include<bits/stdc++.h>
using namespace std;
void Bfs(vector<int>adj[], int s, bool isvisited[]){
 queue<int>q;
 isvisited[s] = true;
 q.push(s);
 while(q.empty() == false){
     int u = q.front();
     q.pop();
     cout << u << " ";
     for(int x : adj[u]){
         if(isvisited[u] == false){
             isvisited[u] = true;
             q.push(u);
         }
     }
 }

}
void BFSDis(vector<int>adj[] , int v){
    bool isvisited[v];
    for(int i = 0; i < v; i++){
        isvisited[i] = false;
    }
    for(int i = 0; i < v; i++){
        if(isvisited[i] == false){
            Bfs(adj, i , isvisited);
        }
    }
}
void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    int v = 7;
    vector<int>adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    addEdge(adj,4,5);
    addEdge(adj,4,6);
    BFSDis(adj,v);
    

}