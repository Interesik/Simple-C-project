#include "../include/Repozytorium.h";
#include "../include/Student.h";
#include "../include/Wyklad.h";
#include "../include/Zapis.h";

Repozytorium::Repozytorium()
{
    Student_plik.open("./Student_plik.txt", ios::in | fstream::out | fstream::app);
    Wyklad_plik.open("./Wyklad_plik.txt", ios::in | fstream::out | fstream::app);
    Zapis_plik.open("./Zapis_plik.txt", ios::in | fstream::out | fstream::app);
}

Repozytorium::~Repozytorium()
{
    Student_plik.close();
    Wyklad_plik.close();
    Zapis_plik.close();
}
void Repozytorium::zapisz_studenta(Student student_zapisz){
    Student_plik << student_zapisz.pobierz_imie() << "," << 
    student_zapisz.pobierz_nazwisko() << "," << 
    student_zapisz.pobierz_indeks() << endl;
}

void Repozytorium::zapisz_wyklad(Wyklad wyklad_zapisz){
     Wyklad_plik << wyklad_zapisz.pobierz_nazwa_przedmiotu() << ", " << 
     wyklad_zapisz.pobierz_kod_przedmiotu() << ", " << 
     wyklad_zapisz.pobierz_nazwisko_prowadzacego() << endl;
}

void Repozytorium::zapisz_zapis(Zapis zapis_zapisz){
    Zapis_plik << zapis_zapisz.pobierz_kod_przedmiotu() << ", " << 
    zapis_zapisz.pobierz_numer_indeksu() << endl;
}