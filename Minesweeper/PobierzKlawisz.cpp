
#include "funkcjesaper.hpp"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
using namespace std;
int PobierzKlawisz()
{
 	int klawisz, klawisz1;
 	klawisz = getch();
 	if(klawisz == 224) klawisz1 = getch(); 
 	else klawisz1 = klawisz;
 	return klawisz1;
}
