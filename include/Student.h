#ifndef Student_H
#define Student_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Student
{
private:
    string nazwisko;
    string imie;
    string indeks;
public:
    // konstrukor
    Student();
    Student(string imie, string nazwisko, string indeks);
    // dekonstruktor
    ~Student();
    string pobierz_nazwisko();
    string pobierz_imie();
    string pobierz_indeks();
    void ustaw_nazwisko(string nowe_nazwisko);
    void ustaw_imie(string nowe_imie);
    void ustaw_indeks(string nowe_indeks);
    Student *nastepny;
};

#endif