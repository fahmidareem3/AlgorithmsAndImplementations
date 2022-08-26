#include<bits/stdc++.h>
using namespace std;
class Minheap{
    int size;
    int capacity;
    int *arr;
    public:
    Minheap(int c){
      capacity = c;
      size = 0;
      arr = new int [c];
    }
    int left(int i ) 
    {
        return(2*i + 1);
    }
    int right(int i){
        return (2*i + 2);
    }
    int parent(int i){
        return (i - 1)/2;
    }
};
int main(){
    Minheap(11);

}