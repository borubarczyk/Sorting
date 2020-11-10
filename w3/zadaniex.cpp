#include <iostream>
#include <climits>
#include <windows.h>
#include <conio.h>

using namespace std;

int dod(int licz_1, int licz_2)
{
   return licz_1+licz_2;
}
int ode(int licz_1, int licz_2)
{
   return licz_1-licz_2;
}
int moz(int licz_1, int licz_2)
{
   return licz_1*licz_2;
}
int dziel(int licz_1, int licz_2)
{
   return licz_1/licz_2;
}
int main()
{
    cout<<"[0]Dodawanie odejmowanie mnożenie dzielenie"<<endl;
    cout<<"[ESC]Wciśnij ESC aby zakończyć"<<endl;
    char typ;
    int w1,w2;
    while (_kbhit()!=1)
    {
    cout<<"podaj 2 liczby"<<endl;
    cin>>w1;
    cin>>typ;
    cin>>w2;
    switch (typ)
    {
        case '+': cout<<dod(w1,w2)<<endl;
            break;
        case '-':  cout<<ode(w1,w2)<<endl;
            break;
        case '*':  cout<<moz(w1,w2)<<endl;
            break;
        case '/':  cout<<dziel(w1,w2)<<endl;
            break;
    }
    }

    return 0;
}
