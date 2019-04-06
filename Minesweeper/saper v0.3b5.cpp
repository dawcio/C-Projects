

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <funkcjesaper.hpp>
using namespace std;
int a,b,c,d,e,f,m;
bool wyjdz=false, dead=false, end=false, niemozliwa=false, cheat=false;
int pole[14][14];
bool ProbaWPrawo[14][14];
bool ProbaWDol[14][14];
bool ProbaWGore[14][14];
bool ProbaWLewo[14][14];
string miny[14][14];
string OstatniRuch;
int g=0;
int pozycjax = 1;                           //pozycja startowa
int pozycjay = 1;
char znak;
     

void Lewo()
{
if(pozycjax>1) pozycjax--; 
OstatniRuch = "Lewo";
}

void Prawo()
{
if(pozycjax<12) pozycjax++;
OstatniRuch = "Prawo";
}

void Dol()
{
if(pozycjay<12) pozycjay++;
OstatniRuch = "Dol";
}

void Gora()
{
if(pozycjay>1) pozycjay--;
OstatniRuch = "Gora";
}


int main()
{
cout<<"Podaj ilosc min do umieszczenia na planszy"<<endl;
cin>>e;
WyczyscPole();
WyczyscMiny();
WyczyscTablice();
GenerujMiny(e);
Gra();
while(wyjdz!=true)
MenuWyjscia();
return 0;
}

 		
	
