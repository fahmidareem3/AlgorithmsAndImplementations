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
    int cases = 1;
    while(scanf("%d %d" ,&n ,&m) && n != 0 && m != 0 ){
        int parent[n + 1],rank[n + 1];
        initialize(parent,rank,n + 1);
        for(int i = 0 ; i < m ; i++){
            int q1,q2;
            cin>>q1>>q2;
            union_set(parent,rank,q1,q2);
        }
        set<int>s;
        for(int i = 1 ; i <=n ; i++){
            s.insert(find(parent,i));
        }
        cout<<"Case "<<cases<<": "<<s.size()<<endl;
        cases++;
     }
}