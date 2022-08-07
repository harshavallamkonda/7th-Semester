#include<iostream>
using namespace std;
int main(){
    int i = 10 , j =20, k;
    k = i++ + j-- + i-- - j++;
    cout<<k;
    
}