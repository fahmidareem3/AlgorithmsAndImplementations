#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    //this is a constructor that initialises
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printlist(Node *head){
    Node *curr = head;
    while(head != NULL)
    {
        cout<< curr -> data<< " ";
        curr = curr -> next;
    }
}
int main()
{
   Node *head = new Node(10);
   head -> next = new Node(20);
   head ->next -> next = new Node(30);
   head -> next ->next = new Node(40);
   printlist(head);
}