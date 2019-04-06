
#include "funkcjesaper.hpp"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
using namespace std;

void WykonajRuch()
{
b = PobierzKlawisz();
if(b == 80) Dol();
if(b == 72) Gora();
if(b == 75) Lewo();
if(b == 77) Prawo();
if(b == 98) cheat=!cheat;
if(b == 27) end = true;
if(b == 97) SprawdzPlansze();
}
