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
    // dekonstruktor
    ~Student();
    void zapisz(string, string, string);
    string wypisz_nazwisko();
    string wypisz_imie();
    string wypisz_indeks();
    Student *nastepny;
};

#endif