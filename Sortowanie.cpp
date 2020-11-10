#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <fstream>
#include <climits>
#include <random>
#include <chrono>

using namespace std;

void color(int wartosc)
{SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),wartosc);}

void cls()
{system("cls");}

void los(int wartosc_2)
{if (wartosc_2==0){cout<<"rosnace";}
if (wartosc_2==1){cout<<"malejace";}}

int main()
{
    starting:
    color(02);
    int m=0,ile_liczb,bufor,o=0,d=1,x=0,wyb_typ_sort,valeu,mn=0,mx=2147483647;
    short int mnmx,wybor;
    std::default_random_engine RandomGenerator;
    std::uniform_int_distribution<int> distribution(0,2147483646);
    system("chcp 28592");
    SetConsoleTitle("Sortowanie :)");
    fstream in,out;
    in.open("in.txt", ios::trunc | ios::out );
    out.open("out.txt", ios::trunc | ios::out );
    if (in.good()&&out.good())
    {
    clock_t st,sto;
    double czas;
    cout<<"[]Sortowanie danych"<<endl;
    cout<<"[]Sortowanie rosnace [0] / malejace [1] : ";cin>>wyb_typ_sort;

    if (wyb_typ_sort!=1&&wyb_typ_sort!=0)

    {cls();color(04);cout<<'\n'<<"[]Nieprawidlowa wartosc !"<<'\n'; color(07);Sleep(1500);cls();goto starting ;}

    cout<<"[]Podaj ile liczb chcesz posortowac : ";cin>>ile_liczb;

    ile_liczb--;
    int liczba[ile_liczb];
    cout<<"[]Losowanie pseudolosowe [0] / Wprowadzenie liczb [1] : ";cin>>wybor;
    zakres:
    cout<<"[]Chesz podac zakres TAK [1] / NIE [0] : ";cin>>mnmx;

    if (mnmx==1)
    {   
        mn=0;
        mx=0;
        cout<<"[]Wartosc najmniejsza : ";cin>>mn;
        cout<<"[]Wartosc najwiesza : ";cin>>mx;
    }
    else if (mnmx==0)
    {}
    else
    {color(04);cout<<'\n'<<"[]Nieprawidlowa wartosc !"<<'\n'; color(07);Sleep(1500);cls();color(02);goto zakres ;}
      
    switch (wybor)
    {
    case 1:
        cout<<"[]Sortowanie ";los(wyb_typ_sort);cout<<" "<<ile_liczb+1<<" liczb"<<endl;
        for (m; m<=ile_liczb; m++)
        {cout<<m+1<<". liczba to: ";cin>>liczba[m];
        o++;in<<"["<<liczba[m]<<"] ";
        if (o>9){in<<'\n';o=0;}}
        break;
    case 0:
        cout<<"[]Sortowanie pseudolosowe ";los(wyb_typ_sort);cout<<" "<<ile_liczb+1<<" liczb"<<endl;
        for (m;m<=ile_liczb;m++)
        {
            valeu=distribution(RandomGenerator);
            liczba[m]=valeu;

            o++;in<<"["<<liczba[m]<<"] ";

            if (o>=10)
            {in<<'\n';o=0;}
        
        }
        break;
    default :
        {goto starting;
        cls();}
    }color(07);
        cout<<endl<<"[]Sprobujmy je posortowac"<<endl;
        st = clock();
        for (int b = 0 ; b<=ile_liczb; b++)
        {for (int n = 0; n<=(ile_liczb-d); n++)
            {
                switch (wyb_typ_sort)
                {
                case 0:
                    if (liczba[n]>liczba[n+1])
                    {swap(liczba[n],liczba[n+1]);}
                    break;
                case 1:
                    if (liczba[n]<liczba[n+1])
                    {swap(liczba[n],liczba[n+1]);}
                    break;
                }}d++;}
                    sto = clock();o=0;
                    czas=(double)(sto-st)/ CLOCKS_PER_SEC;
                    cout<<endl<<"[]Posortowane!"<<endl;
                    cout<<"[]W czasie : "<<czas<<" sekund"<<endl;
                    for (m=0; m<=ile_liczb; m++)
                    {if (liczba[m]==liczba[m+1]){x++;}
                        o++;out<<"["<<liczba[m]<<"] ";
                    if (o>=10){out<<'\n';o=0;}}
                    cout<<"[]Bylo "<<x<<" powtorzen"<<endl;
                    in.close();
                    out.close();
                    starting_2:
                        color(04);
                    cout<<endl<<'\n'<<"[ESC] TO EXIT PROGRAM "<<endl;
                    cout<<"[SPACE] TO SEE SORTED VALUES"<<endl;
                    cout<<"[BACKSPACE] TO RUN AGAIN "<<'\n'<<endl;
                        color(07);
    start:
            if (_kbhit()==1)
            {
                switch (getch())
                {
                case 8:
                    cls();
                    goto starting;
                break;
                case 27:
                    system(EXIT_SUCCESS);
                break;
                case 32:
                    color(14);
                    for (m=0; m<=ile_liczb; m++)
                    {o++;cout<<"["<<liczba[m]<<"]";
                    if (o>=5){cout<<endl;o=0;}}
                    color(07);
                    goto starting_2;
                break;
                default:
                    goto start;
                break;
                }
            }
            else {goto start;}
    endling:
            system(EXIT_SUCCESS);
        }
        else
        {
            color(04);
            cout<<"Can't open a file"<<endl;
            EXIT_FAILURE;
        }
}
