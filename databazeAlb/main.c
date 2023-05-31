#include "gvid.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Struktura ALBUM je entita pole listAlb, která je databáze programu. má 5 položek; 3 stringy (nazev, autor a zanr) a 2 inty (rokVydani, pocetPisni)
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
- filtr alb
- vytvoření nového alba
- výpočet průměrného počtu písní (souhrnný výpočet)
*/

// Tisk alb + alternativní  verze/podfunkce
void printAlbList(ALBUM listAlb[], int n)
{
  system("cls");
  for(int i=0 ; i<n; i++)
  {
    printf("  %d:\n  ALBUM: %s\n  AUTOR: %s\n  ZANR: %s\n  P.PISNI: %d\n  R. VYDANI: %d\n\n", i, listAlb[i].nazev, listAlb[i].autor, listAlb[i].zanr, listAlb[i].pocetPisni, listAlb[i].rokVydani);
  }

}
void singlePrintAlb(ALBUM listAlb, int n)
{
  printf("\n  %d:\n  ALBUM: %s\n  AUTOR: %s\n  ZANR: %s\n  P.PISNI: %d\n  R. VYDANI: %d\n", n, listAlb.nazev, listAlb.autor, listAlb.zanr, listAlb.pocetPisni, listAlb.rokVydani);
}
void askSinglePrintAlb(ALBUM listAlb[])
{
  int n;
  system("cls");
  printf("zadejte album z databaze, ktere chcete vytisknout (cislo): ");
  scanf("%d", &n);
  printf("\n  %d:\n  ALBUM: %s\n  AUTOR: %s\n  ZANR: %s\n  P.PISNI: %d\n  R. VYDANI: %d\n\n", n, listAlb[n].nazev, listAlb[n].autor, listAlb[n].zanr, listAlb[n].pocetPisni, listAlb[n].rokVydani);
}
void printAlbMain(ALBUM listAlb[], int n)
{
  int v;
  printf("chcete vytisknout celou databazi, nebo pouze jedno album? \n  1: pouze jedno \n  2: celou databazi \n  else: konec tisku \n  ");
  scanf(" %d", &v);

  switch(v)
  {
    case 1: askSinglePrintAlb(listAlb); break;
    case 2: printAlbList(listAlb, n); break;
    default: system("cls"); break;
  }
}

// Oprava alba + podfunkce
void opravaNazvu(ALBUM listAlb[],int n)
{
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
  int n, m;
  printf("Zadejte album, ktere chcete zmenit (cislo): ");
  scanf("%d", &n);
  singlePrintAlb(listAlb[n],n);
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

// Filtr alb + podfunkce
void filtrNazvu(ALBUM listAlb[], int n)
{
  char filtrNaz[50];
  printf("zadejte nazev, kterym chcete filtrovat: ");
  scanf(" %[^\n]", filtrNaz);
  system("cls");
  for(int i = 0; i <n; i++)
  {
    if( strcmp(listAlb[i].nazev,filtrNaz)==0 )
    {
      singlePrintAlb(listAlb[i],i);
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
      singlePrintAlb(listAlb[i],i);
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
      singlePrintAlb(listAlb[i],i);
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
      singlePrintAlb(listAlb[i],i);
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
      singlePrintAlb(listAlb[i],i);
    }
  }
  printf("\n");
}
void filtrAlb(ALBUM listAlb[], int n)
{
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

// Vytvoření nového alba
void novyAlbum(ALBUM listAlb[], int n)
{
  int pp, rok, m = n;
  char nazev[50];
  char autor[50];
  char zanr[50];
  n++;

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

  strcpy(listAlb[m].nazev, nazev);
  strcpy(listAlb[m].autor, autor);
  strcpy(listAlb[m].zanr, zanr);
  listAlb[m].pocetPisni = pp;
  listAlb[m].rokVydani = rok;
}

// Výpočet průměrného počtu písní
void prumerPocPis(ALBUM listAlb[], int n)
{
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
  // Int p funguje jako rozhodnutí vypnout program. Jestli ve switchy se zapne default, p se stane 0, a do-while cyklus skončí.
  int p = 1;
  // Int r je proměnná pro switch, který dává uživateli navýběr, které funkce chce zkusit.
  int r;
  int n = 32;
  // Int n funguje jako aktuální počet entit v poli.
  char x = 178;
  // Char, který je použit pro vizuální šmrnc.

  // Definice pole alb, maximální velikost je 64, 32 už tam je.
  ALBUM listAlb[64] = {
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
    scanf(" %d", &r);
    system("cls");

    // Switch, který u každého casu vymaže konzoli a začne funkci, kdyžtak změní proměnnou.
    switch(r)
    {
      case 1:
        system("cls");
        printAlbMain(listAlb,n);
        break;

      case 2:
        system("cls");
        novyAlbum(listAlb,n);
        n++;
        break;

      case 3:
        system("cls");
        opravaAlba(listAlb);
        break;

      case 4:
        system("cls");
        filtrAlb(listAlb,n);
        break;

      case 5:
        system("cls");
        prumerPocPis(listAlb,n);
        break;

      default:
        system("cls");
        printf("...vypinam program sefe...\n");
        p = 0;
        break;
    }
  }while(p == 1);

  return 0;
}
