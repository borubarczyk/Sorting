#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    int correct_pin=1234;
    int pin, wybor, opcja;
    unsigned long long int ile_pieniedzy, wplata, ile_mam = 4256;
    int ile_razy=0;

    podaj_pin:

    cout<<" [ ! ] PODAJ PIN [ ! ] "<<endl;
    steady_clock::time_point starting = steady_clock::now();
    cin>>pin;
    if (pin==correct_pin)
           {
                system("cls");
                    cout<<" [ 0 ] PIN JEST PRAWIDLOWY ! "<<endl;
                    wroc_meni:
                    cout<<" [ 1 ] ZMIANA PINU"<<endl;
                    cout<<" [ 2 ] WYPLAC PIENIADZE"<<endl;
                    cout<<" [ 3 ] WPLAC PIENIADZE"<<endl;
                    cout<<" [ 4 ] ILE MAM "<<endl;
                    cout<<" [ 5 ] ZAKONCZ "<<endl;
                    cin>>wybor;
                switch (wybor)
                        {
                                        case 1 :
                                            system("cls");
                                            cout<<" [ 0 ] ZMIANA PINU"<<endl;
                                            cout<<" [ 1 ] PODAJ NOWY PIN : " ;cin>>correct_pin;
                                            Sleep(500);
                                            system("cls");
                                            cout<<" [ 0 ] PIN ZOSTAL ZMIENIONY"<<endl;
                                            ile_razy==0;
                                            Sleep(500);
                                            system("cls");
                                            goto podaj_pin;
                                            break;
                                        case 2:
                                            wyplac_pieniadze:
                                            system("cls");
                                            cout<<" [ 0 ] WYPLAC PIENIADZE"<<endl;
                                            cout<<" [ 1 ] ILE CHCESZ WYPLACIC ? : " ;cin>>ile_pieniedzy;
                                             if (ile_pieniedzy < 18446744073709551615)
                                             {
                                                if (ile_pieniedzy > ile_mam )
                                                        {
                                                            system("cls");
                                                            cout<<" [ 0 ] !!! UWAGA !!! "<<endl;
                                                            cout<<" [ 1 ] NIE MOZNA WYPLACIC WIECEJ NIZ DOSTEPNE SRODKI !"<<endl;
                                                            cout<<" [ 2 ] WYBIERZ INNA KWOTE"<<endl;
                                                            Sleep(2000);
                                                            goto wyplac_pieniadze;
                                                        }
                                                if (ile_pieniedzy < ile_mam )
                                                        {
                                                            ile_mam=ile_mam-ile_pieniedzy;
                                                            cout<<"  WYPLACONO :"<<ile_pieniedzy<<" PLN "<<endl;
                                                            cout<<"  POZOSTALO :"<<ile_mam<<" PLN "<<endl;
                                                            Sleep(2000);
                                                            system("cls");
                                                            goto wroc_meni;
                                                        }
                                             }
                                             else
                                             {
                                                        cout<<" [ 0 ] PRZEPRASZAMY ALE WARTOSC JEST NIEPRAWIDLOWA"<<endl;
                                                        cout<<" [ 1 ] WRACAM DO GLOWNEGO MENU"<<endl;
                                                        Sleep(2000);
                                                        system("cls");
                                                        goto wroc_meni;
                                            }
                                        break;
                                        case 3:
                                            system("cls");
                                            cout<<" [ 0 ] WPLAC PIENIADZE"<<endl;
                                            cout<<" [ 1 ] ILE CHCESZ WPLACIC: "; cin>>wplata;
                                            if (wplata < 18446744073709551615)
                                                {
                                            ile_mam=wplata+ile_mam;
                                            cout<<""<<endl;
                                            cout<<" [ 2 ] TWOJ STAN KONTA ZWIEKSZL SIE ON O : "<<wplata<< " PLN"<<endl;
                                            cout<<" [ 3 ] WYNOSI TERAZ : "<<ile_mam<<" PLN"<<endl;
                                            Sleep(2000);
                                            system("cls");
                                            goto wroc_meni;
                                                }
                                                else
                                                    {
                                                        cout<<" [ 0 ] PRZEPRASZAMY ALE WARTOSC JEST NIEPRAWIDLOWA"<<endl;
                                                        cout<<" [ 1 ] WRACAM DO GLOWNEGO MENU"<<endl;
                                                        Sleep(2000);
                                                        system("cls");
                                                        goto wroc_meni;
                                                    }
                                            break;
                                        case 4:
                                            system("cls");
                                            cout<<" [ 0 ] ILE MAM ?"<<endl;
                                            cout<<" [ 1 ] POSIADASZ : "<<ile_mam<<" PLN"<<endl;
                                            Sleep(2000);
                                            system("cls");
                                            goto wroc_meni;
                                            break;
                                        case 5:
                                            system("cls");
                                            cout<<" [ 0 ] DO WIDZENIA"<<endl;
                                            Sleep(500);
                                            goto koniec;
                                            break;
                                        default :
                                            system("cls");
                                            cout<<" ERROR WRONG KEY ! " <<endl;
                                            goto wroc_meni;
                                        }
        }
        else
            {
                    ile_razy++;
                    system("cls");
                    cout<<"PIN NIEPRAWIDLOWY"<<endl;
                    cout<<"TRY AGAIN"<<endl;
                    system("pause");
                    system("cls");
                    if (ile_razy<3)
                    {
                        goto podaj_pin;
                        system("cls");
                    }
                    else
                    {
                        cout<<"PODALES PIN 3 RAZY NIEPRAWIDlOWO"<<endl;
                        cout<<"KARTA ZABLOKOWANA"<<"\a"<<endl;
                        Sleep(1000);
                        goto koniec;
                    }
        }
    koniec:
    steady_clock::time_point ending = steady_clock::now();
    duration <double> durat = duration_cast<duration<double>>( ending - starting );
    system("cls");
    cout<< "" <<endl;
    cout<< "" <<endl;
    cout<<"[ 0 ] ZAJELO TOBIE TO : " << durat.count() << " SEKUND" <<endl;
    cout<< "" <<endl;
    cout<< "" <<endl;
    Sleep(3000);
return 0;
}
