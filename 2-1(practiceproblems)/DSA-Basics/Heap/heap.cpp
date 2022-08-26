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
     arr = new int[c];
   }

   int left(int i) 
   {
    return(2*i + 1);
   }
   int right(int i){
       return(2*i + 2);

   }
   int parent(int i){
       return (i-1)/2;
   }
   
   void insert(int x){
       if(size == capacity) return;
       size++;
       arr[size - 1] = x;
       for(int i = size-1; i!= 0 && arr[parent(i)] > arr[i];){
          swap(arr[i], arr[parent(i)]); 
          i = parent(i);
       }

   }
   void minHeapify(int x){
       int leftchild = left(x);
       int rightchild = right(x);
       int smallest = x;
       if(leftchild < size && arr[leftchild] < arr[x]){
           smallest = leftchild;
       }
       if(rightchild < size && arr[rightchild] < arr[smallest]){
           smallest = rightchild;
       }
       if(smallest != x)
      { 
       swap(arr[x], arr[smallest]);
       minHeapify(smallest);
      }
   }
   int extractMin(){
       if(size <= 0) return INT_MAX;
       if(size == 1){
           size --;
           return arr[0];
       }
       
           swap(arr[0], arr[size -1]);
           size --;
           return arr[size];
           minHeapify(0);
       
   }
};

int main() 
{ 
    Minheap h(11);
    h.insert(3); 
    h.insert(2);
    h.insert(15);
    h.insert(20);
    cout << h.extractMin() << " ";
    return 0;
} 
