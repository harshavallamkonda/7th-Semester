#include<bits/stdc++.h>
using namespace std;
void rec(int test)
{
    if(test < 1)
    return;
    else{
        cout<<test<<"";
        rec(test - 1);
        cout<< test << " ";
        return;
    }
}
int main()
{
int test = 3;
rec(test);
}