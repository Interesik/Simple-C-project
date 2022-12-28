#include "../include/Student.h"
#include "../include/Lista_studentow.h"
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
        cout << "Nazwisko:" << (tymcz-> wypisz_nazwisko()) << endl;
        cout << "Imie:" << (tymcz-> wypisz_imie()) << endl;
        cout << "Indeks:" << (tymcz-> wypisz_indeks()) << endl;
        tymcz = tymcz -> nastepny;

    }

}
void Lista_studentow::dodaj_studenta()
{
    Student *nowy = new Student();
    (*nowy).zapisz(nowy->wypisz_imie(), nowy->wypisz_nazwisko(), nowy->wypisz_indeks());
    if (koniec != nullptr ) koniec -> nastepny = nowy;
    nowy -> nastepny = nullptr;
    koniec = nowy;   //trzy wskaźniki ustawilismy
    if(poczatek == nullptr)
    {
        poczatek = nowy;
    }
}
