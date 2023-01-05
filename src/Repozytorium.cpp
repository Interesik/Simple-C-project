#include "../include/Repozytorium.h"
#include "../include/Student.h"
#include "../include/Wyklad.h"
#include "../include/Zapis.h"
#include "../include/Lista_studentow.h"
#include "../include/Lista_wykladow.h"
#include "../include/Lista_zapisow.h"
#include <sstream>
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
    cout << "zapisano." << endl;
}

void Repozytorium::zapisz_wyklad(Wyklad wyklad_zapisz) {
     Wyklad_plik << wyklad_zapisz.pobierz_nazwa_przedmiotu() << "," << 
     wyklad_zapisz.pobierz_kod_przedmiotu() << "," << 
     wyklad_zapisz.pobierz_nazwisko_prowadzacego() << "\n";
     cout << "zapisano." << endl;
}

void Repozytorium::zapisz_zapis(Zapis zapis_zapisz)  {
    Zapis_plik << zapis_zapisz.pobierz_kod_przedmiotu() << "," << 
    zapis_zapisz.pobierz_numer_indeksu() << "\n";
    cout << "zapisano." << endl;
}

Lista_studentow* Repozytorium::wycztaj_studentow() {
    Lista_studentow *ls = new Lista_studentow;
    Student *st;
    string imie,nazwisko,indeks;
    //ustawiam wskażnik odczytu pliku na początek jego
    Student_plik.clear();
    Student_plik.seekg(0, ios::beg);
    //czytam po każdym atrybucie 
    while(getline(Student_plik, imie, ',') && 
        getline(Student_plik, nazwisko, ',' ) &&
        getline(Student_plik, indeks)) {
            st = new Student(imie,nazwisko,indeks);
            ls->dodaj_studenta(st);
        }
    return ls;
}
void Repozytorium::wypisz_studenta(string indeks, Lista_studentow ls) {
    if(!ls.usun_studneta(indeks)) {
        return;
    }
    ostringstream tymcz;
    //czyt_indeks będzie zapisywana jedną linią w pliku
    string czyt_indeks;
    Student_plik.clear();
    Student_plik.seekg(0, ios::beg);
    tymcz << Student_plik.rdbuf();
    // tworze zmienna string w której zapisuję całą zawartość pliku,
    // w celu wykorzystania metody find z string 
    string zmiana = tymcz.str();
    Student_plik.clear();
    Student_plik.seekg(0, ios::beg);
    while (getline(Student_plik, czyt_indeks)) {
        // szuka w pliku linią z poszukiwanym indeksem
        if (czyt_indeks.find(indeks)!=string::npos) {
            //Jezeli znajdzie, zamienia całą linie na "", (+ 1) ponieważ usuwam endl
            zmiana.replace(zmiana.find(czyt_indeks),czyt_indeks.length()+1,"");
            Student_plik.close();
            // otwieram plik w celu nadpisania go całego zamienioną zmienną string
            Student_plik.open("./Student_plik.txt", ios::in | ios::out | ios::trunc);
            Student_plik << zmiana;
            Student_plik.close();
            // powracam do domyślnego trybu dopisywania
            Student_plik.open("./Student_plik.txt", ios::in | ios::out | ios::app);
            return;
        }
    }
    return;
}

Lista_wykladow* Repozytorium::wycztaj_wyklady() {
    Lista_wykladow *lw = new Lista_wykladow;
    Wyklad *wy;
    string nazwa_przedmiotu, nazwisko_prowadzacego, kod_przedmiotu;
    Wyklad_plik.clear();
    Wyklad_plik.seekg(0, ios::beg);
    while(getline(Wyklad_plik, nazwa_przedmiotu, ',') && 
        getline(Wyklad_plik, kod_przedmiotu, ',' ) &&
        getline(Wyklad_plik, nazwisko_prowadzacego)) {
            wy = new Wyklad(nazwa_przedmiotu, nazwisko_prowadzacego, kod_przedmiotu);
            lw->dodaj_wyklad(wy);
        }
    return lw;
}

