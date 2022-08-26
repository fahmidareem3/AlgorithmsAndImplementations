#include<bits/stdc++.h>
using namespace std;
void merge_sorted(int a[], int b[], int n, int m)
{
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if(a[i] <= b[j])
        {
            cout<<a[i] << " ";
            i++;
        }
        else{
            cout<<b[j] << " ";
            j++;
        }
    }
    while(i < n)
    {
         cout<<a[i] << " ";
        i++;
    }
      while(j < m)
    {
         cout<<b[j] << " ";
         j++;
    }
}
int main()
{
    int arr1[] = {10,20,50};
    int arr2[] = {5,50,50};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
     merge_sorted(arr1,arr2,n,m);
    

}