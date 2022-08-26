#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
Node *insertatend(Node *head, int x)
{   
    Node *temp = new Node(x);
    if(head == NULL)
    {
        return temp;
    }
    Node *curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}
void printlist(Node *head)
{
    Node *curr = head;
    while(curr->next != NULL)
    {
        cout<< curr->data<<" ";
        curr = curr->next;
    }
    cout<<curr->data;
}
int main()
{
    int t;
    cin >> t;
    Node *head = NULL;
    while(t--)
    {
        int n;
        cin >> n;
        head = insertatend(head,n);
    }
    printlist(head);
}