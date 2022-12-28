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
void Repozytorium::Zapisz_studenta(Student student_zapisz){
    Student_plik << student_zapisz.wypisz_imie() << "," << 
    student_zapisz.wypisz_nazwisko() << "," << student_zapisz.wypisz_indeks() << endl;
}

void Repozytorium::Zapisz_wyklad(Wyklad wyklad_zapisz){
    // Wyklad_plik << wyklad_zapisz << ", " << 
    // wyklad_zapisz << ", " << wyklad_zapisz;
}

void Repozytorium::Zapisz_zapis(Zapis zapis_zapisz){

}