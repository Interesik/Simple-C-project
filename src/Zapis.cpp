#include "../include/Zapis.h";
#include <iostream>

Zapis::Zapis() {
    cout<<"Prosze podac numer indeksu:";
    cin>>numer_indeksu;
    cout<<"Prosze podac kod przedmiotu:";
    cin>>kod_przedmiotu;
}
Zapis::~Zapis() {}