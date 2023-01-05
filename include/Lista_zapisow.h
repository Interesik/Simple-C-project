#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Zapis;
class Lista_zapisow
{
private:
    Zapis *poczatek = nullptr;
    Zapis *koniec = nullptr;
public:
    Lista_zapisow(); //konstruktor

    ~Lista_zapisow();

    void ustaw_poczatek(Zapis* poczatek);

    void ustaw_koniec(Zapis* koniec);

    Zapis* pobierz_poczatek();

    Zapis* pobierz_koniec();

    Zapis* znajdz_zapis(string kod_przedmiotu, string numer_indeksu);
    
    void dodaj_zapis(Zapis* nowy);

    void wypisz_liste();

    bool usun_zapis(string kod_przedmiotu, string numer_indeksu);

};