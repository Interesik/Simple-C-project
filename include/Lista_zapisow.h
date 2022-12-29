#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Zapis;
class Lista_zapis
{
public:
    Lista_zapis(); //konstruktor
    ~Lista_zapis();
    Zapis *poczatek;
    Zapis *koniec;
    Zapis znajdz_zapis_po_kod_przedmiotu(string kod_przedmiotu); //funkcja która przyjmuje np. nazwisko lub indeks
    Zapis znajdz_zapis_po_numer_indeksu(string numer_indeksu);
    void dodaj_zapis();
    void wypisz_liste();
    //mozna oddac mase funkcji

};