#include<bits/stdc++.h>
using namespace std;
struct MyStack{
    int *arr;
    int cap;
    int top;
    MyStack(int c){
        cap = c;
        arr = new int [cap];
        top = -1;
    }
    void push(int x){
        if(top == cap -1){
            cout<<"Stack is full"<< endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    int pop(){
        if(top == -1){
            cout<< "Stack is empty"<<endl;
            return -1;
        }
        int res = arr[top];
        top--;
        return res;
    }
    int peek(){
        if(top == -1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }
    int size(){
        return (top+1);
    }
    bool isEmpty(){
        if(top == -1)
        {
            return true;
        }
        return false;
    }
};
int main()
{
   MyStack s(5);
   s.push(5);
   s.push(10);
   s.push(20);
   cout << s.pop()<< endl;
   cout<< s.size()<<endl;
   cout<<s.peek()<<endl;
   cout<<s.isEmpty()<<endl;
   return 0;
}