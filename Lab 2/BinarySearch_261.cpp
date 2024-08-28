#include<bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int Start, int End, int x)
{
    while(Start <= End)
    {
        int mid = (Start + End)/2;
        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            Start = mid + 1;
        else
            End = mid -1;
    }
    return -1;
}

int main()
{
    int n,x;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in sorted order: "<<endl;
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }

    cout<<"Enter the Value: ";
    cin>>x;
    int result = BinarySearch(arr,1,n,x);

    if (result == -1)
        cout<<"Value Not Found."<<endl;
    else
        cout<<"Value Found at Index: "<<result<<endl;
}
