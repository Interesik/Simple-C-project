#include <iostream>
#include <string>
#include <fstream>
#include"klasy.h"
using namespace std;


  //napisz funkcje "wypisz_menu"
    // trzeba wywo³ywac ró¿nego rodzaju funkcje => switch case
    // potrzebne klasy student  => class Student
    // imie, naziwko, nr indeksu, wskaŸnik na element nast
    //
    //
/*
class student
{
private:
    string nazwisko;
    string imie;
    string nr_indeksu;
public:
    void zapisz(string, string, string);
    string wypisz_nazwisko();
    string wypisz_imie();
    string wypisz_nr_indeksu();
    student *nastepny;
};

//osobna klasa do ka¿dej listy
class lista_studentow
{
public:
    lista_studentow(); //konstruktor
    student *poczatek;
    student *znajdz_studenta_nazwisko(string); //funkcja która przyjmuje np. nazwisko lub indeks
    student *znajdz_studenta_indeks(string);
                                                //mozna oddac mase funkcji

};
*/

void usun_studenta();
void szukaj_studenta();


int main()
{
    lista_studentow studenci;
    studenci.poczatek = nullptr;
    studenci.koniec = nullptr;
    while(true)
    {
        cout<<"Program zarzadzania zajeciami \n\n\n";
        cout<<"Wybierz opcje:"<<endl;
        cout<<"\t1.Dodaj studenta do listy"<< endl;
        cout<<"\t2.Usun studenta z listy"<< endl;
        cout<<"\t3.Szukaj studenta po nazwisku"<< endl;
        cout<<"\t4.Wypisz liste studentow"<< endl;
        cout<<"\t5.Oposc"<< endl<<endl;
        int wybor;
        cin>>wybor;
        switch(wybor)
        {
        case 1:
            studenci.dodaj_studenta();
            break;
        case 4:
            studenci.wypisz_liste();
            break;
        }
    }
    return 0;
}

/*
int main()
{
    ofstream fout("tmp.txt");
    fout.open("tmp.txt");
    fout<<"to jest";
    fout.close();
}

int main()
{
    fstream fin("tmp.txt");
    string str{};
    fin>>str;
    cout <<str;
    fin.close();

}


int main()
{
    ofstream fout("tmp.txt",ios::out~ala'flaga'|ios::app );
}
    ifstream fin("tmp.txt");
    char znak;
    while(!fin.eof()&&(in-> znak))   //(fin.get(znak))
        {
        fin>>znak;
        count<<"znak:"<<znak<<endl;
    }
*/
