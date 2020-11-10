#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main()
{
    poczatek:
    cout<<"[0] PROSTY KALKULATOR"<<endl;
    cout<<"[1] DODAJ"<<endl;
    cout<<"[2] ODEJMIJ"<<endl;
    cout<<"[3] PODZIEL"<<endl;
    cout<<"[4] POMNOZ"<<endl;
    cout<<"[5] ZAKONCZ"<<endl;
    int opcja_wybrana;
    cout<<"WYBRALES OPCJE NR : "; cin>>opcja_wybrana;
        if ((opcja_wybrana > 0) && (opcja_wybrana <= 5))
        {
            if (opcja_wybrana == 5 )
            {
                cout<<"EXIT PROGRAM"<<endl;
            }
            if (opcja_wybrana== 1 ) //dodawanie
                {
                    int a1;
                    int b1;
                    cout<<"Podaj wartosc a = ";
                    cin >>a1;
                    cout<<"Podaj wartosc b = ";
                    cin>> b1;
                    cout<<a1<<" + " <<b1<< " = " <<a1+b1<<endl;
                    system("pause");
                    system("cls");
                    goto poczatek;
                                    }
            if (opcja_wybrana==2 ) //odejmowanie
            {
                int a2;
                int b2;
                cout<<"Podaj wartosci a = ";
                cin >>a2;
                cout<<"Podaj wartosc b = ";
                cin>> b2;
                cout<<a2<<" - " <<b2<< " = " <<a2-b2<<endl;
                system("pause");
                system("cls");
                goto poczatek;

            }
            if (opcja_wybrana==3 ) // Dzilenie
            {
                int a3;
                int b3;
                cout<<"Podaj wartosci a = ";
                cin >>a3;
                cout<<"Podaj wartosc b = ";
                cin>> b3;
                if ((a3!=0) && (b3!=0))
                {
                    if ( a3 < b3) // jeśli a jest większe niż b
                    {
                        cout<<a3<<"/"<<b3<<endl;
                        system("pause");
                        system("cls");
                        goto poczatek;
                    }
                    if ( a3%b3==0)
                    {
                        cout<<a3/b3<<endl;
                        system("pause");
                        system("cls");
                        goto poczatek;
                    }
                    else
                    cout<<a3<<" / " <<b3<< " = " <<(a3/b3)<<" + "<<a3 % b3<< "/"<<a3<<endl;
                    system("pause");
                    system("cls");
                    goto poczatek;

                }
                else
                    cout<<"NIE DZIELIMY PRZEZ ZERO"<<endl;
                    system("pause");
                    system("cls");
                    goto poczatek;


            }
            if (opcja_wybrana==4) // mnożenie
            {
                int a4;
                int b4;
                cout<<"Podaj wartosc a = ";
                cin>>a4;
                cout<<"Podaj wartosc b = ";
                cin>> b4;
                cout<<a4<<" * "<<b4<<" = "<<a4*b4<<endl;
                system("pause");
                system("cls");
                goto poczatek;
            }
        }
        else
        {
            ask_me:
            cout<<"WRONG KEY NO OPTION"<<endl;
            cout<<"DO YOU WANT TO TRY AGAIN?"<<endl;
            string tak_nie;
            cout<<"Y/N"<<endl;
            cin>>tak_nie;
            if ((tak_nie=="Y") || (tak_nie=="y"))
            {
                system("cls");
                goto poczatek;
            }
            if ((tak_nie=="n") || (tak_nie=="N"))
            {
                system(EXIT_SUCCESS);
            }
            else
            {
                system("cls");
                goto ask_me;

            }

        }

return 0;
}
