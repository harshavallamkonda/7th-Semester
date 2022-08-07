#include<iostream>
using namespace std;
int main(){
     int row , col;
     cout<<"Enter number of rows and columns:"<<endl;
     cin>> row>> col;
     
     for(int i = 1; i<=row ; i++){
         for(int  j =1 ; j<=col ; j++){
             if(i==1 || i == row || j==1 || j==col){  //Here in the 1st postition of row we will be printing continous *'s and in the first col and 
                                                        //last col we will be printing continous stars 
                 cout<<"*";
             }
             else{
                 cout<<" ";
             }
         }
         cout<<endl;
     }
}