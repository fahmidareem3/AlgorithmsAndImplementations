#include<bits/stdc++.h>
using namespace std;
void DfsRec(vector<int> adj[], int s , bool isvisted[]){
    isvisted[s] = true;
    //cout << s << " ";
    for(int x : adj[s]){
        if(isvisted[x] == false){
            isvisted[x] = true;
            DfsRec(adj,x,isvisted);
        }
    }
}
int DFS(vector<int>adj[], int s, int v){
    bool isvisited[v]; int count = 0;
    for(int i = 0; i < v; i++){
        isvisited[i] = false;
    }
    for(int i = 0; i < v; i++){
        if(isvisited[i] == false){
            DfsRec(adj, i , isvisited);
            count++;
        }
    }
    return count;
}
void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    int v;
    cin >> v;
    vector<int>adj[v];
  	addEdge(adj,0,1); 
	addEdge(adj,0,2); 
	addEdge(adj,1,2);
	addEdge(adj,3,4);
    addEdge(adj,5,5);
    
    cout << DFS(adj, 0, v) << endl;
    
}