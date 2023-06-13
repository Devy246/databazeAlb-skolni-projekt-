#include "gvid.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Program databaze alb funguje jako pole s 64 prvky struktur ALBUM, 32 už jsou předem vyplněny.
V funkci main nabízí switch využití různých funkcí pro manipulaci s prvkami poli a jejími hodnotami.
*/

/*
Struktura ALBUM je entita pole listAlb, která je databáze programu. má 5 položek; 3 stringy (nazev, autor a zanr) a 2 inty (rokVydani, pocetPisni).
*/
typedef struct
{
  char nazev[40];
  char autor[50];
  char zanr[20];
  int rokVydani;
  int pocetPisni;
} ALBUM;

/*
Funkce programu a jejich podfunkce/alternativní verze jsou následující (v pořadí):
- tisk alb
- oprava alba
- filtrování listem alb
- vytvoření nového alba
- výpočet průměrného počtu písní (pro splnění zadání úkolu mít funkci pro souhrnný výpočet.)

Ve skupinách funkcí je nejníže hlavní, tu přečtěte první pro dokumentaci.
Hlavní funkce je volána v main a podfunkce jsou volány hlavní funkcí nebo i jinými funkci.
Podfunkce se mohou hodně podobat, jelikož častokrát byly okopírovány a byly změněny jen některé části.
*/



// TISK ALB + PODFUNKCE
void printAlbList(ALBUM listAlb[], int n)
{
//vypis cele databaze, for cyklus projde všechny položky
  system("cls");
  for(int i=0 ; i<n; i++)
  {
    printf("  %d:\n  ALBUM: %s\n  AUTOR: %s\n  ZANR: %s\n  P.PISNI: %d\n  R. VYDANI: %d\n\n", i, listAlb[i].nazev, listAlb[i].autor, listAlb[i].zanr, listAlb[i].pocetPisni, listAlb[i].rokVydani);
  }

}
void singlePrintAlb(ALBUM album)
{
//vypis jednoho alba v listu, předem specifikovano
  printf("\n  ALBUM: %s\n  AUTOR: %s\n  ZANR: %s\n  P.PISNI: %d\n  R. VYDANI: %d\n\n", album.nazev, album.autor, album.zanr, album.pocetPisni, album.rokVydani);
}
void printAlbMain(ALBUM databazeAlb[], int n)
{
// funkce se prve zeptá co zda chcete celou databazi nebo jen jednu věc, switch pak vybere co dělat, default skonci funkci
  int v, m;
  printf("chcete vytisknout celou databazi, nebo pouze jedno album? \n  1: pouze jedno \n  2: celou databazi \n  else: konec tisku \n  ");
  scanf(" %d", &v);
  switch(v)
  {
    case 1:
      system("cls");
      printf("zadejte album z databaze, ktere chcete vytisknout (cislo): ");
      scanf(" %d", &m);
      singlePrintAlb(databazeAlb[m]);
      break;

    case 2:
      printAlbList(databazeAlb, n);
      break;

    default:
      system("cls");
      break;
  }
}

// OPRAVA ALB + PODFUNKCE
void opravaNazvu(ALBUM listAlb[],int n)
{
//funkce nacte novy nazev a vymeni ho
  char novyNazev[50];
  printf("\nzadejte novy nazev: ");
  scanf("%s", novyNazev);
  strcpy(listAlb[n].nazev, novyNazev);
}
void opravaAutora(ALBUM listAlb[],int n)
{
  char novyAutor[50];
  printf("\nzadejte noveho autora: ");
  scanf("%s", novyAutor);
  strcpy(listAlb[n].autor, novyAutor);
}
void opravaZanru(ALBUM listAlb[],int n)
{
  char novyZanr[50];
  printf("\nzadejte novy zanr: ");
  scanf("%s", novyZanr);
  strcpy(listAlb[n].zanr, novyZanr);
}
void opravaPisni(ALBUM listAlb[],int n)
{
  int novyPisne;
  printf("\nzadejte novy pocet pisni: ");
  scanf("%d", &novyPisne);
  listAlb[n].pocetPisni = novyPisne;
}
void opravaRoku(ALBUM listAlb[],int n)
{
  int novyRok;
  printf("\nzadejte novy rok vydani: ");
  scanf("%d", &novyRok);
  listAlb[n].rokVydani = novyRok;
}
void opravaAlba(ALBUM listAlb[])
{
//program se zepta jake album chcete zmenit, vypise ho, a nabidne co chcete delat, switch pote vybere podfunkci ci skonci funkci, podfunkce jsou velice podobne, staci se kouknout na opravaNazvu.
  int n, m;
  printf("Zadejte album, ktere chcete zmenit (cislo): ");
  scanf("%d", &n);
  singlePrintAlb(listAlb[n]);
  printf("\nCo chcete zmenit? \n  1: nazev \n  2: autora \n  3: zanr \n  4: pocet pisni \n  5: rok vydani\n  else: ukoncit opravu\n  ");
  scanf("%d", &m);
  switch(m)
  {
    case 1: opravaNazvu(listAlb,n); break;
    case 2: opravaAutora(listAlb,n); break;
    case 3: opravaZanru(listAlb,n); break;
    case 4: opravaPisni(listAlb,n); break;
    case 5: opravaRoku(listAlb,n); break;
    default: printf("\n...koncim opravu sefe...\n"); break;
  }
  system("cls");
}

