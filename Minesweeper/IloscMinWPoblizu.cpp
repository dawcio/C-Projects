
#include "funkcjesaper.hpp"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
using namespace std;

int IloscMinWPoblizu(int pozycjax, int pozycjay)
{
m=0;
if(miny[pozycjax+1][pozycjay]=="@") m++;    
if(miny[pozycjax-1][pozycjay]=="@") m++;  
if(miny[pozycjax][pozycjay+1]=="@") m++;  
if(miny[pozycjax][pozycjay-1]=="@") m++;  
if(miny[pozycjax+1][pozycjay+1]=="@") m++;  
if(miny[pozycjax+1][pozycjay-1]=="@") m++;  
if(miny[pozycjax-1][pozycjay+1]=="@") m++;  
if(miny[pozycjax-1][pozycjay-1]=="@") m++;
return m;  
}    
