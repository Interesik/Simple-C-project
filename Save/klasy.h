#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class student
{
private:
    string nazwisko;
    string imie;
    string indeks;
public:
    void zapisz(string, string, string);
    string wypisz_nazwisko(){return nazwisko;}
    string wypisz_imie(){return imie;}
    string wypisz_indeks(){return indeks;}
    student *nastepny;
};

void student::zapisz(string nazw,string im,string ind)
{
    nazwisko = nazw;
    imie = im;
    indeks = ind;

}

//osobna klasa do ka¿dej listy
class lista_studentow
{
public:
 //   lista_studentow(); //konstruktor
    student *poczatek;
    student *koniec;
 //   student *znajdz_studenta_nazwisko(string); //funkcja która przyjmuje np. nazwisko lub indeks
  //  student *znajdz_studenta_indeks(string);
    void dodaj_studenta();
    void wypisz_liste();
                                                //mozna oddac mase funkcji

};
void lista_studentow::wypisz_liste()
{
    student *tymcz = poczatek;
    if (tymcz == nullptr)
    {
        cout <<"Lista jest pusta"<<endl;
        return;
    }
    int i =1;
    while (tymcz!=nullptr)
    {
        cout << "Student nr" << i++ << ":" << endl;
        cout << "Nazwisko:" << (tymcz-> wypisz_nazwisko()) << endl;
        cout << "Imie:" << (tymcz-> wypisz_imie()) << endl;
        cout << "Indeks:" << (tymcz-> wypisz_indeks()) << endl;
        tymcz = tymcz -> nastepny;

    }

}

void lista_studentow::dodaj_studenta()
{
    student *nowy = new student;
    string nazwisko,imie,indeks;
    cout<<"Prosze podac nazwisko:";
    cin>>nazwisko;
    cout<<"Prosze podac imie:";
    cin>>imie;
    cout<<"Prosze podac numer indeksu:";
    cin>>indeks;
    (*nowy).zapisz(nazwisko,imie,indeks);
    if (koniec != nullptr ) koniec -> nastepny = nowy;
    nowy -> nastepny = nullptr;
    koniec = nowy;   //trzy wskaźniki ustawilismy
    if(poczatek == nullptr)
    {
        poczatek = nowy;
    }





}
