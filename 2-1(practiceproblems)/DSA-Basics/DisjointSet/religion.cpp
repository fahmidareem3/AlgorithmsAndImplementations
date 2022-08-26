#include<bits/stdc++.h>
using namespace std;
void initialize(int parent[], int ranked[], int n){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
    for(int i = 1; i <= n; i++){
        ranked[i] = 0;
    }
}
int find_parent(int x, int parent[]){
    if(parent[x] == x) return x;
    else return find_parent(parent[x],parent);
}
void union_make(int x, int y, int parent[], int ranked[]){
    int x_parent = find_parent(x,parent);
    int y_parent = find_parent(y,parent);
    if(x_parent == y_parent) return;
    if(ranked[x_parent] < ranked[y_parent]) parent[x_parent] = y_parent;
    else if(ranked[y_parent] < ranked[x_parent]) parent[y_parent] = x_parent;
    else{
        parent[y_parent] = parent[x_parent];
        ranked[x_parent]++;
    }
}
int main(){
    int n,m;
    vector<int>test;
     while(scanf("%d%d",&n,&m) && n != 0 && m != 0){
         int parent[n+1];
         int ranked[n+1];
        initialize(parent,ranked,n);
        while(m--){
            int i,j;
            cin >> i >> j;
            union_make(i,j,parent,ranked);
            
        }
         set<int>s;
        for(int i = 1; i <= n; i++){
            //cout<<find_parent(i,parent);
            s.insert(find_parent(i,parent));
           
        }
        test.push_back(s.size());
       
     }
     for(int i = 0; i < test.size(); i++){
         cout<<"Case"<<" "<<i+1<<":"<<" "<<test[i]<<endl;
     }
    
}