//root is a special node that has parent as itself
#include<bits/stdc++.h>
using namespace std;
#define n 5
int parent[n];
void initialize(){
    for(int i = 0; i < 5; i++){
        parent[i] = i;
    }
}
int find(int x){
    if(parent[x] == x) return x;
    else return find(parent[x]);
}
void unions(int x, int y){
    int x_rep = find(x);
    int y_rep = find(y);
    if(x_rep == y_rep) return;
    else parent[y_rep] = x_rep;

}
int main(){
   initialize();
   unions(0,2);
   unions(2,4);
   unions(1,3);
   
   cout<<find(2)<<endl;
   cout<<find(3);
}