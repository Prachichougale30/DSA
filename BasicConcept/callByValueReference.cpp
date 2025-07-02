#include<iostream>
using namespace std;

void callByValue(int temp)//call by value
{
   cout <<"address of temp in callByValue: " << &temp << endl;
   temp = 10;
   cout << "Value of temp in callByValue: " << temp << endl;
}
void callByReference(int &temp)//call by reference
{
   cout <<"address of temp in callByReference: " << &temp << endl;
   temp = 10;
   cout << "Value of temp in callByReference: " << temp << endl;
}
int main()
{
   int a=5;
   int *ptr=&a;
   cout << "Address of a in main: " << &a << endl;
   callByReference(a);
   cout<<endl;
   callByValue(a);

   cout << "Value of a:"<<*ptr<<endl;

}