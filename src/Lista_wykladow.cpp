#include "../include/Wyklad.h"
#include "../include/Lista_wykladow.h"
#include "../include/Repozytorium.h"
using namespace std;

void Lista_wykladow::ustaw_poczatek(Wyklad* poczatek) { this->poczatek = poczatek;};

void Lista_wykladow::ustaw_koniec(Wyklad* koniec) { this->koniec = koniec;};

Wyklad* Lista_wykladow::pobierz_poczatek() { return poczatek;};

Wyklad* Lista_wykladow::pobierz_koniec() { return koniec;};

Lista_wykladow::Lista_wykladow() {};

Lista_wykladow::~Lista_wykladow() {};

void Lista_wykladow::wypisz_liste()
{
    Wyklad *element_listy = pobierz_poczatek();
    if (element_listy == nullptr)
    {
        cout <<"Lista jest pusta"<<endl;
        return;
    }
    int i = 1;
    while (element_listy != nullptr)
    {
        cout << "Wyklad nr" << i++ << ":" << endl;
        cout << "Kod_przedmiotu:" << (element_listy-> pobierz_kod_przedmiotu()) << endl;
        cout << "Nazwa_przedmiotu:" << (element_listy-> pobierz_nazwa_przedmiotu()) << endl;
        cout << "Nazwisko_prowadzacego:" << (element_listy-> pobierz_nazwisko_prowadzacego()) << endl;
        element_listy = element_listy -> nastepny;

    }
}
void Lista_wykladow::dodaj_wyklad(Wyklad* nowy)
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

Wyklad* Lista_wykladow::znajdz_wyklad_po_kod_przedmiotu(string kod_przedmiotu) {
    Wyklad *element_listy = pobierz_poczatek();
    if (element_listy == nullptr)
    {
        cout <<"Lista jest pusta"<<endl;
        return nullptr;
    }
    while (element_listy!=nullptr)
    {
        // Szukamy dopuki nie znajdziemy studneta o takim indesie w liscie
        if(element_listy->pobierz_kod_przedmiotu().compare(kod_przedmiotu) == 0) {
            cout << "Znaleziono: \nWyklad:"; 
            cout << "Kod_przedmiotu:" << (element_listy-> pobierz_kod_przedmiotu()) << endl;
            cout << "Nazwa_przedmiotu:" << (element_listy-> pobierz_nazwa_przedmiotu()) << endl;
            cout << "Nazwisko_prowadzacego:" << (element_listy-> pobierz_nazwisko_prowadzacego()) << endl;
            return element_listy;
        }
        element_listy = element_listy -> nastepny;
    }
    cout <<"W listcie nie ma Wyklada o takim kodzie przedmiotu"<<endl;
    return 0;
}

Wyklad* Lista_wykladow::znajdz_wyklad_po_nazwa_przedmiotu(string nazwa_przedmiotu) {
    Wyklad *element_listy = this->pobierz_poczatek();
    if (element_listy == nullptr)
    {
        cout <<"Lista jest pusta"<<endl;
        return NULL;
    }
    while (element_listy!=nullptr)
    {
        // Szukamy dopuki nie znajdziemy studneta o takim indesie w liscie
        if(element_listy->pobierz_nazwa_przedmiotu().compare(nazwa_przedmiotu) == 0) {
            cout << "Znaleziono: \nWyklad:"; 
            cout << "Kod_przedmiotu:" << (element_listy-> pobierz_kod_przedmiotu()) << endl;
            cout << "Nazwa_przedmiotu:" << (element_listy-> pobierz_nazwa_przedmiotu()) << endl;
            cout << "Nazwisko_prowadzacego:" << (element_listy-> pobierz_nazwisko_prowadzacego()) << endl;
            return element_listy;
        }
        element_listy = element_listy -> nastepny;
    }
    cout <<"W listcie nie ma wykladu o takim kodzie przedmiotu"<<endl;
    return 0;
}

Wyklad* Lista_wykladow::znajdz_wyklad_po_nazwisko_prowadzacego(string nazwisko_prowadzacego) {
    Wyklad *element_listy = pobierz_poczatek();
    if (element_listy == nullptr)
    {
        cout <<"Lista jest pusta"<<endl;
        return NULL;
    }
    while (element_listy!=nullptr)
    {
        // Szukamy dopuki nie znajdziemy studneta o takim indesie w liscie
        if(element_listy->pobierz_nazwisko_prowadzacego().compare(nazwisko_prowadzacego) == 0) {
            cout << "Znaleziono: \nWyklad:"; 
            cout << "Kod_przedmiotu:" << (element_listy-> pobierz_kod_przedmiotu()) << endl;
            cout << "Nazwa_przedmiotu:" << (element_listy-> pobierz_nazwa_przedmiotu()) << endl;
            cout << "Nazwisko_prowadzacego:" << (element_listy-> pobierz_nazwisko_prowadzacego()) << endl;
            return element_listy;
        }
        element_listy = element_listy -> nastepny;
    }
    cout <<"W listcie nie ma wykladu o takim kodzie przedmiotu"<<endl;
    return 0;
}

// Zakładam że nie ma 2 i więcej wykladów o tym samym Kodzie Przedmiotu.
bool Lista_wykladow::usun_wyklad(string kod_przedmiotu) {
    Wyklad *szukany = this->znajdz_wyklad_po_kod_przedmiotu(kod_przedmiotu);
    Wyklad *poprzedni;
    Wyklad *element_listy = this->pobierz_poczatek();
    // Jeżeli poszukiwany wyklad był pierwszy zamień tylko początek listy
    if(element_listy == szukany) {
        this->ustaw_poczatek(element_listy->nastepny);
        delete szukany;
        cout <<"Usunieto Wyklad o takim kodzie przedmiotu"<<endl;
        return true;
    }
    while (element_listy!=nullptr) {
        if(element_listy == szukany) {
            // Jeżeli poszukiwany wyklad był ostatni zamień koniec listy i wskźnik poprzedniego elementu
            if(this->pobierz_koniec() == element_listy) {
                this->ustaw_koniec(poprzedni);
                poprzedni->nastepny = nullptr;
                delete szukany;
                cout <<"Usunieto wyklad o takim kodzie przedmiotu"<<endl;
                return true;
            }else {
                // Jeżeli poszukiwany Wyklad był w środku listy, zamień wskźnik poprzedniego elementu na następny
                poprzedni->nastepny = element_listy -> nastepny;
                delete szukany;
                cout <<"Usunieto wyklad o takim kodzie przedmiotu"<<endl;
                return true;
            }
        }
        poprzedni = element_listy;
        element_listy = element_listy -> nastepny;
    }
    cout <<"W listcie nie ma wykladu o takim kodzie przedmiotu"<<endl;
    return false;
    
};