// FILTROVANI ALB + PODFUNKCE
void filtrNazvu(ALBUM listAlb[], int n)
{
//funkce nacte nazev kterym se chce hledat, porovna stringy, a vypise ty ktery se rovnaj
  char filtrNaz[50];
  printf("zadejte nazev, kterym chcete filtrovat: ");
  scanf(" %[^\n]", filtrNaz);
  system("cls");
  for(int i = 0; i <n; i++)
  {
    if( strcmp(listAlb[i].nazev,filtrNaz)==0 )
    {
      singlePrintAlb(listAlb[i]);
    }
  }
  printf("\n");
}
void filtrAutora(ALBUM listAlb[], int n)
{
  char filtrAut[50];
  printf("zadejte autora, kterym chcete filtrovat: ");
  scanf(" %[^\n]", filtrAut);
  system("cls");
  for(int i = 0; i <n; i++)
  {
    if( strcmp(listAlb[i].autor,filtrAut)==0 )
    {
      singlePrintAlb(listAlb[i]);
    }
  }
  printf("\n");
}
void filtrZanru(ALBUM listAlb[], int n)
{
  char filtrZan[50];
  printf("zadejte zanr, kterym chcete filtrovat: ");
  scanf(" %[^\n]", filtrZan);
  system("cls");
  for(int i = 0; i <n; i++)
  {
    if( strcmp(listAlb[i].zanr,filtrZan)==0 )
    {
      singlePrintAlb(listAlb[i]);
    }
  }
  printf("\n");
}
void filtrPP(ALBUM listAlb[], int n)
{
  int m;
  printf("zadejte pocet pisni, kterym chcete filtrovat: ");
  scanf(" %d", &m);
  system("cls");
  for(int i = 0; i <n; i++)
  {
    if( m==listAlb[i].pocetPisni)
    {
      singlePrintAlb(listAlb[i]);
    }
  }
  printf("\n");
}
void filtrRok(ALBUM listAlb[], int n)
{
  int m;
  printf("zadejte rok, kterym chcete filtrovat: ");
  scanf(" %d", &m);
  system("cls");
  for(int i = 0; i <n; i++)
  {
    if( m==listAlb[i].rokVydani)
    {
      singlePrintAlb(listAlb[i]);
    }
  }
  printf("\n");
}
void filtrAlb(ALBUM listAlb[], int n)
{
  //funkce se zepta, cim chcete filtrovat, pak vybere switch podfunkci. Podfunkce jsou si velmi podobne, staci se kouknout na filtrNazvu
  int m;
  printf("Zadejte parametr, podle ktereho chcete filtrovat alba: \n  1: nazev \n  2: autor \n  3: zanr \n  4: pocet pisni \n  5: rok vydani\n  else: ukoncit filtrovani\n  ");
  scanf("%d", &m);
  system("cls");

  switch(m)
  {
    case 1: filtrNazvu(listAlb,n); break;
    case 2: filtrAutora(listAlb,n);break;
    case 3: filtrZanru(listAlb,n);break;
    case 4: filtrPP(listAlb,n);break;
    case 5: filtrRok(listAlb,n);break;
    default: break;
  }
}

// VYTVOŘENÍ NOVÉHO ALBA
void novyAlbum(ALBUM listAlb[], int n)
{
  // funkce nacte do pole novy album pomoci printf a scanf na pozici n. n udava pocet prvku, ale jelikoz pole zacina nulou tak v poli je to prvni prazdna hodnota. pote se da n++ po volani funkce jelikoz nechapu pointery.

  // JA VIM ZE JE TO HNUSNY A NEDAVA TO SMYSL ALE POINTERY JSME SE NEUCILI A TOHLE FUNGUJE
  int pp, rok;
  char nazev[50];
  char autor[50];
  char zanr[50];

  printf("zadejte jmeno noveho alba: ");
  scanf("%s", nazev);
  printf("\nzadejte autora noveho alba: ");
  scanf("%s", autor);
  printf("\nzadejte zanr noveho alba: ");
  scanf("%s", zanr);
  printf("\nzadejte pocet pisni noveho alba: ");
  scanf("%d", &pp);
  printf("\nzadejte rok vydani noveho alba: ");
  scanf("%d", &rok);
  system("cls");

  strcpy(listAlb[n].nazev, nazev);
  strcpy(listAlb[n].autor, autor);
  strcpy(listAlb[n].zanr, zanr);
  listAlb[n].pocetPisni = pp;
  listAlb[n].rokVydani = rok;
}

