#include<bits/stdc++.h>
using namespace std;
int evaluatepostfix(string s){
    stack<int>st;
    for(int i = 0; s[i]; i++){
        if(isdigit(s[i])) st.push(s[i] - '0');
        else{
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            switch(s[i]){
                case '+' : st.push(op2 + op1);break;
                case '-' : st.push(op2 - op1);break;
                case '/' : st.push(op2 / op1);break;
                case '*' : st.push(op2 * op1);break;
            }
        }
    }
    return st.top();
}
int main(){
    string s;
    cin >> s;
    int sol = evaluatepostfix(s);
    cout << sol << endl;
}