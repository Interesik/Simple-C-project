#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Wyklad;
class Lista_wykladow
{
public:
    Lista_wykladow(); //konstruktor
    ~Lista_wykladow();
    Wyklad *poczatek;
    Wyklad *koniec;
    Wyklad znajdz_wyklad_po_nazwa_przedmiotu(string nazwa_przedmiotu); //funkcja która przyjmuje np. nazwisko lub indeks
    Wyklad znajdz_wyklad_po_nazwisko_prowadzacego(string nazwisko_prowadzacego);
    Wyklad znajdz_wyklad_po_kod_przedmiotu(string kod_przedmiotu);
    void dodaj_wyklad();
    void wypisz_liste();
    //mozna oddac mase funkcji

};