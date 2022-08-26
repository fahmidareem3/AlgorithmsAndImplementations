//31
//31
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>adj[], int s, int d){
    adj[s].push_back(d);
    adj[d].push_back(s);
}
int isbipartite(vector<int>adj[], int v){
    vector<int>col(v,-1);
    queue<pair<int,int>>q;
    for(int i = 0; i < v; i++){
        if(col[i] == -1){
            col[i] = 0;
            q.push({i,0});
            while(q.empty() == false){
            pair<int,int>p = q.front();
            q.pop();
            int current_node = p.first;
            int current_color = p.second;
            for(int j : adj[current_node]){
                if(col[j] == current_color) return 0;
                else if(col[j] == -1){
                    if(current_color == 0) col[j] = 1;
                    else if(current_color == 1) col[j] = 0;
                    q.push({j,col[j]});

                }
            }
        }
        }
    }
    return 1;
}

int main(){
    int vertice, edge;
    cin >> vertice >> edge;
    vector<int>adj[vertice];
    for(int i = 0; i < edge; i++){
        int p,q;
        cin >> p >> q;
        addEdge(adj,p,q);
    }
    if(isbipartite(adj,vertice)) cout<<"Yes\n";
    else cout<<"No\n";
}