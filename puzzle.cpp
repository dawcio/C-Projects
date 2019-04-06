
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cstdlib>

using namespace std;

void mieszanie(int tab[])
{ 
     for(int i=0;i<15;i++)
     { 
          int random = rand()%5 ;//srand(time(NULL))%4;//
                int buff;
             if(i<10)
             {
                buff= tab[i];
                tab[i]=tab[i+random];
                tab[i+random]=buff;
             }
             else 
             {
                buff= tab[i];
                tab[i]=tab[i-random];
                tab[i-random]=buff;
             }
     }
}

int sprawdz(int tab[])
{ 
    int sort=0;
     for(int i=0;i<14;i++)
     {
      if(tab[15]==0 && tab[i]<tab[i+1]) sort ++;
      else sort =0;
     }
     return sort;

}

int szukaj_zera(int tablica[])
     {  
        int zero;
        for (int i=0;i<16;i++)
        {
         if (tablica[i]==0) zero = i;
        }
        return zero;
     };

void w_gore(int tab[], int m_zerowe)
     {          
       if(m_zerowe>3)
       {
        int buff;
        buff= tab[m_zerowe];
        tab[m_zerowe]=tab[m_zerowe-4];
        tab[m_zerowe-4]=buff;
       }
     };
void w_dol(int tab[], int m_zerowe)
{
     if(m_zerowe<12)
     {
      int buff;
      buff= tab[m_zerowe];
      tab[m_zerowe]=tab[m_zerowe+4];
      tab[m_zerowe+4]=buff;
     }
};
void w_lewo(int tab[], int m_zerowe)
{
 if(m_zerowe>0 && (((m_zerowe)%4)!=0))
 {
  int buff;
  buff=tab[m_zerowe];
  tab[m_zerowe]=tab[m_zerowe-1];
  tab[m_zerowe-1]=buff;
  }
};
void w_prawo(int tab[], int m_zerowe)
{
 if(m_zerowe<15&&(((m_zerowe+1)%4)!=0))
 {
  int buff;
  buff= tab[m_zerowe];
  tab[m_zerowe]=tab[m_zerowe+1];
  tab[m_zerowe+1]=buff;
 }
};

void sterowanie(int sterownik, int tablica[])
{       
  if (sterownik==4)
  w_prawo(tablica,szukaj_zera(tablica));
  else if (sterownik==6)
  w_lewo(tablica,szukaj_zera(tablica));
  else if (sterownik==2)
  w_gore(tablica,szukaj_zera(tablica));
  else if (sterownik==8)
  w_dol(tablica,szukaj_zera(tablica));
}

