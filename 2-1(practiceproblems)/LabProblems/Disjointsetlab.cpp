//31
#include <bits/stdc++.h>
using namespace std;
void initialize(int parent[],int rank[],int n){
    for(int i = 0 ; i < n ; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}
int find(int parent[],int x){
    if(parent[x] == x)return x;

    parent[x] = find(parent,parent[x]);

    return parent[x];
}
void union_set(int parent[],int rank[],int x,int y){
    int x_rep = find(parent,x);
    int y_rep = find(parent,y);

    if(x_rep == y_rep) return;

    if(rank[x_rep] < rank[y_rep])parent[x_rep]= y_rep;
    else if(rank[x_rep] > rank[y_rep])parent[y_rep]=x_rep;
    else{
        parent[y_rep] = x_rep;
        rank[x_rep]++;
    }
}

int main(){
    int n,m;
    cin >> n >> m;
    //getchar();
    int parent[n],rank[n];
    initialize(parent,rank,n);
    while(m --){
        string s;
        cin >> s;
        int a, b;
        cin >> a >> b;
        if(s[0] == 'J'){
            union_set(parent,rank,a,b);
        }
        else if(s[0] == 'F'){
            if(find(parent,a) == find(parent,b)){
                cout<<"Yes\n";
            }
            else cout<<"No\n";
        }
    }
}