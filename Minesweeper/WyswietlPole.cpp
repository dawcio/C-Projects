
#include "funkcjesaper.hpp"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
using namespace std;

void WyswietlPole()
{
for(a = 0; a<=13; a++) 
{
      
 		for(c = 0; c<=13; c++)
 		{
	  	if(a == 0 or a == 13) 
	  	{cout<<"#";
	  	if(c == 13) cout<<endl;
		}
	  	else
	  	{
		if(c == pozycjax and a==pozycjay){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); cout<<"X";SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);}
		else
		{
            
 		if(c == 0 or c == 13) cout<<"#";
 		if (c==12 and a==12) cout<<"+";
 		if(c>0 and c<13 and pole[a][c] == '\0' and (c!=12 or a!=12)) cout<<" ";
 		if(c>0 and c<13 and pole[a][c] == 9) cout<<"0";
 		if(c>0 and c<13 and pole[a][c] != '\0' and pole[a][c] != 9) cout<<pole[a][c];
 		if(c==13) {cout/*<<"   "<<a*/<<endl;}                                                      //numery wierszy
		}
		}
 		}
}
}
