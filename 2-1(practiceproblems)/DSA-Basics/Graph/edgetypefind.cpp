#include<bits/stdc++.h>
using namespace std;
#define Gray 1
#define White 0
#define Black 2
int edgecheck(vector<int>adj[],int x,int y){
    for(auto it : adj[x]){
        if(it == y)
        return 1;
    }
    return 0;
}
void DFS(vector<int>adj[],vector<int>&starting,vector<int>&finishing,int s,vector<int>&color,int time[]){
    color[s] = Gray;
    starting[s] = time[0];
    time[0]++;
    for(int x: adj[s]){
        if(color[x] == White){
            color[x] = Gray;
            DFS(adj,starting,finishing,x,color,time);
        }
    }
    color[s] = Black;
    finishing[s] = time[0];
    time[0]++;
    
}
void DfsComp(vector<int>adj[],vector<int>&starting,vector<int>&finishing,int v,vector<int>&color){
    int time[1];
    time[0] = 1;
    for(int i = 0; i < v; i++){
     if(color[i] == White){
         DFS(adj,starting,finishing,i,color,time);
     }
    }
    for(int i = 0; i < v; i++){
       for(int j = 0; j < v; j++){
           if(edgecheck(adj,i,j)){
               if(starting[i] < starting[j] && finishing[i] > finishing[j]){
                  
                       if(starting[j]-starting[i] ==  1 ) printf("%d %d (T)\n",i,j);
                       else printf("%d %d (F)\n",i,j);
                   

               }
               else if(starting[i] > starting[j] && finishing[i] < finishing[j]) printf("%d %d (B)\n",i,j);
               else printf("%d %d (C)\n",i,j);
           }
       }
    }
}
void addEdge(vector<int>adj[],int u,int v){
    adj[u].push_back(v);
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
  
  vector<int>color(v,White);
  vector<int>startingtime(v,0);
  vector<int>finishingtime(v,0);
  DfsComp(adj,startingtime,finishingtime,v,color);
}