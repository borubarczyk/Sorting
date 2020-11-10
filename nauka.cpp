#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <string>

using namespace std;

int main ()

{
    /*int los;
    srand(time(NULL));
    for (int x=0 ; x<10 ; x++)
    {
    cout<<rand()<<endl;
    Sleep(500);
    if(kbhit()==1)
        {
            if (getch()==27)
            {goto end_end;}
        }
    }
    end_end:
        return 0;
        */

        cout<<"Po podaniu string getchar(); wyrzuca nam pierwszy znak z ciagu przy stosowaniu string przy int wartoœæ w ascii code"<<endl;
        int co_wpisane;
        co_wpisane=_getchar();
        cout<<co_wpisane<<'\n';
        cout<<"wypisanie wiecej niz jednego nzaku powoduje pobranie go do stringu nastepnej"<<endl;
        cout<<" funkcji poniewaz getchar bierze tylko jeden zank "<<endl;
        cout<<"String to string to ciag znakow"<<endl;
        cin.ignore(256, '\n');
        string nazwa;
        cin>>nazwa;
        cout<<nazwa<<endl;


    HANDLE hOut;

    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    cout << "Standart" << endl << endl;

    SetConsoleTextAttribute( hOut, BACKGROUND_RED );
    cout << "This text is red." << flush << endl << endl;

    SetConsoleTextAttribute( hOut, FOREGROUND_GREEN );
    cout << "This text is green." << endl << endl;

    SetConsoleTextAttribute( hOut, FOREGROUND_BLUE );
    cout << "This text is blue." << endl << endl;

    system( "PAUSE" );

}
