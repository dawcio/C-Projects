
#include "stdafx.h" 
#include <stdlib.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include "vector"
#include <string>
using namespace std;


int main()
{

	vector<char> znaki;
	vector<int> liczniki;
	string nazwa;
	double dlugosc;
	char * tablica;
	tablica = new char;
	ofstream output;
	ifstream bufor;
	int tryb = 0;

	cout << "Kompresja (1) czy dekompresja (2)?";
	cin >> tryb;

	if (tryb == 1)
	{		

		cout << endl << "Wybrales kompresje!";
		cout << endl;
		cout << "Podaj nazwe pliku: ";
		cin >> nazwa;


		const string nzw = nazwa; 
		bufor.open(nzw, ifstream::binary); 

		if (bufor) {
			cout << "Plik wczytany poprawnie" << endl << "Wynik kompresji:" << endl; 
			output.open(nazwa.append(".rlc"), ofstream::binary);
			
			bufor.seekg(0, ios::end);
			dlugosc = bufor.tellg();
			bufor.seekg(0, ios::beg);

			
			int licznik = 1;
			char znak;
			char znak2;
			
			for (int i = 1; i < dlugosc; i++)
			{   
				bufor.seekg(i - 1);
				bufor.read(tablica, 1);
				znak = *tablica;
				bufor.seekg(i);
				bufor.read(tablica, 1);
				znak2 = *tablica;
				
				if (znak == znak2)
				{
					licznik++; 
				}
				else
				{ 
					znaki.push_back(znak);
					liczniki.push_back(licznik);
					licznik = 1; 
				}

			}
			
			for (int j = 0; j < znaki.size(); j++)
			{
				if (liczniki[j] > 1)
				{
					cout << liczniki[j];
					output << liczniki[j];
				}

				cout << znaki[j];
				output << znaki[j];

			}

		}
		else { cout << "Blad odczytu pliku." << endl; }

	}

	else if (tryb == 2) 
	{
		cout << endl << "Wybrales dekompresje!" << endl;
		cout << "Podaj nazwe pliku: ";
		cin >> nazwa;
		
		const string nzw = nazwa;
		bufor.open(nazwa, ifstream::binary);
		if (bufor) {
			cout << "Plik wczytany poprawnie" << endl << "Wynik dekompresji:" << endl;
			nazwa.erase(nazwa.end() - 4, nazwa.end());
			output.open(nazwa);


			
			bufor.seekg(0, ios::end);
			dlugosc = bufor.tellg();
			bufor.seekg(0, ios::beg);

			string liczba_str; 
			liczba_str.clear(); 

			for (int i = 0; i < dlugosc; i++)
			{  				
				bufor.seekg(i);
				bufor.read(tablica, 1);
				int znak_liczba = *tablica; 
				

				if (znak_liczba > 47 && znak_liczba < 58) 
				{
					char znak = *tablica; 
				
					liczba_str.append(1, znak);
					
				}
				else
				{
					int l = 0;
					l = atoi(liczba_str.c_str()); 

					
					if (l > 1) 
					{
						for (int k = 0; k < l; k++)
						{
							output << *tablica;
							cout << *tablica;
						}
					}
					else
						output << *tablica; 
					cout << *tablica;
					liczba_str.clear(); 
				}

			}
		}
		else { cout << "Blad odczytu pliku." << endl; }

	}

	else { cout << "Cos chyba nie gra..."; }

	cout << endl;
	bufor.close();  
	output.close();
	system("Pause");
	return 0;
}

