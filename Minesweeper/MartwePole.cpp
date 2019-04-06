
#include "funkcjesaper.hpp"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
using namespace std;

bool MartwePole(int pozycjax, int pozycjay)
{
m=0; 
if(miny[pozycjax+1][pozycjay]=="@" or pozycjax==12) m++;
if(miny[pozycjax-1][pozycjay]=="@" or pozycjax==1) m++;
if(miny[pozycjax][pozycjay+1]=="@" or pozycjay==12) m++;
if(miny[pozycjax][pozycjay-1]=="@" or pozycjay==1) m++;
if((pozycjax==1 and pozycjay==1) or (pozycjax==1 and pozycjay==12) or (pozycjax==12 and pozycjay==1)) m--;
if(m>=3) {return true;}
if(m<3) return false;
}
