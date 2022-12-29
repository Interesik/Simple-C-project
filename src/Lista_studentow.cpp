#include "../include/Student.h"
#include "../include/Lista_studentow.h"
#include "../include/Repozytorium.h"
using namespace std;


void Lista_studentow::wypisz_liste()
{
    Student *tymcz = poczatek;
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
void Lista_studentow::dodaj_studenta()
{
    Repozytorium *repo = new Repozytorium();
    Student *nowy = new Student();
    repo->zapisz_studenta(*nowy);
    if (koniec != nullptr ) koniec -> nastepny = nowy;
    nowy -> nastepny = nullptr;
    koniec = nowy;   //trzy wskaźniki ustawilismy
    if(poczatek == nullptr)
    {
        poczatek = nowy;
    }
}
