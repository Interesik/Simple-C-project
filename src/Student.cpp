#include "../include/Student.h"

Student::Student() {
    cout<<"Prosze podac nazwisko:";
    cin>>nazwisko;
    cout<<"Prosze podac imie:";
    cin>>imie;
    cout<<"Prosze podac numer indeksu:";
    cin>>indeks;
}

Student::~Student() {}


string Student::wypisz_nazwisko() {return this->nazwisko;}
string Student::wypisz_imie() {return this->imie;}
string Student::wypisz_indeks() {return this->indeks;}