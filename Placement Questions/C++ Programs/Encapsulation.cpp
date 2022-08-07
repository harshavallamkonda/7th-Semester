/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using std::string;
using namespace std;
class Employee{
private:
string Name;
string Company;
int Age;

public:
void setName(string name){
    Name = name;       /* Setter method*/
}
string getName(){
    return Name; /*Get Method*/
}
void setCompany(string company){
    Company = company;
}
string getCompany(){
    return Company;
}
void setAge(int age){
    if(age>=18)
    Age = age;
}
int getAge(){
    return Age;
}

      void intoduce(){
      cout<<"Name - "<<Name<<endl;
      cout<<"Company - "<<Company<<endl;
      cout<<"Age - "<<Age<<endl;

  }
  Employee(string name, string company, int age){
      Name = name;
      Company = company;
      Age = age;
      
  }

};

int main()
{
    Employee employee1 = Employee("Harsha", "Google", 22);
    employee1.intoduce();
    employee1.setAge(10);
    cout<<employee1.getName()<<"is"<<employee1.getAge()<<endl;


}
