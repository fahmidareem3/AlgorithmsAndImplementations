#include<bits/stdc++.h>
using namespace std;
void BFSrec(vector<int>adj[], int s, bool isvisited[],int v, int distance[]){
    isvisited[s] = true;
    queue<int>q;
    q.push(s);
   
  
    while(q.empty() == false){
        int u = q.front();
        q.pop();
        for(int x : adj[u]){
            if(isvisited[x] == false){
            isvisited[x] = true;
            distance[x] = distance[u] + 1;
            q.push(x);
            }
         }

    }
    
    
}
void Bfs(vector<int>adj[], int s, int v, int distance[]){
    bool isvisited[v];
    for(int i = 0; i < v; i++){
        isvisited[i] = false;
    }
    for(int i = 0; i < v; i++){
        if(isvisited[i] == false){
           BFSrec(adj, i , isvisited, v ,distance);
        }
    }
}
void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    int v = 4;
    vector<int>adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    int distance[v];
    for(int i = 0; i < v; i++){
        distance[i] = 0;
    }
    Bfs(adj,0,v , distance);
     for(int i = 0; i < v; i++){
        cout << distance[i] << " ";
    }
    
}