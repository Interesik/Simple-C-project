#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Student;
class Lista_studentow
{
private:
    Student *poczatek = nullptr;
    Student *koniec = nullptr;
public:
    Lista_studentow(); //konstruktor

    ~Lista_studentow();

    void ustaw_poczatek(Student* poczatek);

    void ustaw_koniec(Student* koniec);

    Student* pobierz_poczatek();

    Student* pobierz_koniec();

    Student znajdz_studenta_nazwisko(string nazwisko); 
    //funkcja która przyjmuje np. nazwisko lub indeks
    
    Student znajdz_studenta_indeks(string indeks);

    void dodaj_studenta(Student* nowy);

    void wypisz_liste();
    //mozna oddac mase funkcji.// czyli usuń, zamień tylko

};