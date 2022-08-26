#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
    vector<int>v = {3,6,7,4};
    int n = v.size();
    sort(v.begin(),v.end());
    for(int i = 0; i < n; i++)
    {
        cout<< v[i] << " ";
    }
    cout<< endl;
    sort(v.begin(),v.end(),greater<int>());

     for(int i = 0; i < n; i++)
    {
        cout<< v[i] << " ";
    }
    
}