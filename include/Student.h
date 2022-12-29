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
    string pobierz_nazwisko();
    string pobierz_imie();
    string pobierz_indeks();
    Student *nastepny;
};

#endif