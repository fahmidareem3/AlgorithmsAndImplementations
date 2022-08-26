#include<bits/stdc++.h>
using namespace std;
bool DFScycle(vector<int>adj[], bool isvisited[], bool recStk[], int s){
    isvisited[s] = true;
    recStk[s] = true;
    for(int x : adj[s] ){
        if(isvisited[x] == false && DFScycle(adj,isvisited,recStk,x)){
            return true;
        }
        else if(recStk[x] == true) return true;
    }
    recStk[s] = false;
    return false;
}
bool DFS(vector<int>adj[], int v){
    bool isvisited[v];
    bool recStk[v];
    for(int i = 0 ; i < v; i++){
        isvisited[i] = false;
    }
    for(int i = 0; i < v; i++){
        recStk[i] = false;
    }
    for(int i = 0; i < v; i++){
        if(isvisited[i] == false){
            if(DFScycle(adj,isvisited,recStk,i) == true){
                return true;
            }
        }
    }
    return false;
}
void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
}
int main(){
    int v = 6;
    vector<int>adj[v];
    addEdge(adj,0,1);
    addEdge(adj,2,1);
    addEdge(adj,2,3);
    addEdge(adj,3,4);
    addEdge(adj,4,5);
    addEdge(adj,5,3);
    if(DFS(adj,v)) cout<< "Cycle detected"<< endl;
    else cout<<"Not detected"<< endl;
    
}