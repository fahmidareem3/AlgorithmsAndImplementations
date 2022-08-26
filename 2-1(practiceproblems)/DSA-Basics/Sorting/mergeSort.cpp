#include<bits/stdc++.h>
using namespace std;
void merge(int a[], int l, int m, int r)
{
    int n1 = m-l + 1;
    int n2 = r-m;
    int x[n1];
    int y[n2];
    for(int i = 0; i < n1; i++)
    {
        x[i] = a[i+l]; //low can be different
    }
    for(int j = 0; j < n2; j++)
    {
        y[j] = a[j+m+1]; // because mid+1 will be starting
    }
    int i = 0, j = 0, k = l; //k will be lower index
    while(i < n1 && j < n2)
    {
        if(x[i] <= y[j])
        {
           a[k] = x[i];
           i++;
           k++;
        }
        else{
            a[k] = y[j];
            j++;
            k++;
        }
    }
    while(i < n1)
    {
        a[k] = x[i];
        i++;
        k++;
    }
     while(j < n2)
    {
        a[k] = y[j];
        j++;
        k++;
    }
}
void mergesort(int a[], int l, int r)
{
    if(r > l)
    {
        int m = l + (r-l)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main()
{
    int arr[] = {5,7,10,15,30};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr,0,n-1);
    for(int i = 0; i < n; i++)
    {
       cout<< arr[i] << " ";
    }
}