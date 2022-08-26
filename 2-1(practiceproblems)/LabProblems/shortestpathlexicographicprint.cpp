//31
//31
//31
#include<bits/stdc++.h>
using namespace std;
#define White 0
#define Gray 1
#define Black 2
void addEdge(vector<int>adj[],int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void Bfs(vector<int>adj[],vector<int>&distance,int s,vector<int>&color){
    color[s] = Gray;
    queue<int>q;
    q.push(s);
    while(q.empty() == false){
        int u = q.front();
        q.pop();
        for(int x : adj[u]){
            if(color[x] == White){
                color[x] = Gray;
                q.push(x);
                distance[x] = distance[u] + 1;
            }
        }
    }

}
void pathprinting(vector<int>v,int mindes[],int des,int prevdes[]){
    // cout<< v.size()<<" ";
    // cout<<mindes[0]<<" ";
    //cout<< prevdes<<" ";
    //cout<<prevdes[0]<<" ";
    // cout<<des<<" ";
    if(v.size() - 1 == mindes[0]){
    if(prevdes[0] != des)
    {   cout<<des<<": ";
        for(int i = 0; i < v.size(); i++){
        if(i == v.size()-1) cout<<v[i];
        else
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    }
    prevdes[0] = des;
    //cout<<"\n";
    }
    //prevdes[0] = des;
}
void pathprint(int s, int des, vector<int>distance,vector<int>adj[],int mindes[],vector<int>&visited,vector<int>path,int prevdes[]){
    visited[s] = Gray;
    //vector<int>path;
    path.push_back(s);
    for(int x : adj[s]){
      if(visited[x] == White){
          if(x == des){
              path.push_back(x);
              pathprinting(path,mindes,des,prevdes);
          }
          else pathprint(x,des,distance,adj,mindes,visited,path,prevdes);
      }
     
    }
    

}
void BfsShortest(vector<int>adj[],int v){
    vector<int>color(v,White);
    vector<int>distance(v,0);
    int count = 0;
    for(int i = 0; i < v; i++){
        count++;
        if(count > 1) break;
        if(color[i] == White)
        {Bfs(adj,distance,i,color);}
    }
   int i = 0;
   int prevdes[1];
   prevdes[0] = -1;
   vector<int>path;

   cout<<"0: "<<"0"<<"\n";
   //vector<int>visited(v,White);
   for(int j = 0; j < v; j ++){
       if(j != 0 && distance[j] == 0) cout<<j<<": "<<"Not Reachable\n";
       else{
           int mindes[1];
           mindes[0] = distance[j];
           vector<int>visited(v,White);
           path.clear();
        
           pathprint(i,j,distance,adj,mindes,visited,path,prevdes);
       }

}
}
void printlist(vector<int>adj[],int v){
    for(int i = 0; i < v; i++){
        for(auto it : adj[i]){
            cout<< i << " "<<it<<" ";
        }
        cout<<"\n";
    }
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
    for(int i = 0; i < v; i++){
        sort(adj[i].begin(),adj[i].end());
    }
    //printlist(adj,v);
    
    BfsShortest(adj,v);
}