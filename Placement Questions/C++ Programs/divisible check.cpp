#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    if (n%2==0 && n%3==0 ){
        cout<<"Both are divisble "<<endl;
        
    }
    else if( n%2==0){
        cout<<"Divisible by 2"<<endl;
        
    }
    else if(n%3==0){
        cout<<"Divisible by  3"<<endl;
    }
    else{
        cout<<"Not Divisible by both the numbers"<<endl;
    }


    
}