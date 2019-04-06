
#include "funkcjesaper.hpp"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
using namespace std;

void Gra()
{
while(end==false)
{
system("cls");
cout<<"Dojdz do punktu w prawym dolnym rogu omijajac miny."<<endl<<"Nacisnij ESC aby wyjsc z gry."<<endl;
cout<<"Nacisnij a aby sprawdzic czy plansza jest mozliwa do przejscia."<<endl<<endl;
if(cheat==false)WyswietlPole();
if(cheat==true)WyswietlMiny();
d = IloscMinWPoblizu(pozycjax, pozycjay);
cout<<"PozycjaX: "<<pozycjax<<", PozycjaY: "<<pozycjay<<endl;
cout<<"Ilosc min w poblizu: "<<d<<endl;
if(d!=0) pole[pozycjay][pozycjax] = d;
else pole[pozycjay][pozycjax] = 9;
WykonajRuch();
if(miny[pozycjax][pozycjay]=="@") {dead=true; end=true;}
if(pozycjax == 12 and pozycjay==12) end=true;
}
system("cls");
if(niemozliwa==1) cout<<"Wylosowano plansze niemozliwa do przejscia."<<endl;
if(pozycjax==12 and pozycjay==12) cout<<"Wygrana!"<<endl;
if(dead == true) cout<<"Zginales!"<<endl;
system("pause");
}
