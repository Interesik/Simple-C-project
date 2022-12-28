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

Wyklad::~Wyklad() {}