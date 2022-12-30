#include "../include/Repozytorium.h";
#include "../include/Student.h";
#include "../include/Wyklad.h";
#include "../include/Zapis.h";
#include "../include/Lista_studentow.h";
using namespace std;

Repozytorium::Repozytorium()
{
    Student_plik.open("./Student_plik.txt", ios::in | ios::out | ios::app);
    Wyklad_plik.open("./Wyklad_plik.txt", ios::in | ios::out | ios::app);
    Zapis_plik.open("./Zapis_plik.txt", ios::in | ios::out | ios::app);
}

Repozytorium::~Repozytorium()
{
    Student_plik.close();
    Wyklad_plik.close();
    Zapis_plik.close();
}
void Repozytorium::zapisz_studenta(Student student_zapisz) {
    Student_plik << student_zapisz.pobierz_imie() << "," << 
    student_zapisz.pobierz_nazwisko() << "," << 
    student_zapisz.pobierz_indeks() << "\n";
}

void Repozytorium::zapisz_wyklad(Wyklad wyklad_zapisz) {
     Wyklad_plik << wyklad_zapisz.pobierz_nazwa_przedmiotu() << "," << 
     wyklad_zapisz.pobierz_kod_przedmiotu() << "," << 
     wyklad_zapisz.pobierz_nazwisko_prowadzacego() << "\n";
}

void Repozytorium::zapisz_zapis(Zapis zapis_zapisz)  {
    Zapis_plik << zapis_zapisz.pobierz_kod_przedmiotu() << "," << 
    zapis_zapisz.pobierz_numer_indeksu() << "\n";
}

Lista_studentow Repozytorium::wycztaj_studentow() {
    Lista_studentow *ls = new Lista_studentow;
    Student *st;
    string imie,nazwisko,indeks;
    Student_plik.clear();
    Student_plik.seekg(0, ios::beg);
    while(getline(Student_plik, imie, ',') && 
        getline(Student_plik, nazwisko, ',' ) &&
        getline(Student_plik, indeks)) {
            st = new Student(imie,nazwisko,indeks);
            ls->dodaj_studenta(st);
        }
    return *ls;
}