int main ()
{   
  int tablica[16];
  int sterownik;
  for (int i=0; i<16 ; i++)
  {
        tablica[i]=i;
  }

    cout << " Ukladanka" << endl;
    cout << " Gra polega na poukladaniu elementow tak, aby utworzyly one ciag liczb w kolejnosci rosnacej " << endl;
    cout << " Instrukcje do gry:" << endl;
    cout << " 8 - w gore" << endl;
    cout << " 4 - w lewo" << endl;
    cout << " 2 - w dol" << endl;
    cout << " 6 - w prawo" << endl;
    cout << " Milej zabawy ;) " << endl;
    /* Szablon wyœwietlania
         cout << " .-------."<< ".-------."<< ".-------."<< ".-------."<< "\n"; 
         cout << " | " << tablica[1] << "     |"<< "| " << tablica[1] << "     |"<< "| " << tablica[1] << "     |"<< "| " << tablica[1] << "     |" <<"\n"; 
         cout << " | 	 |"<< "| 	  |"<< "| 	   |"<< "|       |"<< "\n"; 
         cout << " |    " << tablica[1] << "  |"<< "|    " << tablica[1] << "  |"<< "|    " << tablica[1] << "  |"<< "|    " << tablica[1] << "  |"<< "\n"; 
         cout << " ,-------,"<< ",-------,"<< ",-------,"<< ",-------,"<< "\n";
      */ 
         
    mieszanie(tablica); // komentarz - tablica niezmieszana
    int a;
    while(true)
    {
   /* for (int i=0; i<16 ; i++) // wyœwietlanie "cyfrowe"
        {
        cout << tablica[i] << "\t";
      
        if(((i+1)%4)==0)
            {
               cout <<endl;
            }

          }*/
          
          a=szukaj_zera(tablica);
      for(int i=0;i<16;i++)
      { 
              if(i%4==0)
              {
                   
               if( i==a)
               {
                   // pierwszy pusty
         cout << "          "<< ".-------."<< ".-------."<< ".-------."<< "\n"; 
         cout << "          "<< "| " << tablica[i+1] << "\t  |"<< "| " << tablica[i+2] << "\t   |"<< "|" << tablica[i+3] << "\t    | \n"; 
         cout << "          "<< "| 	  |"<< "| 	   |"<< "|       |"<< "\n"; 
         cout << "          "<< "|     "  << tablica[i+1]; if(tablica[i+1]<10){cout << " ";} cout << "|"<< "| \t"  << tablica[i+2]; if(tablica[i+2]<10){cout << " ";}  cout <<" |"<< "| \t  "  << tablica[i+3]; if(tablica[i+3]<10){cout << " ";} cout << "|\n"; 
         cout << "          "<< ",-------,"<< ",-------,"<< ",-------,"<< "\n";
         }
         else  if( i+1==a) 
         { //drugi pusty
         cout << " .-------."<< "         "<< ".-------."<< ".-------."<< "\n"; 
         cout << "| " << tablica[i] << "\t |"<< "         "<< "| " << tablica[i+2] << "\t   |"<< "|" << tablica[i+3] << "\t    | \n"; 
         cout << "| 	 |"<< "         "<< "| 	   |"<< "|       |"<< "\n"; 
         cout << "|    " << tablica[i] << "\t |"<<"         "<< "| \t"  << tablica[i+2]; if(tablica[i+2]<10){cout << " ";} cout << " |"<< "| \t  "  << tablica[i+3] ; if(tablica[i+3]<10){cout << " ";} cout<< "|\n"; 
         cout << " ,-------,"<< "         "<< ",-------,"<< ",-------,"<< "\n";
         }
         else  if( i+2==a)  
         { //trzeci pusty
         cout << " .-------."<< ".-------."<< "         "<< ".-------."<< "\n"; 
         cout << "| " << tablica[i] << "\t |"<< "| " << tablica[i+1] << "\t  |"<< "         "<< "|" << tablica[i+3] << "\t    | \n"; 
         cout << "| 	 |"<< "| 	  |"<< "         "<< "|       |"<< "\n"; 
         cout << "|    " << tablica[i] << "\t |"<< "|    "  << tablica[i+1]; if(tablica[i+1]<10){cout << " ";} cout << " |"<< "         "<< "| \t  "  << tablica[i+3]; if(tablica[i+3]<10){cout << " ";} cout << "|\n"; 
         cout << " ,-------,"<< ",-------,"<< "         "<< ",-------,"<< "\n"; 
         }
              
         else    if( i+3==a)  
         {//czwarty pusty
                   
         cout << " .-------."<< ".-------."<< ".-------."<<  "\n"; 
         cout << "| " << tablica[i] << "\t |"<< "| " << tablica[i+1] << "\t  |"<< "| " << tablica[i+2] << "\t   |"<<" \n"; 
         cout << "| 	 |"<< "| 	  |"<< "| 	   |"<< "\n"; 
         cout << "|    " << tablica[i] << "\t |"<< "|    "  << tablica[i+1]; if(tablica[i+1]<10){cout << " ";} cout << " |"<< "| \t"  << tablica[i+2]; if(tablica[i+2]<10){cout << " ";} cout << " |" << "\n"; 
         cout << " ,-------,"<< ",-------,"<< ",-------,"<< "\n"; 
         }
                   
                   
                   
         else 
         {         
                   //wszystkie pe³ne
         cout << " .-------."<< ".-------."<< ".-------."<< ".-------."<< "\n"; 
         cout << "| " << tablica[i] << "\t |"<< "| " << tablica[i+1] << "\t  |"<< "| " << tablica[i+2] << "\t   |"<< "|" << tablica[i+3] << "\t    | \n"; 
         cout << "| 	 |"<< "| 	  |"<< "| 	   |"<< "|       |"<< "\n"; 
         cout << "|    " << tablica[i] << "\t |"<< "|    "  << tablica[i+1] ; if(tablica[i+1]<10){cout << " ";} cout << " |"<< "| \t"  << tablica[i+2]; if(tablica[i+2]<10){cout << " ";} cout << " |"<< "| \t  "  << tablica[i+3] ; if(tablica[i+3]<10){cout << " ";} cout << "|\n"; 
         cout << " ,-------,"<< ",-------,"<< ",-------,"<< ",-------,"<< "\n";
         }
         }
      }    
          
    
    if(sprawdz(tablica)==14) break;
    cin >> sterownik;
    sterowanie(sterownik, tablica);

    system("cls");
    }
    cout<< "Udalo ci sie ulozyc puzzle! Gratulacje! :)";
    cout <<endl;
    system ("pause");
    return 0;
}

