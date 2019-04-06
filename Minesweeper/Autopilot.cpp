
#include "funkcjesaper.hpp"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
using namespace std;

void Autopilot()
{
if(MartwePole(pozycjax, pozycjay)==true) {OdwrocRuch();}

else
{
if(ProbaWDol[pozycjax][pozycjay]==false and OstatniRuch!="Gora")
{
ProbaWDol[pozycjax][pozycjay]=true;
if(miny[pozycjax][pozycjay+1]!="@" and pozycjay!=12) {Dol();}
}
else
{	
    if(ProbaWPrawo[pozycjax][pozycjay]==false and OstatniRuch!="Lewo")
	{
	ProbaWPrawo[pozycjax][pozycjay]=true;
	if(miny[pozycjax+1][pozycjay]!="@" and pozycjax!=12 and OstatniRuch!="Lewo") {Prawo();}
	}
	else
	{
		if(ProbaWGore[pozycjax][pozycjay]==false and OstatniRuch!="Dol")
		{
		ProbaWGore[pozycjax][pozycjay]=true;
		if(miny[pozycjax][pozycjay-1]!="@" and pozycjay!=1) {Gora();}
		}
		else
		{
			if(ProbaWLewo[pozycjax][pozycjay]==false and OstatniRuch!="Prawo")
			{
			ProbaWLewo[pozycjax][pozycjay]=true;
			if(miny[pozycjax-1][pozycjay]!="@" and pozycjax!=1) {Lewo();}
			}
			else
				{
				Niemozliwa();
				}
		}
	}
}
Sleep(20);
}
}
