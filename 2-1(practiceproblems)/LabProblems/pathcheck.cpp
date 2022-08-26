#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int a, int b){
    adj[a].push_back(b);
   
}
int DFSPATH(vector<int>adj[],int source, int des){
    for(int it : adj[source]){
        if(DFSPATH(adj,it,des))
        {  // cout<<it<<" ";
            return true;
        }
        else if(it == des)
        {
        //cout<<it<<" ";
        return true;
        }
    }
    return false;
}
int main(){
    int n,m;
    cin >> n >> m;
   // vector<int>pathtracker;
    vector<int>adj[n+1];
    for(int i = 1; i <= m; i++){
        int a,b; 
        cin >> a >> b; 
        addEdge(adj,a,b);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(DFSPATH(adj,i,j) == true) cout<<i << " " << j<< " :"<< " Yes"<<"\n";
            else cout<<i << " " << j<< " :"<< " No"<<"\n";
        }
    }
}