
#include "funkcjesaper.hpp"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
using namespace std;

void SprawdzPlansze()
{
     if(MartwePole(1,1) == true) {niemozliwa=true; end=true;}
     while(niemozliwa==0 and (pozycjax!=12 or pozycjay!=12))
     {
     system("cls");
     WyswietlMiny();
     Autopilot();
     }
}
