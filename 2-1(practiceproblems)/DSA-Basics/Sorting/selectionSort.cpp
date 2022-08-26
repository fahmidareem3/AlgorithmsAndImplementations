#include<bits/stdc++.h>
using namespace std;
void selection_sort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int min_index = i;
        for(int j = i+1; j < n; j++)
        {
             if(arr[j] < arr[min_index])
             {
                 min_index = j;
             }
        }
        swap(arr[min_index],arr[i]);
    }
}
int main()
{
    int arr[] = {6,7,4,3,2,1,0};
    int n = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr,n);
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<< " ";

    }
}