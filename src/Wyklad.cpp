#include "../include/Wyklad.h";
#include <iostream>
using namespace std;

Wyklad::Wyklad() {
    cout<<"Prosze podac nazwe przedmiotu:";
    cin>>nazwa_przedmiotu;
    cout<<"Prosze podac nazwisko prowadzacego:";
    cin>>nazwisko_prowadzacego;
    cout<<"Prosze podac kod przedmiotu:";
    cin>>kod_przedmiotu;
}
Wyklad::Wyklad(string nazwa_przedmiotu, string nazwisko_prowadzacego, string kod_przedmiotu) {
    this->nazwa_przedmiotu = nazwa_przedmiotu;
    this->nazwisko_prowadzacego = nazwisko_prowadzacego;
    this->kod_przedmiotu = kod_przedmiotu;
}

Wyklad::~Wyklad() {}

string Wyklad::pobierz_kod_przedmiotu() { return this->kod_przedmiotu;};
string Wyklad::pobierz_nazwa_przedmiotu() { return this->nazwa_przedmiotu;};
string Wyklad::pobierz_nazwisko_prowadzacego() { return this->nazwisko_prowadzacego;};