#include <iostream>
#include <fstream>

using namespace std;
//using namespace std::chrono;


int main ()

{
    ofstream dane;
    dane.open( "dane_wyjœciowe.txt", ios::app );
    if (dane.is_open())
    {
    unsigned long long int x,y;
    int c;
    for (x=0;;x++)
    {
        cout<<x<<endl;
        c=1;
        dane<<"["<<x<<"]: [1]";
        for (y=2;y<=x;y++)
        {
            if (x%y==0)
            {
                dane<<"["<<y<<"]";
                c++;
            }

        }
        dane<<" : Ilosc dzielnikow: "<<c<<endl;
    }
    }
    else
    {
        cout<<"Cant open a file !"<<endl;
    }

    return 0;
}
