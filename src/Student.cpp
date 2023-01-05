#include "../include/Student.h"

Student::Student() {
    cout<<"Prosze podac nazwisko:";
    cin>>nazwisko;
    cout<<"Prosze podac imie:";
    cin>>imie;
    cout<<"Prosze podac numer indeksu:";
    cin>>indeks;
}

Student::Student(string imie, string nazwisko, string indeks) {
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->indeks = indeks;
}

Student::~Student() {}


string Student::pobierz_nazwisko() {return this->nazwisko;}
string Student::pobierz_imie() {return this->imie;}
string Student::pobierz_indeks() {return this->indeks;}
void Student::ustaw_nazwisko(string nowe_nazwisko){this->nazwisko = nazwisko;};
void Student::ustaw_imie(string nowe_imie){ this->imie = imie;};
void Student::ustaw_indeks(string nowe_indeks){this->indeks = indeks;};