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
Node *insertatbegin(Node *head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    return temp;
}
void printlist(Node *head)
{
    Node *curr = head;
    while(curr->next != NULL)
    {
        cout<< curr->data <<" ";
        curr = curr ->next;
    }
    cout<< curr -> data;
}
int searchlinkedlist(Node *head,int n)
{   
    int pos = 1;
    Node *curr = head;
    while(curr != NULL)
    {
        if(curr->data == n)
        {
            return pos;
        }
        else{
            curr = curr->next;
            pos++;
        }
    }
    return -1;
    
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
        head = insertatbegin(head,n);
        
    }
    int search_val;
    cin >> search_val;
    cout<< searchlinkedlist(head,search_val);
    
}