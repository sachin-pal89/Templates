// we will create a template function here
#include<iostream>
#include<string>
using namespace std;

template <class T>        // here we have define a type which is to be used in function
void func_swap(T &a, T &b)     // this show that a,b are of same type
                               // also we have perform function call by reference here
{ 
    T swapp ;
    swapp = a;
    a = b;
    b = swapp;
}

int main()
{
    int a=6, b=4;

    func_swap(a,b);
    cout<<a<<endl<<b;
    return 0;
}
