#include "../include/Student.h"
#include "../include/Lista_studentow.h"
#include "../include/Repozytorium.h"
using namespace std;

void Lista_studentow::ustaw_poczatek(Student* poczatek) { this->poczatek = poczatek;};

void Lista_studentow::ustaw_koniec(Student* koniec) { this->koniec = koniec;};

Student* Lista_studentow::pobierz_poczatek() { return poczatek;};

Student* Lista_studentow::pobierz_koniec() { return koniec;};

Lista_studentow::Lista_studentow() {};

Lista_studentow::~Lista_studentow() {};

void Lista_studentow::wypisz_liste()
{
    Student *tymcz = pobierz_poczatek();
    if (tymcz == nullptr)
    {
        cout <<"Lista jest pusta"<<endl;
        return;
    }
    int i = 1;
    while (tymcz!=nullptr)
    {
        cout << "Student nr" << i++ << ":" << endl;
        cout << "Nazwisko:" << (tymcz-> pobierz_nazwisko()) << endl;
        cout << "Imie:" << (tymcz-> pobierz_imie()) << endl;
        cout << "Indeks:" << (tymcz-> pobierz_indeks()) << endl;
        tymcz = tymcz -> nastepny;

    }

}
void Lista_studentow::dodaj_studenta(Student* nowy)
{
    if (this->pobierz_koniec() != nullptr ) {
        this->pobierz_koniec() -> nastepny = nowy;
    }
    nowy->nastepny = nullptr;
    this->ustaw_koniec(nowy);   //trzy wskaźniki ustawilismy
    if(this->pobierz_poczatek() == nullptr)
    {
        this->ustaw_poczatek(nowy);
    }
}
