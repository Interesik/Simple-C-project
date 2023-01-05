#include "../include/Zapis.h"
#include "../include/Lista_zapisow.h"
#include "../include/Repozytorium.h"
using namespace std;

void Lista_zapisow::ustaw_poczatek(Zapis* poczatek) { this->poczatek = poczatek;};

void Lista_zapisow::ustaw_koniec(Zapis* koniec) { this->koniec = koniec;};

Zapis* Lista_zapisow::pobierz_poczatek() { return poczatek;};

Zapis* Lista_zapisow::pobierz_koniec() { return koniec;};

Lista_zapisow::Lista_zapisow() {};

Lista_zapisow::~Lista_zapisow() {};

void Lista_zapisow::wypisz_liste()
{
    Zapis *element_listy = this->pobierz_poczatek();
    if (element_listy == nullptr)
    {
        cout <<"Lista jest pusta"<<endl;
        return;
    }
    int i = 1;
    while (element_listy!=nullptr)
    {
        cout << "Zapis nr" << i++ << ":" << endl;
        cout << "Kod_przedmiotu:" << (element_listy-> pobierz_kod_przedmiotu()) << endl;
        cout << "Numer_indeksu:" << (element_listy-> pobierz_numer_indeksu()) << endl;
        element_listy = element_listy -> nastepny;

    }
}
void Lista_zapisow::dodaj_zapis(Zapis* nowy)
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

Zapis* Lista_zapisow::znajdz_zapis(string kod_przedmiotu, string numer_indeksu) {
    Zapis *element_listy = pobierz_poczatek();
    if (element_listy == nullptr)
    {
        cout <<"Lista jest pusta"<<endl;
        return nullptr;
    }
    while (element_listy!=nullptr)
    {
        // Szukamy dopoki nie znajdziemy kod_przedmiotu oraz numer indeksu w liscie
        if(element_listy->pobierz_kod_przedmiotu().compare(kod_przedmiotu) == 0 &&
         element_listy->pobierz_numer_indeksu().compare(numer_indeksu) == 0) {
            cout << "Znaleziono: \nZapis:"; 
            cout << "Kod_przedmiotu:" << (element_listy-> pobierz_kod_przedmiotu()) << endl;
            cout << "Numer_indeksu:" << (element_listy-> pobierz_numer_indeksu()) << endl;
            return element_listy;
        }
        element_listy = element_listy -> nastepny;
    }
    cout <<"W listcie nie ma zapisu o takich danych"<<endl;
    return 0;
}





// Zakładam że nie ma 2 i więcej Zapisów o tym samym Kodzie Przedmiotu.
bool Lista_zapisow::usun_zapis(string kod_przedmiotu, string numer_indeksu) {
    Zapis *szukany = this->znajdz_zapis(kod_przedmiotu, numer_indeksu);
    Zapis *poprzedni;
    Zapis *element_listy = this->pobierz_poczatek();
    // Jeżeli poszukiwany Zapis był pierwszy zamień tylko początek listy
    if(element_listy == szukany) {
        this->ustaw_poczatek(element_listy->nastepny);
        delete szukany;
        cout <<"Usunieto Zapis o takim kodzie przedmiotu"<<endl;
        return true;
    }
    while (element_listy!=nullptr) {
        if(element_listy == szukany) {
            // Jeżeli poszukiwany Zapis był ostatni zamień koniec listy i wskźnik poprzedniego elementu
            if(this->pobierz_koniec() == element_listy) {
                this->ustaw_koniec(poprzedni);
                poprzedni->nastepny = nullptr;
                delete szukany;
                cout <<"Usunieto Zapis o takim kodzie przedmiotu"<<endl;
                return true;
            }else {
                // Jeżeli poszukiwany Zapis był w środku listy, zamień wskźnik poprzedniego elementu na następny
                poprzedni->nastepny = element_listy -> nastepny;
                delete szukany;
                cout <<"Usunieto Zapis o takim kodzie przedmiotu"<<endl;
                return true;
            }
        }
        poprzedni = element_listy;
        element_listy = element_listy -> nastepny;
    }
    cout <<"W listcie nie ma Zapisu o takim kodzie przedmiotu"<<endl;
    return false;
    
};