void Repozytorium::anuluj_wyklad(string kod_przedmiotu, Lista_wykladow lw) {
    if(!lw.usun_wyklad(kod_przedmiotu)) {
        return;
    }
    ostringstream tymcz;
    //czyt_kod_przedmiotu będzie zapisywana jedną linią w pliku
    string czyt_kod_przedmiotu;
    Wyklad_plik.clear();
    Wyklad_plik.seekg(0, ios::beg);
    tymcz << Wyklad_plik.rdbuf();
    // tworze zmienna string w której zapisuję całą zawartość pliku,
    // w celu wykorzystania metody find z string 
    string zmiana = tymcz.str();
    Wyklad_plik.clear();
    Wyklad_plik.seekg(0, ios::beg);
    // szuka w pliku lini z poszukiwanym kodem_przedmiotu
    while (getline(Wyklad_plik, czyt_kod_przedmiotu)) {
        if (czyt_kod_przedmiotu.find(kod_przedmiotu)!=string::npos) {
            //Jezeli znajdzie, zamienia całą linie na "", (+ 1) ponieważ usuwam endl;
            zmiana.replace(zmiana.find(czyt_kod_przedmiotu),czyt_kod_przedmiotu.length()+1,"");
            Wyklad_plik.close();
            // otwieram plik w celu nadpisania go całego zamienioną zmienną string
            Wyklad_plik.open("./Wyklad_plik.txt", ios::in | ios::out | ios::trunc);
            Wyklad_plik << zmiana;
            Wyklad_plik.close();
            // powracam do domyślnego trybu dopisywania
            Wyklad_plik.open("./Wyklad_plik.txt", ios::in | ios::out | ios::app);
            return;
        }
    }
    return;
}


Lista_zapisow* Repozytorium::wycztaj_zapisy() {
    Lista_zapisow *lz = new Lista_zapisow;
    Zapis *za = nullptr;
    string kod_przedmiotu, numer_indesku;
    Zapis_plik.clear();
    Zapis_plik.seekg(0, ios::beg);
    while(getline(Zapis_plik, kod_przedmiotu, ',') && 
        getline(Zapis_plik, numer_indesku)) {
            za = new Zapis(numer_indesku, kod_przedmiotu);
            lz->dodaj_zapis(za);
        }
    return lz;
}

void Repozytorium::anuluj_zapis(string kod_przedmiotu,string numer_indeksu, Lista_zapisow lz) {
    if(!lz.usun_zapis(kod_przedmiotu, numer_indeksu)) {
        return;
    }
    ostringstream tymcz;
    //czyt_linia będzie zapisywana jedną linią w pliku
    string czyt_linia;
    Zapis_plik.clear();
    Zapis_plik.seekg(0, ios::beg);
    tymcz << Zapis_plik.rdbuf();
    // tworze zmienna string w której zapisuję całą zawartość pliku,
    // w celu wykorzystania metody find z string 
    string zmiana = tymcz.str();
    Zapis_plik.clear();
    Zapis_plik.seekg(0, ios::beg);
    // szuka w pliku lini z poszukiwanym kodem_przedmiotu i numerem_indeksu
    while (getline(Zapis_plik, czyt_linia)) {
        if (czyt_linia.find(kod_przedmiotu)!=string::npos &&
            czyt_linia.find(numer_indeksu)!=string::npos) {
            //Jezeli znajdzie zamienia całą linie na "", (+ 1) ponieważ usuwam endl;
            zmiana.replace(zmiana.find(czyt_linia),czyt_linia.length()+1,"");
            Zapis_plik.close();
            // otwieran plik w celu nadpisania go całego zamienioną zmienną string
            Zapis_plik.open("./Zapis_plik.txt", ios::in | ios::out | ios::trunc);
            Zapis_plik << zmiana;
            Zapis_plik.close();
            // powracam do domyślnego trybu dopisywania
            Zapis_plik.open("./Zapis_plik.txt", ios::in | ios::out | ios::app);
            return;
        }
    }
    return;
}