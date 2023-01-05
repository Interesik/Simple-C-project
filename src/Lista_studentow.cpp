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
    Student *element_listy = this->pobierz_poczatek();
    if (element_listy == nullptr)
    {
        cout <<"Lista jest pusta"<<endl;
        return;
    }
    int i = 1;
    while (element_listy!=nullptr)
    {
        cout << "Student nr" << i++ << ":" << endl;
        cout << "Nazwisko:" << (element_listy-> pobierz_nazwisko()) << endl;
        cout << "Imie:" << (element_listy-> pobierz_imie()) << endl;
        cout << "Indeks:" << (element_listy-> pobierz_indeks()) << endl;
        element_listy = element_listy -> nastepny;

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
    Student *element_listy = pobierz_poczatek();
    if (element_listy == nullptr)
    {
        cout <<"Lista jest pusta"<<endl;
        return nullptr;
    }
    while (element_listy!=nullptr)
    {
        // Szukamy dopuki nie znajdziemy studneta o takim indesie w liscie
        if(element_listy->pobierz_indeks().compare(indeks) == 0) {
            cout << "Znaleziono: \nNazwisko:" << (element_listy-> pobierz_nazwisko()) << endl;
            cout << "Imie:" << (element_listy-> pobierz_imie()) << endl;
            cout << "Indeks:" << (element_listy-> pobierz_indeks()) << endl;
            return element_listy;
        }
        element_listy = element_listy -> nastepny;
    }
    cout <<"W listcie nie ma studenta o takim indeksie"<<endl;
    return 0;
}

Student* Lista_studentow::znajdz_studenta_nazwisko(string nazwisko) {
    Student *element_listy = pobierz_poczatek();
    if (element_listy == nullptr)
    {
        cout <<"Lista jest pusta"<<endl;
        return NULL;
    }
    while (element_listy!=nullptr)
    {
        // Szukamy dopuki nie znajdziemy studneta o takim indesie w liscie
        if(element_listy->pobierz_nazwisko().compare(nazwisko) == 0) {
            cout << "Znaleziono: \nNazwisko:" << (element_listy-> pobierz_nazwisko()) << endl;
            cout << "Imie:" << (element_listy-> pobierz_imie()) << endl;
            cout << "Indeks:" << (element_listy-> pobierz_indeks()) << endl;
            return element_listy;
        }
        element_listy = element_listy -> nastepny;
    }
    cout <<"W listcie nie ma studenta o takim indeksie"<<endl;
    return 0;
}

// Zakładam że nie ma 2 i więcej studentów o tym samym indeksie.
bool Lista_studentow::usun_studneta(string indeks) {
    Student *szukany = this->znajdz_studenta_indeks(indeks);
    Student *poprzedni;
    Student *element_listy = this->pobierz_poczatek();
    // Jeżeli poszukiwany student był pierwszy zamień tylko początek listy
    if(element_listy == szukany) {
        this->ustaw_poczatek(element_listy->nastepny);
        delete szukany;
        cout <<"Usunieto studenta o takim indeksie"<<endl;
        return true;
    }
    while (element_listy != nullptr) {
        if(element_listy == szukany) {
            // Jeżeli poszukiwany student był ostatni zamień koniec listy i wskźnik poprzedniego elementu
            if(this->pobierz_koniec() == element_listy) {
                this->ustaw_koniec(poprzedni);
                poprzedni->nastepny = nullptr;
                delete szukany;
                cout <<"Usunieto studenta o takim indeksie"<<endl;
                return true;
            }else {
                // Jeżeli poszukiwany student był w środku listy, zamień wskźnik poprzedniego elementu na następny
                poprzedni->nastepny = element_listy -> nastepny;
                delete szukany;
                cout <<"Usunieto studenta o takim indeksie"<<endl;
                return true;
            }
        }
        poprzedni = element_listy;
        element_listy = element_listy -> nastepny;
    }
    cout <<"W listcie nie ma studenta o takim indeksie"<<endl;
    return false;
    
};
