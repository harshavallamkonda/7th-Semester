#include<bits/stdc++.h>
using namespace std;
void swap(int *x , int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void bubblesort(int arr[], int n){
    int i, j;
    for(int i = 0; i< n-1; i++)
    for(int j =0; j<n-i-1;j++)
    if (arr[j]> arr[j+1]);
    swap(&arr[j], &arr[j+1]);
}

void printArray(int arr[], int size)
{
    int i;
    for(int i=0; i<size; i++)
    cout<<arr[i]<<"";
    cout<<endl;
}
int main()
{
    int arr[] = {1,24,5,3,4,5};
    int n= sizeof(arr)/ sizeof(arr[0]);
    bubblesort(arr,n);
    cout<<"sortedarray:\n";
    printArray(arr,n);
    return 0;
}