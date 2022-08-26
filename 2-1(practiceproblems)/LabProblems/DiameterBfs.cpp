#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void Bfsdistance(vector<bool>&visited, vector<int>&distance, int src,vector<int>adj[]){
    visited[src] = true;
    queue<int>q;
    q.push(src);
    while(q.empty() == false){
        int u = q.front();
        q.pop();
        for(auto it : adj[u]){
            if(visited[it] == false){
                visited[it] = true;
                q.push(it);
                distance[it] = distance[u] + 1;
            }
        }
    }
}
int BFSdiameter(vector<int>adj[], int v){
       vector<bool>visited(v,false);
        vector<int>distance(v,0);
        set<int>s;
    for(int i = 0; i < v; i++){
        visited.clear();
        for(int i = 0; i < v; i++){
            visited[i] = false;
        }
        for(int i = 0; i < v; i++){
            s.insert(distance[i]);
        }
        distance.clear();
        for(int i = 0; i < v; i++){
            distance[i] = 0;
        } 
        Bfsdistance(visited,distance,i,adj);
    }
    int count = 0;
    int val = 0;
    for(auto it : s){
        count++;
        if(count == s.size()){
            val = it;
        }
    }
    return val;
}
int main(){
    int n;
    cin >> n;
    vector<int>adj[n];
    int e = n-1;
    for(int i = 0; i < e; i++){
        int x,y;
        cin >> x >> y;
        addEdge(adj,x,y);
    }
   cout<< BFSdiameter(adj,n)<<"\n";
}