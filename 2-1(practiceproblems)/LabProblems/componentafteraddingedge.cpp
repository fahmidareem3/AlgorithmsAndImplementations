#include<bits/stdc++.h>
using namespace std;
#define ll long long
void addEdge(vector<ll int>adj[],ll int u,ll int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void DFS(vector<ll int>adj[], vector<bool>&isvisited, ll int s, ll int count[]){
    isvisited[s] = true;
    count[0]++;
    for(ll int i : adj[s]){
        if(isvisited[i] == false){
            DFS(adj,isvisited,i,count);
        }
    }

}
int DFScompsize(vector<ll int>adj[],ll int v){
    vector<bool>isvisited(v+1,false);
    set<ll int>s;
    for(ll int i = 1; i <= v; i++){
        if(isvisited[i] == false){
            ll int count[1];
            count[0] = 0;
            DFS(adj,isvisited,i,count);
            s.insert(count[0]);
        }
    }
    ll int counter = 0;
    ll int val = 0;
    for(auto it : s){
       counter++;
       if(counter == s.size()){
           val = it;
       }
    }
    return val;
}
int main(){
    ll int n,q;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    vector<ll int>adj[n+1];
    while(q--){
        ll int query;
        cin >> query;
        if(query == 1){
            ll int val1,val2;
            cin >> val1 >> val2;
            addEdge(adj,val1,val2);
        }
        else if(query == 2){
            cout<<DFScompsize(adj,n)<<"\n";
        }
    }
}