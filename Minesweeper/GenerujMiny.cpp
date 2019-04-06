
#include "funkcjesaper.hpp"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
using namespace std;

void GenerujMiny(int IloscMin)
{
int k,l;
srand(time(NULL));
for(a=1; a<=IloscMin; a++)
{
k = rand()%12 + 1;
l = rand()%12 + 1;
if(miny[k][l]=="@" or (k==pozycjax and l==pozycjay) or (k==12 and l==12)) a--;
else miny[k][l]="@";
}
}
