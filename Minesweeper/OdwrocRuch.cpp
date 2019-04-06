
#include "funkcjesaper.hpp"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
using namespace std;

void OdwrocRuch()
{
if(OstatniRuch=="Gora") {Dol(); ProbaWGore[pozycjax][pozycjay]=true;}
if(OstatniRuch=="Dol" and MartwePole(pozycjax, pozycjay-1)==false) {Gora(); ProbaWDol[pozycjax][pozycjay]=true;}
if(OstatniRuch=="Prawo") {Lewo(); ProbaWLewo[pozycjax][pozycjay]=true;}
if(OstatniRuch=="Lewo" and MartwePole(pozycjax+1, pozycjay)==false) {Prawo(); ProbaWPrawo[pozycjax][pozycjay]=true;}
}
