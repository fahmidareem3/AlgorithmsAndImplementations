//31
//31
#include<bits/stdc++.h>
using namespace std;
#define White 0
#define Gray 1
#define Black 2
int DFSCycle(vector<int>adj[],vector<int>&color,int s,int parent){
   color[s] = Gray;
   for(int x : adj[s]){
       if(color[x] == White){
           if(DFSCycle(adj,color,x,s)) return true;
           //else if(x != parent) return true;
       }
        else if(x != parent) return true;
   }
   color[s] = Black;
   return false;
}
void addEdge(vector<int>adj[],int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int Dfsundirectedcycle(vector<int>adj[],int v){
    vector<int>color(v,White);
    for(int i = 0; i < v; i++){
        if(color[i] == White){
            if(DFSCycle(adj,color,i,-1))return true;
        }
    }
    return false;
}
int main(){
    int v,e;
    cin >> v >> e;
    vector<int>adj[v];
    for(int i = 0; i < e; i++){
        int x,y;
        cin >> x >> y;
        addEdge(adj,x,y);
    }
    if(Dfsundirectedcycle(adj,v)) cout<<"Yes\n";
    else cout<<"No\n";
}