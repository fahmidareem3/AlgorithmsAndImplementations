#include<bits/stdc++.h>
using namespace std;
struct Point{
    int x;
    int y;
};
bool myCmp(Point p1, Point p2)
{
    return(p1.x < p2.x); //change here to get
}
int main()
{
    Point arr[] = {{3,10},{2,8},{5,4}};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr,arr+n,myCmp);
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i].x<< arr[i].y<<" ";
    }
    

}