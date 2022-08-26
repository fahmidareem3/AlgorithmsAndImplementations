#include<bits/stdc++.h>
using namespace std;
struct Node{
    int key;
    Node *left,*right;
    Node(int x){
        key = x;
        left = right = NULL;
    }
};
NO inserttobin(Node *root,int x){
    if(root == NULL){
        return new Node(x);
    }
}
int main(){
    int n;
    cin >> n;
    Node *root = new Node(n);
    int node_number;
    cin >> node_number;
    while(node_number--)
    {
        int node;
        cin >> node;
        inserttobin(root,node);
    }
    inorder(root);
}