#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Student;
class Lista_studentow
{
public:
    Lista_studentow(); //konstruktor
    ~Lista_studentow();
    Student *poczatek;
    Student *koniec;
    Student znajdz_studenta_nazwisko(string nazwisko); //funkcja która przyjmuje np. nazwisko lub indeks
    Student znajdz_studenta_indeks(string indeks);
    void dodaj_studenta();
    void wypisz_liste();
    //mozna oddac mase funkcji

};