#include<bits/stdc++.h>
using namespace std;
void BFSshortestpath(vector<int>adj[],vector<bool>&isvisited,vector<int>&distance,int s){
    isvisited[s] = true;
    queue<int>q;
    q.push(s);
    while(q.empty() == false){
        int u = q.front();
        q.pop();
        for(int x : adj[u]){
            if(isvisited[x] == false){
                isvisited[x] = true;
                q.push(x);
                distance[x] = distance[u] + 1;
            }
        }
    }


}
void BfsComponent(vector<int>adj[], int v){
    vector<bool>isvisited(v,false);
    vector<int>distance(v,0);
    int count = 0;
    for(int i = 0; i < v; i++){
       count++;
       if(count > 1) break;
       if(isvisited[i] == false){
           BFSshortestpath(adj,isvisited,distance,i);
       }
    }
    for(int i = 0; i < v; i++){
        if(i != 0 && distance[i] == 0) printf("%d: Not Reachable\n",i);
        else printf("%d: %d\n",i,distance[i]);
        
    }
}
void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    //adj[v].push_back(u);
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
    BfsComponent(adj,v);
}