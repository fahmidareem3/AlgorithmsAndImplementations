#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[], int u, int v){
    adj[u].push_back(v);
}
void printpath(vector<int>v){
   for(int i = 0; i < v.size(); i++){
       cout<<v[i]<<" ";
   }
   cout<<"\n";
}
void DFSpathbetween(vector<int>adj[],int s, int des,int n,vector<bool>&visited,vector<int>path,int count[]){
     visited[s] = true;
     path.push_back(s);
     for(int x: adj[s]){
       if(visited[x] == false){
           if(x == des){
            //    path.push_back(x);
            //    printpath(path);
            count[0]++;
           }
           else{
               DFSpathbetween(adj,x,des,n,visited,path,count);
           }
       }
       else{
           path.pop_back();
       }
     }

}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int>adj[n+1];
    for(int i = 1; i <= m; i++){
        int a,b; 
        cin >> a >> b; 
        addEdge(adj,a,b);
    }
    int p,q;
    cin >> p >> q;
    int count[1];
    count[0] = 0;
    vector<bool>visited(n+1,false);
    vector<int>path;
    DFSpathbetween(adj,p,q,n,visited,path,count);
    cout<<count[0]<<"\n";
}