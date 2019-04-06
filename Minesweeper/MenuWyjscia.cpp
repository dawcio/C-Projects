
#include "funkcjesaper.hpp"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
using namespace std;

void MenuWyjscia()
{
system("cls");
cout<<"Nacisnij 1 by zagrac od nowa"<<endl;
cout<<"Nacisnij 2 by zagrac od nowa z ta sama liczba min"<<endl;
cout<<"Nacisnij 3 by zagrac pononie na tej samej planszy"<<endl;
cout<<"Nacisnij dowolny inny klawisz by zakonczyc"<<endl;
b = getch();
if(b<49 or b>51) wyjdz = true;
else
{
end = false;
dead = false;
niemozliwa = false;
pozycjax = 1;
pozycjay = 1;
OstatniRuch="";
WyczyscPole();
WyczyscTablice();
system("cls");
if(b == 49)                                   //1 - od nowa
{
cout<<"Podaj ilosc min do umieszczenia na planszy"<<endl;
cin>>e;
WyczyscMiny();
GenerujMiny(e);
Gra();
}
if(b == 50)                                   //2 - od nowa z ta sama liczba min
{
WyczyscMiny();
GenerujMiny(e);
}
                                            //3 - zagraj ponownie na tym samym polu
Gra();
}
}
