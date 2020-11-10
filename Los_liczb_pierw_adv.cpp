#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <ratio>
#include <chrono>

using namespace std;
using namespace std::chrono;
int main()
{
    ofstream plik;
    plik.open( "l_p.txt" ,ios::out);
    poczatek:
    int c, z, h=0;
    srand(time(NULL));
    cout<<"[] Program do losowania pierwszych liczb "<<endl;
    cout<<"[] Podaj ile ? : ";cin>>z;
    steady_clock::time_point starting = steady_clock::now();
    cout<<"Program wylosowal liczbe pierwsza :"<<endl;;
    for (int o=1; o<=z; )
    {c=0;int liczba=rand();
        for ( int x = 1 ; x<=liczba; x++)
        {if (liczba%x==0)
                {c++;}
                if (c>2){break;}}

        if (c==2)
        {h++;if (h<10)
            {cout<<liczba<<", ";
            plik<<liczba<<endl;}
            else
            {cout<<liczba<<""<<endl;h=0;}o++;}
        c=0;

    }
    steady_clock::time_point ending = steady_clock::now();
    duration <double> durat = duration_cast<duration<double>>( ending - starting );
    cout<< "" <<endl;
    cout<< "" <<endl;
    cout<<"[] ZAJELO TO : " << durat.count() << " SEKUND" <<endl;
    cout<< "" <<endl;
    cout<< "" <<endl;
    wybo:
    string wybor;
    cout<<""<<endl;
    cout<<"[] Ponownie ? TAK/NIE " <<endl;
    cin>>wybor;
            if ((wybor =="T") || (wybor =="t") || (wybor == "TAK" || (wybor =="tak")))
                {
                    system("cls");
                    goto poczatek;
                }
            if ((wybor=="n") || (wybor =="N") || (wybor == "NIE" || (wybor =="nie")))
                {
                    system(EXIT_SUCCESS);
                }
            else
                {
                     cout<<"WRONG KEY"<<endl;
                     system("cls");
                     goto wybo;
                }
    return 0;
}
