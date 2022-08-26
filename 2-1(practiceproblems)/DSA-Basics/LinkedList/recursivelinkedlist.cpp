#include<bits/stdc++.h>
using namespace std;
struct Node
{
   int data;
   Node *next;
   Node(int x){
       data = x;
       next = NULL;

   }
};
void recursive_print(Node *head){
    if(head == NULL)
    {
        return;
    }
    cout << (head -> data) << " ";
    recursive_print(head -> next);
}
int main()
{
    Node *head = new Node(10);
    head -> next = new Node(20);
    head -> next -> next = new Node(30);
    head -> next -> next -> next = new Node(40);
    recursive_print(head);
}