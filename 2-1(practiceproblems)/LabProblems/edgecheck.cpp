#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<int>>&a,int x, int y){
    a[x].push_back(y);
}
// void printList(vector<vector<int>>&a,int n){
//     for(int i = 1; i <= n; i++){
//         for(auto it : a[i]){
//             cout<< i << " " << it<<"\n";
//         }
//     }
// }
int checkEdge(vector<vector<int>>&a,int x, int y){
    for(auto it : a[x]){
        if(it == y) return 1;
    }
    return 0;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>>a(n+1);
    for(int i = 1; i <= m; i++){
       int x,y;
       cin >> x >> y;
       addEdge(a,x,y);
    }
    // printList(a,n);
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            if(checkEdge(a,i,j)){
                cout<<i<<" "<<j<<" :"<<" Yes"<<"\n";
            }
            else  cout<<i<<" "<<j<<" :"<<" No"<<"\n";
        }
    }
}