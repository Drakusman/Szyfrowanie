#include<iostream>
#include<cstdlib>
#include<cstring>
#include<fstream>
using namespace std;

string szyfrowanie(string slowo, string klucz);
string deszyfrowanie(string slowo, string klucz);

int main()
{
    //szyfrowanie
    string linia;
    string klucz[120];
    string slowo[120];
    ifstream szyfrPlik ("Szyfr_klucze1.txt",ios::in);

      int i=0;
    while ( getline (szyfrPlik,linia) )
    {
      klucz[i]=linia;
      i++;
    }
    szyfrPlik.close();
    ifstream slowoPlik ("Szyfr_tj.txt",ios::in);

     i=0;
    while ( getline (slowoPlik,linia) )
    {
      slowo[i]=linia;
      i++;
    }
    slowoPlik.close();

     ofstream wynik ("wynik4a.txt", ios::out);

    for(int i=0;i<120;i++)
    {
        wynik << szyfrowanie(slowo[i],klucz[i])<<"\n";
    }

    wynik.close();


    //deszyfrowanie
    string slowo2[120];
    string deszyfr[120];
    ifstream slowo2Plik ("Szyfr_klucze2.txt",ios::in);

    i=0;
    while ( getline (slowo2Plik,linia) )
    {
      slowo2[i]=linia;
      i++;
    }
    slowo2Plik.close();
    ifstream deszyfrPlik ("Szyfr_sz.txt",ios::in);

     i=0;
    while ( getline (deszyfrPlik,linia) )
    {
      deszyfr[i]=linia;
      i++;
    }
    deszyfrPlik.close();

     ofstream wynik2 ("wynik4b.txt", ios::out);

    for(int i=0;i<120;i++)
    {
        wynik2 << deszyfrowanie(deszyfr[i],slowo2[i])<<"\n";
    }

    wynik2.close();


return 0;
}
string szyfrowanie(string slowo, string klucz)
{
    int licznik1, licznik2, kod1, kod2;
    string wynik="";
    char k;
    licznik1=slowo.length();
    licznik2=klucz.length();
        for (int i=0;i<licznik1; i++)
    {
        kod1=slowo[i];
        if (i<licznik2) kod2=klucz[i]; else kod2=klucz[i%licznik2];
        if((kod1+kod2-64)>90) k=kod1+kod2-90;
            else k=kod1+kod2-64;


wynik+=k;  

    }
    return wynik;
}

string deszyfrowanie(string slowo, string klucz)
{
    int licznik1, licznik2, kod1, kod2;
    string wynik="";
    char k;
    licznik1=slowo.length();
    licznik2=klucz.length();
        for (int i=0;i<licznik1; i++)
        {
        kod1=slowo[i];
        if (i<licznik2) kod2=klucz[i]; else kod2=klucz[i%licznik2];
        if((kod1-kod2)>0) k=kod1-kod2+64;
            else k=kod1-kod2+90;

wynik+=k;  

    }
    return wynik;
}
