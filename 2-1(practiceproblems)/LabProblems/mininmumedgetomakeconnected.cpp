//31
//31
#include<bits/stdc++.h>
using namespace std;
void DFS(vector<int>adj[],int s,vector<bool>&isvisited){
    isvisited[s] = true;
    for(int x : adj[s]){
        if(isvisited[x] == false){
            DFS(adj,x,isvisited);
        }
    }

}
void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int componentcount(vector<int>adj[],int v){
    vector<bool>isvisited(v+1,false);
    int count = 0;
    for(int i = 1; i <= v; i++){
        if(isvisited[i] == false)
        {
            count++;
            DFS(adj,i,isvisited);
        }
    }
    
    return count;
}
int main(){
    int v,e;
    cin >> v >> e;
    vector<int>adj[v+1];
    for(int i = 0; i < e; i++){
        int x, y;
        cin >> x >> y;
        addEdge(adj,x,y);
    }
    int comp = componentcount(adj,v);
    cout<<comp - 1<<"\n";
}