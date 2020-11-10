#include <iostream>
#include<climits>
#include <windows.h>

using namespace std;

int main()
{
    system("chcp 65001");
    short int a = 0;
    int b = 0;
    cout<<SHRT_MAX<<endl;
    cout<<INT_MAX<<endl;
    a=32767;
    b=2147483647;
    a+1;
    a+2;
    cout<<sizeof(a)<<endl;
    cout<<a*a<<endl;
    cout<< "Wartość a, ";
    if (a>SHRT_MAX)
    {
        cout<<"przekracza short inta"<<endl;
    }
    else
    {
        cout<<"nie przekracza short inta"<<endl;
    }
    cout<<a<<endl;
    cout<<"Wartość b, ";
    if (b>INT_MAX)
    {
        cout<<"przekracza inta"<<endl;
    }
    else
    {
        cout<<"nie przekracza inta"<<endl;
    }
    cout<<b<<endl;
    


    return 0;
}