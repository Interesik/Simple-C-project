#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Wyklad;
class Lista_wykladow
{
private:
    Wyklad *poczatek = nullptr;
    Wyklad *koniec = nullptr;
public:
    Lista_wykladow(); //konstruktor

    ~Lista_wykladow();

    void ustaw_poczatek(Wyklad* poczatek);

    void ustaw_koniec(Wyklad* koniec);

    Wyklad* pobierz_poczatek();

    Wyklad* pobierz_koniec();

    Wyklad* znajdz_wyklad_po_nazwa_przedmiotu(string nazwa_przedmiotu);

    Wyklad* znajdz_wyklad_po_nazwisko_prowadzacego(string nazwisko_prowadzacego);

    Wyklad* znajdz_wyklad_po_kod_przedmiotu(string kod_przedmiotu);
    
    void dodaj_wyklad(Wyklad* nowy);

    void wypisz_liste();

    //zakładam że każdy wykład ma unikatowy kod_przedmiotu
    bool usun_wyklad(string kod_przedmiotu);
    

};