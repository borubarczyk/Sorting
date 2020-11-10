#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string>

using namespace std;

void start()
{
    for (short int d=5; d>=0;d--)
    {   system("cls");
        cout<<"[] Program counts diviners []"<<endl;
        cout<<"[] Program starts where you ended []"<<endl;
        cout<<"[] Program starts in: "<<d<<" []"<<flush<<endl;
        Sleep(800);}
}

int main ()

{
    starting:
    unsigned long long int x,y;
    int c;
    string line,new_line;
    fstream dane, valeu;
    start();
    valeu.open("last_val.txt", ios::in | ios::out | ios::app);
    dane.open( "dane_dane.txt", ios::out | ios::app );
    if (dane.is_open()&&valeu.is_open())
    {
        getline(valeu,line);
        if (line.empty())
        {
        valeu.clear();
        valeu.seekp(0,ios::end);
        cout<<line.length()<<" bytes length"<<endl;
        cout<<"Val.txt is empty !"<<endl;
        cout<<"State of file (good): ["<<valeu.good()<<"] zero is bad one is good"<<endl;
        cout<<"State of file (eof): ["<<valeu.eof()<<"] zero is good one is bad"<<endl;
        cout<<"State of file (fail): ["<<valeu.fail()<<"] zero is good one is bad"<<endl;
        cout<<"State of file (bad): ["<<valeu.bad()<<"] zero is bad one is good"<<endl;
        cout<<"Going to give zero"<<endl;
        valeu<<"0";
        valeu.clear();
        valeu.seekp(ios::beg);
        getline(valeu,new_line);
        cout<<"File looks like this:| "<<new_line<<" |"<<'\n';
        cout<<"Going to start again"<<endl;
        Sleep(3000);
        valeu.close();
        goto starting;
        }
        else
        {
        x = stoi(line);
        x++;
        valeu.close();
        cout<<'\n';
        cout<<"Counting from number: "<<x<<'\n';
        cout<<"Press SPACE to see progress, ESC to end program."<<'\n';
        cout<<"Press DEL to zero the calculations"<<'\n';
        }

    for (x;;x++)
    {
        c=1;
        dane<<"["<<x<<"]: [1]";
        for (y=2;y<=x;y++)
        {if (x%y==0)
            {dane<<"["<<y<<"]";c++;}
        }
        dane<<" : Ilosc dzielnikow: "<<c<<'\t'<<"["<<x<<"]"<<'\n';
        if (_kbhit()==1)
        {
        switch (getch())
        {
        case 27:
        valeu.open("last_val.txt", ios::trunc | ios::out );
        if (valeu.good()==true)
        {
            valeu<<x<<'\n';
            wybor_goto:
            cout<<"Program finished on number: "<<x<<'\n';
            cout<<"Are you sure you finished ? Y/N"<<'\n';
            char wybor;
            cin>>wybor;
                if (wybor=='Y'||wybor=='y')
                {
                    goto endling;
                }
                if (wybor=='N'||wybor=='n')
                {
                    goto starting;
                }
                else
                {
                    cout<<"Wrong key!"<<endl;
                    goto wybor_goto;
                }

        }
        else
        {cout<<"Cant open a file !"<<endl;}
        break;
        case 32:
        cout<<"Program is on number: "<<x<<'\n';
        break;
        case 224:
        wybor_goto_2:
        cout<<"Are you sure ?"<<'\n';
        cout<<"Do you want DELETE all calculations Y/N"<<'\n';
        char wybo;
        cin>>wybo;
                if (wybo=='Y'||wybo=='y')
                {
                dane.close();
                valeu.open("last_val.txt", ios::trunc | ios::out );
                dane.open("dane_dane.txt", ios::trunc | ios::out );
                if (valeu.is_open()&&dane.is_open())
                {
                cout<<"Program will start from "<<0<<'\n';
                cout<<"And data was deleted from data_data.txt"<<'\n';
                Sleep(3000);
                dane.close();
                valeu.close();
                goto starting;
                }
                else
                {
                    cout<<"Can't open a files !"<<endl;
                    Sleep(3000);
                }
                }
                if (wybo=='N'||wybo=='n')
                {
                    cout<<"Ok let's go back to work :)"<<'\n';
                }
                else
                {
                    cout<<"Wrong key!"<<endl;
                    goto wybor_goto_2;
                }
                break;}}}
    }
    else
    {cout<<"Cant open a file !"<<endl;}
    endling:
    dane.close();
    return 0;
}
