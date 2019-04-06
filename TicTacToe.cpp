#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
using namespace std;
int a,b,c,d,e,f,m,licznik = 0, opcja, pozycjax=1, pozycjay=1;
bool wygranaX = false, wygranaO = false, remis = false;

class klasa
{
public:
char wartosc;
};

klasa pole[5][5];

void Lewo()
{
if(pozycjax>1) pozycjax--; 
}

void Prawo()
{
if(pozycjax<3) pozycjax++;
}

void Dol()
{
if(pozycjay<3) pozycjay++;
}

void Gora()
{
if(pozycjay>1) pozycjay--;
}



int PobierzKlawisz()
{
 	int klawisz, klawisz1;
 	klawisz = getch();
 	if(klawisz == 224) klawisz1 = getch();
 	else klawisz1 = klawisz;
 	return klawisz1;
}

void Zaznacz()
{
if(pole[pozycjay][pozycjax].wartosc != 0) {cout<<"To pole jest juz zajete!"<<endl; Sleep(1000);} 
if(licznik%2 != 0 and pole[pozycjay][pozycjax].wartosc == 0) {pole[pozycjay][pozycjax].wartosc = 1; licznik++;}
if(licznik%2 == 0 and pole[pozycjay][pozycjax].wartosc == 0) {pole[pozycjay][pozycjax].wartosc = 2; licznik++;}

}

void WykonajRuch()
{
b = PobierzKlawisz();
if(b == 80) Dol();
if(b == 72) Gora();
if(b == 75) Lewo();
if(b == 77) Prawo();
if(b == 13) Zaznacz();
}




void WyswietlPole()
{
for(a = 0; a<=4; a++) 
{
 		for(c = 0; c<=4; c++)
 		{
	  	if(a == 0 or a == 4) 
	  	{cout<<"#";
	  	if(c == 4) cout<<endl;
		}
	  	else
	  	{
        if(a==pozycjay and c==pozycjax and remis==false) {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); cout<<"*";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);}
        else
        {
        if(pole[a][c].wartosc == 1) {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); cout<<"X";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);}
        if(pole[a][c].wartosc == 2) {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); cout<<"O";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);}
		else
		{    
 		if(c == 0 or c == 4) cout<<"#";
 		if(c>0 and c<4 and pole[a][c].wartosc == 0) cout<<" ";
 		if(c==4) {cout<<endl;}                                                      
		}
    }
		}
 		}
}
}



void WyczyscPole()
{	
for(int s = 0; s<4; s++)
{
 		for(int q = 1; q<4; q++) 
 		{
       		pole[s][q].wartosc = 0;
		}
}
}


void SprawdzWygrana()
{
//sprawdza wygran¹ dla xów
if(pole[1][1].wartosc==1 and pole[1][2].wartosc==1 and pole[1][3].wartosc==1) wygranaX=true;
if(pole[2][1].wartosc==1 and pole[2][2].wartosc==1 and pole[2][3].wartosc==1) wygranaX=true;
if(pole[3][1].wartosc==1 and pole[3][2].wartosc==1 and pole[3][3].wartosc==1) wygranaX=true;
if(pole[1][1].wartosc==1 and pole[2][1].wartosc==1 and pole[3][1].wartosc==1) wygranaX=true;
if(pole[1][2].wartosc==1 and pole[2][2].wartosc==1 and pole[3][2].wartosc==1) wygranaX=true;
if(pole[1][3].wartosc==1 and pole[2][3].wartosc==1 and pole[3][3].wartosc==1) wygranaX=true;
if(pole[1][1].wartosc==1 and pole[2][2].wartosc==1 and pole[3][3].wartosc==1) wygranaX=true;
if(pole[1][3].wartosc==1 and pole[2][2].wartosc==1 and pole[3][1].wartosc==1) wygranaX=true;
//sprawdza wygran¹ dla O
if(pole[1][1].wartosc==2 and pole[1][2].wartosc==2 and pole[1][3].wartosc==2) wygranaO=true;
if(pole[2][1].wartosc==2 and pole[2][2].wartosc==2 and pole[2][3].wartosc==2) wygranaO=true;
if(pole[3][1].wartosc==2 and pole[3][2].wartosc==2 and pole[3][3].wartosc==2) wygranaO=true;
if(pole[1][1].wartosc==2 and pole[2][1].wartosc==2 and pole[3][1].wartosc==2) wygranaO=true;
if(pole[1][2].wartosc==2 and pole[2][2].wartosc==2 and pole[3][2].wartosc==2) wygranaO=true;
if(pole[1][3].wartosc==2 and pole[2][3].wartosc==2 and pole[3][3].wartosc==2) wygranaO=true;
if(pole[1][1].wartosc==2 and pole[2][2].wartosc==2 and pole[3][3].wartosc==2) wygranaO=true;
if(pole[1][3].wartosc==2 and pole[2][2].wartosc==2 and pole[3][1].wartosc==2) wygranaO=true;
}

void Gra()
{
WyczyscPole();
      while(wygranaX == false and wygranaO == false and remis == false)
{
    system("cls");
    WyswietlPole();
    cout<<"Ruch: ";
    if(licznik%2 == 1) {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); cout<<"X"<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);}
    if(licznik%2 == 0) {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); cout<<"O"<<endl;SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);}	
    WykonajRuch(); 
    SprawdzWygrana();
    if(licznik == 9 and wygranaX == false and wygranaO == false) remis = true;
}
system("cls");
WyswietlPole();
cout<<endl<<endl;
if(wygranaX == true) cout<<"WYGRAL KRZYZYK!!!!"<<endl;
if(wygranaO == true) cout<<"WYGRALO KOLKO!!!!"<<endl;
if(remis == true and wygranaX == false and wygranaO == false) cout<<"REMIS!!!!"<<endl;
cout<<endl<<"1. Zagraj ponownie"<<endl<<"2. Wyjdz"<<endl;
cin>>opcja;
if(opcja == 1){system("cls"); wygranaX = false; wygranaO = false; remis = false; licznik = 0; Gra();};
}

int main()
{
    while(1)
    {
    system("cls");
    cout<<"Gra kolko i krzyzyk"<<endl<<endl;
    cout<<"$$$  MENU  $$$"<<endl<<endl;
    cout<<"1. Nowa Gra"<<endl;
    cout<<"2. Wyjdz"<<endl<<endl;
    cout<<"Wybierz opcje:  ";
    cin>>opcja;

    if(opcja==1) Gra();
    if(opcja==2){system("cls"); system("PAUSE"); return EXIT_SUCCESS;}
}
}

