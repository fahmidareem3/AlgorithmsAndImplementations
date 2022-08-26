#include<bits/stdc++.h>
using namespace std;
bool DFSCycle(vector<int>adj[], int s, bool isvisited[],int parent){
    isvisited[s] = true;
    for(int x : adj[s]){
       if(isvisited[x] == false){
           if(DFSCycle(adj, x, isvisited,s) == true){
               return true;
           }
       }
       else if(x != parent) return true;
    }
    return false;
}
bool DFS(vector<int>adj[], int v){
    bool isvisited[v];
    for(int i = 0; i < v; i++){
        isvisited[i] = false;
    }
    for(int i = 0; i < v; i++){
        if(isvisited[i] == false){
            if(DFSCycle(adj,i,isvisited,-1)){
                return true;
            }
        }
    }
    return false;
}
void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main(){
    int v = 6;
    vector<int> adj[v];
	addEdge(adj,0,1); 
	addEdge(adj,1,2); 
	addEdge(adj,2,4); 
	addEdge(adj,4,5); 
	addEdge(adj,1,3);
	addEdge(adj,2,3);

	if(DFS(adj,v))
	    cout<<"Cycle found";
	else
	    cout<<"No cycle found";

	return 0; 
}