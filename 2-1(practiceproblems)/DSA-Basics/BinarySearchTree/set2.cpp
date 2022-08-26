#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int,greater<int>>s;
    s.insert(10);
    s.insert(5);
    s.insert(20);
    for(auto it = s.begin(); it!= s.end();it++){
        cout << (*it) << " ";
    }
    cout<<endl;
    auto it = s.find(10);
    if(it == s.end()){
        cout << "Not found"<< endl;
    }
    else cout<< "Found"<< endl;
    s.clear();
    cout<< "Size: "<< s.size()<<endl;

}