// VÝPOČET PRŮMĚRNÉHO POCTU PISNI
void prumerPocPis(ALBUM listAlb[], int n)
{
  //funkce secte pocet pisni a vydeli to poctem alb, pak vypise
  //to vsechno s tim co je float a int je blbe ale musi to takhle byt aby to bylo desetinny
  float soucet = 0;
  for(int i = 0; i<n ; i++)
  {
    soucet = soucet + listAlb[i].pocetPisni;
  }
  float prumer = soucet/n;
  printf("%f\n\n", prumer);
}

// funkce Main
int main(void)
{
  /*
  použití niže definovaných funkcí je následující:
  - int konec = funguje jako rozhodnutí vypnout program. Jestli ve switchy se zapne default, p se stane 0, a do-while cyklus ve kterém je switch skončí.
  - int r  = je proměnná pro switch, který dává uživateli navýběr, které funkce chce zkusit.
  - int n = funguje jako aktuální počet entit v poli.
  - char x = char, který je použit pro vizuální šmrnc.
  */
  int konec = 0;
  int rozhodnuti;
  int n = 32;
  char x = 178;

  //pole databazeAlb je databaze projektu
  ALBUM databazeAlb[64] = {
    {"...I Care Because You Do","Aphex Twin","ambient",1995,12},
    {"Richard D. James Album","Aphex Twin","ambient",1996,10},
    {"Selected Ambient Works 85-92","Aphex Twin","ambient",1992,13},
    {"Illmatic","Nas","hiphop/rap",1994,10},
    {"History Will Absolve Me","Billy Woods","hiphop/rap",2012,18},
    {"Almighty So","Chief Keef","drill",2013,15},
    {"Finally Rich","Chief Keef","drill",2012,12},
    {"Atrocity Exhibition","Danny Brown","experimental rap",2016,15},
    {"One Day You'll See Me Again","Viper","cloud rap",2020,31},
    {"e","ECCO2K","cloud rap",2019,12},
    {"Icedancer","Bladee","cloud rap",2018,19},
    {"Crest","Bladee","cloud rap",2022,9},
    {"Good Kid M.A.A.D City","Kendrick Lamar","hiphop/rap",2012,12},
    {"To Pimp A Butterfly","Kendrick Lamar","hiphop/rap",2015,15},
    {"DAMN.","Kendrick Lamar","hiphop/rap",2017,14},
    {"Exmilitary","Death Grips","industrial",2011,13},
    {"The Money Store","Death Grips","industrial",2012,13},
    {"No Love Deep Web","Death Grips","industrial",2012,13},
    {"Year of the Snitch","Death Grips","industrial",2018,13},
    {"Graduation","Kanye West","hiphop/rap",2007,13},
    {"ye","Kanye West","hiphop/rap",2018,7},
    {"The Life of Pablo","Kanye West","hiphop/rap",2016,19},
    {"LP!","JPEGMAFIA","experimental rap",2021,20},
    {"All My Heroes Are Cornballs","JPEGMAFIA","experimental rap",2019,18},
    {"Veteran","JPEGMAFIA","experimental rap",2018,19},
    {"Born Like This","MF DOOM","hiphop/rap",2009,17},
    {"Operation Doomsday","MF DOOM","hiphop/rap",1999,19},
    {"Madvillainy","MF DOOM","hiphop/rap",2004,22},
    {"Mm.. Food","MF DOOM","hiphop/rap",2004 ,15},
    {"Playboi Carti","Playboi Carti","trap",2017,15},
    {"Die Lit","Playboi Carti","trap",2018,19},
    {"Whole Lotta Red","Playboi Carti","trap",2020,24},
  };

  do{
    // Vytisknutí informací a načtení r.
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n%c  DATABAZE ALB v0.1  %c\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x,x);
    printf("\nzadejte, co chcete delat: \n  1: zobrazit databazi alb \n  2: pridat album do databaze alb \n  3: opravit album v databazi \n  4: filtrovat databazi \n  5: zjistit prumerny pocet pisni v albech databaze \n  else: ukoncit program \n  ");
    scanf(" %d", &rozhodnuti);
    system("cls");

    // Switch, který u každého kola vymaže konzoli a začne funkci, kdyžtak změní proměnnou.
    switch(rozhodnuti)
    {
      case 1:
        system("cls");
        printAlbMain(databazeAlb,n);
        break;

      case 2:
        system("cls");
        novyAlbum(databazeAlb,n);
        n++;
        break;

      case 3:
        system("cls");
        opravaAlba(databazeAlb);
        break;

      case 4:
        system("cls");
        filtrAlb(databazeAlb,n);
        break;

      case 5:
        system("cls");
        prumerPocPis(databazeAlb,n);
        break;

      default:
        system("cls");
        printf("...vypinam program sefe...\n");
        konec = 1;
        break;
    }
  }while(konec == 0);

  return 0;
}
