//31
#include<bits/stdc++.h>
using namespace std;
map<char,string>m;
struct Node{
    char data;
    unsigned frequency;
    Node *left;
    Node *right;
    Node(char data, unsigned freq, Node *l = NULL, Node *r = NULL)
    {
        this->data = data;
        this->frequency = freq;
        this->left = l;
        this->right = r;

    }
};
void printCodes(struct Node * root, string str){
    if(root == NULL) return;
    if(root -> data != '$'){
      m[root -> data] = str;

    }
    printCodes(root->left,str+"0");
    printCodes(root->right,str+"1");
}
struct compare{
    bool operator()(Node *l, Node *r){
        return(l -> frequency > r->frequency);
    }
};
void printHcodes(char arr[], int freq[], int size){
    priority_queue<Node* ,vector<Node*>, compare>h;
    for(int i = 0; i < size; i++){
        h.push(new Node(arr[i],freq[i]));
    }
    while(h.size() > 1){
        Node *l = h.top(); h.pop();
        Node *r = h.top(); h.pop();
        Node *top = new Node('$', l->frequency+r->frequency,l,r);
        h.push(top);
    }
    printCodes(h.top(),"");
}
int main(){
  	int n;
    cin >> n;
    char arr[n];
    int freq[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        cin >> freq[i];
    }

	int size = sizeof(arr) / sizeof(arr[0]);

	printHcodes(arr, freq, size);
    for(auto it : m){
        cout<<it.first<<" "<<it.second<<"\n";
    }
	return 0;
}