#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <ratio>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

int main()
{
    ofstream dane,liczby;
    dane.open( "dane_czasu.txt", ios::app );
    if (dane.is_open())
    {
    poczatek:
    unsigned long long int c,f, z;
    float d=0, s=0;
    srand(time(NULL));
    time_t teraz=time(0);
    char* dt = ctime(&teraz);
    tm*ltm = localtime(&teraz);
    unsigned short int rok,dzien,miesiac,h_m,m_h,sek;
    rok=1900+ltm->tm_year;
    miesiac=1+ltm->tm_mon;
    dzien=ltm->tm_mday;
    h_m=ltm->tm_hour;
    m_h=ltm->tm_min;
    sek=1+ltm->tm_sec;
    cout<<"[] Program do wydajnosci alg "<<endl;
    cout<<"[] Podaj ile ma losowac liczb ? : ";cin>>z;
    cout<<"[] Podaj ile ma losowac powtorzen ? : ";cin>>f;
    dane<<"[] "<<dt<<z<<"x"<<f<<" ";
    cout<<"[] Program wylosowal liczby pierwsze w czasie (sekundy) :"<<endl;
    string nazwa = to_string(z) + "x" + to_string(f) + "_"+ to_string(rok) + "_" + to_string(miesiac) + "_" + to_string(dzien) + "_" + to_string(h_m) + "." + to_string(m_h)+"." + to_string(sek) +".txt";
    cout<<"[] "<<nazwa<<endl;
    liczby.open( nazwa.c_str());
            for (int x=0; x<f;x++)
            {
                steady_clock::time_point starting = steady_clock::now();
                    for (int o=1; o<=z; )
                    {
                        c=0;
                        int liczba=rand();
                        for ( int x = 1 ; x<=liczba; x++)
                            {
                                if (liczba%x==0)
                                    {
                                            c++;
                                    }
                                if (c>2)
                                    {
                                    break;
                                    }
                            }
                        if (c==2)
                            {
                                o++;
                                liczby<<""<<liczba<<" ";
                            }
                        c=0;
                    }
                liczby<<""<<'\n';
                liczby<<""<<'\n';
                steady_clock::time_point ending = steady_clock::now();
                duration<double>durat = duration_cast<duration<double>>( ending - starting );
                cout<<durat.count()<<'\n';
                s=durat.count();
                dane<<"["<<s<<"] ";
                d+=durat.count();
                }
    cout<<"[] Srednia pomiarow wynosi: "<<d/f<<'\n';
    dane<<"[ sr:"<<d/f<<"] "<<'\n';
    wybo:
    string wybor;
    cout<<"[] Ponownie ? TAK/NIE " <<endl;
    cin>>wybor;
            if ((wybor =="T") || (wybor =="t") || (wybor == "TAK") || (wybor =="tak"))
                {
                    system("cls");
                    goto poczatek;
                }
            if ((wybor=="n") || (wybor =="N") || (wybor == "NIE") || (wybor =="nie"))
                {
                    Sleep(750);
                    system(EXIT_SUCCESS);
                }
            else
                {
                     system("cls");
                     cout<<"WRONG KEY"<<endl;
                     Sleep(1500);
                     system("cls");
                     goto wybo;
                }
   }
   else
   {
       cout<<"Nie mozna otwaorzyc pliku"<<endl;
   }
    return 0;
}
