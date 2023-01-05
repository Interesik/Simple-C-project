#include "../include/Zapis.h";
#include <iostream>

Zapis::Zapis() {
    cout<<"Prosze podac numer indeksu:";
    cin>>numer_indeksu;
    cout<<"Prosze podac kod przedmiotu:";
    cin>>kod_przedmiotu;
}

Zapis::Zapis(string numer_indeksu, string kod_przedmiotu) {
    this->numer_indeksu = numer_indeksu;
    this->kod_przedmiotu = kod_przedmiotu;
}

Zapis::~Zapis() {}

string Zapis::pobierz_numer_indeksu() {return this->numer_indeksu;};
string Zapis::pobierz_kod_przedmiotu() {return this->kod_przedmiotu;};