#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[],int a, int b){
    adj[a].push_back(b);
   
}
int DFSPATH(vector<int>adj[],int source, int des, vector<int>&pathtracker){
    for(int it : adj[source]){
        if(DFSPATH(adj,it,des,pathtracker))
        {  // cout<<it<<" ";
        pathtracker.push_back(it);
            return true;
        }
        else if(it == des)
        {
        pathtracker.push_back(it);
        //cout<<it<<" ";
        return true;
        }
    }
    return false;
}
void printlist(vector<int>v){
    for(int i = (v.size() - 1); i >= 0; i--){
        cout<< v[i]<<" ";
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<int>pathtracker;
    vector<int>adj[n+1];
    for(int i = 1; i <= m; i++){
        int a,b; 
        cin >> a >> b; 
        addEdge(adj,a,b);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(DFSPATH(adj,i,j,pathtracker) == true) {
                pathtracker.push_back(i);
                cout<<"The path between "<<i <<" & "<< j << " is: ";
                printlist(pathtracker);
                cout<<"\n";
                pathtracker.clear();
            }
            else cout<<i << " " << j<< " :"<< " No"<<"\n";
        }
    }
}