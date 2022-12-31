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
    this->ustaw_koniec(nowy);   //trzy wskaźniki ustawilismy // XD nie wiadomo bo są ify.
    if(this->pobierz_poczatek() == nullptr)
    {
        this->ustaw_poczatek(nowy);
    }
}

Student* Lista_studentow::znajdz_studenta_indeks(string indeks) {
    Student *tymcz = pobierz_poczatek();
    if (tymcz == nullptr)
    {
        cout <<"Lista jest pusta"<<endl;
        return NULL;
    }
    while (tymcz!=nullptr)
    {
        // Szukamy dopuki nie znajdziemy studneta o takim indesie w liscie
        if(tymcz->pobierz_indeks().compare(indeks) == 0) {
            cout << "Znaleziono: \nNazwisko:" << (tymcz-> pobierz_nazwisko()) << endl;
            cout << "Imie:" << (tymcz-> pobierz_imie()) << endl;
            cout << "Indeks:" << (tymcz-> pobierz_indeks()) << endl;
            return tymcz;
        }
        tymcz = tymcz -> nastepny;
    }
    cout <<"W listcie nie ma studenta o takim indeksie"<<endl;
    return 0;
}

// Zakładam że nie ma 2 i więcej studentów o tym samym indeksie.
bool Lista_studentow::wyjeb_studenta_za_ECTSY(string indeks) {
    Student *szukany = this->znajdz_studenta_indeks(indeks);
    Student *poprzedni;
    Student *tymcz = this->pobierz_poczatek();
    // Jeżeli poszukiwany student był pierwszy zamień tylko początek listy
    if(tymcz == szukany) {
        this->ustaw_poczatek(tymcz->nastepny);
        delete szukany;
        cout <<"Usunieto studenta o takim indeksie"<<endl;
        return true;
    }
    while (tymcz!=nullptr) {
        if(tymcz == szukany) {
            // Jeżeli poszukiwany student był ostatni zamień koniec listy i wskźnik poprzedniego elementu
            if(this->pobierz_koniec() == tymcz) {
                this->ustaw_koniec(poprzedni);
                poprzedni->nastepny = nullptr;
                delete szukany;
                cout <<"Usunieto studenta o takim indeksie"<<endl;
                return true;
            }else {
                // Jeżeli poszukiwany student był w środku listy, zamień wskźnik poprzedniego elementu na następny
                poprzedni->nastepny = tymcz -> nastepny;
                delete szukany;
                cout <<"Usunieto studenta o takim indeksie"<<endl;
                return true;
            }
        }
        poprzedni = tymcz;
        tymcz = tymcz -> nastepny;
    }
    cout <<"W listcie nie ma studenta o takim indeksie"<<endl;
    return false;
    
};
