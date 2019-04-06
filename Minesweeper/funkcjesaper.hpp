
#ifndef funkcjesaper
#define funkcjesaper
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
using namespace std;
int PobierzKlawisz();
void WyswietlPole();
void InicjujWyswietlanieMin();
void GenerujMiny(int IloscMin);
void WykonajRuch();
void Autopilot();
void Gra();
int IloscMinWPoblizu(int pozycjax, int pozycjay);
bool MartwePole(int pozycjax, int pozycjay);
void MenuWyjscia();
void Niemozliwa();
void OdwrocRuch();
void SprawdzPlansze();
void WyczyscMiny();
void WyczyscPole();
void WyczyscTablice();
void WyswietlMiny();

#endif
