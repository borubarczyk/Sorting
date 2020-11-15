#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <fstream>
using namespace std;


int main ()

{
int ile,ile_tab;
cin>>ile;
int tablica[ile];
ile_tab=ile-1;
srand(time(NULL));
for (int x=0;x<=ile_tab;x++)
{
    tablica[x]=rand();
    //cout<<tablica[x]<<endl;
}
int z=0,y=0,c=0,liczby[z][y],iles[c];
liczby [0][0]=tablica[0];
for (int x=1;x<=ile_tab;x++)
{
if (tablica[x]>=liczby[z][y])
{
    y++;
    liczby[z][y]=tablica[x];
    cout<<z<<"x"<<y<<" "<<liczby[z][y]<<endl;
}
else
{
    iles[c]=y;
    c++;
    z++,y=0;
    liczby[z][y]=tablica[x];
    cout<<z<<"x"<<y<<" "<<liczby[z][y]<<endl;
}
}





    return 0;
}
