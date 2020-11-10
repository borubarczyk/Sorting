#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

void color(unsigned short int wartosc_koloru)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),wartosc_koloru);
}
void cls()
{
    system("cls");
}

int main()
{
fstream in,out;
in.open("input.txt", ios::trunc | ios::out );
out.open("output.txt", ios::trunc | ios::out );
start:
unsigned short int where_val,sort_direc;
unsigned int how_many;
SetConsoleTitle("SORTOWANIE");
color(02);
cout<<"#Sorotowanie "<<endl;
cout<<"#Podaj wartosci [0] / Wylosuj wartosci [1] : ";
cin>>where_val;
    switch(where_val)
    {
        case 0:
            {
                pocz_podaj_wart:
                cout<<"#Prosze podaj ile wartosci chcesz wprowadzic : ";cin>>how_many;
                if (how_many<=1000000)
                {
                    int tab[how_many];
                    cout<<"Podaja wartosci :"<<endl;
                    for (int i=0; i<(how_many);i++)
                    {
                        pocz_petli:
                        if (!cin.fail())
                        {
                        cout<<i+1<<". = ";cin>>tab[i];
                        }
                        else
                        {
                            cout<<"#Zla wartosc !"<<endl;
                            --i;
                            cin.clear();
                            cin.ignore(80, '\n');
                            goto pocz_petli;
                        }
                    }
                }
                else
                {
                cout<<"#Podana wartosc nieprawidlowa"<<endl;
                cout<<"#Wartosc z przedzialu od 0 do 4 294 967 295"<<endl;
                cls();
                Sleep(1500);
                goto pocz_podaj_wart;
                }
            }
            break;
        case 1:
            {
                cout<<"#Ile wartosci wylosowac ? :"<<endl;
            }
            break;
        default:
        {
            cout<<"#Wartosc nieprawidlowa !"<<endl;
            Sleep(1500);
            cls();
            goto start;
        }
    }
cout<<"#Sortowanie rosnace [0] / Sortowanie malejace [1] "<<endl;
color(04);




}
