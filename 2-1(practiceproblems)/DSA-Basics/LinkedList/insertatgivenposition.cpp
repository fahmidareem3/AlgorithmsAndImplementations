#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }

};
Node *insertatend(Node *head, int x)
{
    Node *temp = new Node(x);
    if(head == NULL) return temp;
    Node *curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}
Node *insertatposition(Node *head, int pos, int val)
{
    Node *temp = new Node(val);
    if(pos == 1)
    {
        temp->next = head;
        return temp;
    }
    Node *curr = head;
    for(int i = 1; i <= pos-2 && curr!= NULL; i++)
    {
        curr = curr->next;
    }
    if(curr == NULL) return head;
    temp->next = curr->next;
    curr->next = temp;
    return head;
}
void printlist(Node *head)
{
    Node *curr = head;
    while(curr != NULL)
    {
        cout<< curr->data << " ";
        curr = curr->next;
    }
   
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
    int position, value;
    cin >> position >> value;
    head = insertatposition(head,position,value);
    printlist(head);

}