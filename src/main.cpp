#include <iostream>
#include <string>
#include <fstream>
#include "../include/Repozytorium.h"

#include "../include/Student.h"
#include "../include/Wyklad.h"
#include "../include/Zapis.h"

#include "../include/Lista_studentow.h"
#include "../include/Lista_wykladow.h"
#include "../include/Lista_zapisow.h"

using namespace std;
// int main()
// {
//     Repozytorium *rep = new Repozytorium();
//     rep->zapisz_studenta(Student());
//     Lista_studentow *ls = rep->wycztaj_studentow();
//     ls->wypisz_liste();
//     Student* znaleziony = ls->znajdz_studenta_indeks("123");
//     cout << znaleziony->pobierz_nazwisko() << endl;
//     rep->wypisz_studenta("123", *ls);
//     ls->wypisz_liste();
//     delete znaleziony;
//     delete rep;
//     return 0;
    
// }

int main()
{   
    cofnij: ;
    while(true) {
        Repozytorium *rep = new Repozytorium();
        cout<<"Program zarzadzania zajeciami \n\n\n";
        cout<< "Wybierz opcje:" << endl;
        cout<<"\t1.Zarzadzaj Studentami"<< endl;
        cout<<"\t2.Zarzadzaj Wykladami"<< endl;
        cout<<"\t3.Zarzadzaj Zapisami"<< endl;
        cout<<"\t4.Oposc\n\n";
        int wybor;
        cin>>wybor;
        switch(wybor){
            case 1:  
                while(true) {
                    Lista_studentow *ls;
                    cout<<"Wybierz opcje:"<<endl;
                    cout<<"\t1.Dodaj studenta do listy"<< endl;
                    cout<<"\t2.Usun studenta z listy"<< endl;
                    cout<<"\t3.Szukaj studenta po nazwisku"<< endl;
                    cout<<"\t4.Szukaj studenta po indeksie"<< endl;
                    cout<<"\t5.Wypisz liste studentow"<< endl;
                    cout<<"\t6.Cofnij"<< endl<<endl;
                    int wybor;
                    cin>>wybor;
                    string imie, nazwisko, indeks;
                    switch(wybor)
                    {
                    case 1:
                        rep->zapisz_studenta(Student());
                        break;
                    case 2:
                        cout << "Podaj indeks studenta, do wypisania z listy: ";
                        cin >> indeks;
                        ls = rep->wycztaj_studentow();
                        rep->wypisz_studenta(indeks,*ls);
                        goto cofnij;
                    case 3:
                        cout << "Podaj nazwisko studenta, do wyswietlenia go z listy: ";
                        cin >> nazwisko;
                        ls = rep->wycztaj_studentow();
                        ls->znajdz_studenta_nazwisko(nazwisko);
                        goto cofnij;
                    case 4:
                        cout << "Podaj indeks studenta, do wyswietlenia go z listy: ";
                        cin >> indeks;
                        ls = rep->wycztaj_studentow();
                        ls->znajdz_studenta_indeks(indeks);
                        goto cofnij;
                    case 5:
                        ls = rep->wycztaj_studentow();
                        ls->wypisz_liste();
                        goto cofnij;
                    case 6:
                        ls = rep->wycztaj_studentow();
                        delete ls;
                        delete rep;
                        goto cofnij;
                    default:
                        cout <<"Podaj liczbe nastepnym razem." << endl;
                        break;
                    }
                }
                break;
            case 2:
                while(true) {
                    Lista_wykladow *lw;
                    cout<<"Wybierz opcje:"<<endl;
                    cout<<"\t1.Dodaj wyklad do listy"<< endl;
                    cout<<"\t2.Usun wyklad z listy"<< endl;
                    cout<<"\t3.Szukaj wyklad po nazwisku prowadzacego"<< endl;
                    cout<<"\t4.Szukaj wyklad po kodzie przedmiotu"<< endl;
                    cout<<"\t5.Szukaj wyklad po nazwie przedmiotu"<< endl;
                    cout<<"\t6.Wypisz liste wykladow"<< endl;
                    cout<<"\t7.Cofnij"<< endl<<endl;
                    int wybor;
                    cin>>wybor;
                    string nazwisko_prowadzacego, nazwa_przedmiotu, kod_przedmiotu;
                    switch(wybor)
                    {
                    case 1:
                    {
                        rep->zapisz_wyklad(Wyklad());
                        break;
                    }
                    case 2:
                        cout << "Podaj kod przedmiotu, do wypisania z listy: ";
                        cin >> kod_przedmiotu;
                        lw = rep->wycztaj_wyklady();
                        rep->anuluj_wyklad(kod_przedmiotu,*lw);
                        goto cofnij;
                    case 3:
                        cout << "Podaj nazwisko prowadzacego, do wyswietlenia go z listy: ";
                        cin >> nazwisko_prowadzacego;
                        lw = rep->wycztaj_wyklady();
                        lw->znajdz_wyklad_po_nazwisko_prowadzacego(nazwisko_prowadzacego);
                        goto cofnij;
                    case 4:
                        cout << "Podaj kod przedmiotu, do wyswietlenia go z listy: ";
                        cin >> kod_przedmiotu;
                        lw = rep->wycztaj_wyklady();
                        lw->znajdz_wyklad_po_kod_przedmiotu(kod_przedmiotu);
                        goto cofnij;
                    case 5:
                        cout << "Podaj nazwe przedmiotu, do wyswietlenia go z listy: ";
                        cin >> nazwa_przedmiotu;
                        lw = rep->wycztaj_wyklady();
                        lw->znajdz_wyklad_po_nazwa_przedmiotu(nazwa_przedmiotu);
                        goto cofnij;
                    case 6:
                        lw = rep->wycztaj_wyklady();
                        lw->wypisz_liste();
                        goto cofnij;
                    case 7:
                        lw = rep->wycztaj_wyklady();
                        delete lw;
                        delete rep;
                        goto cofnij;
                    default:
                        cout <<"Podaj liczbe nastepnym razem." << endl;
                        break;
                    }
                }
                break;
            case 3:
                while(true) {
                    Lista_zapisow *lz;
                    cout<<"Wybierz opcje:"<<endl;
                    cout<<"\t1.Dodaj zapis do listy"<< endl;
                    cout<<"\t2.Usun zapis z listy"<< endl;
                    cout<<"\t3.Szukaj zapis"<< endl;
                    cout<<"\t4.Wypisz liste zapisow"<< endl;
                    cout<<"\t5.Cofnij"<< endl<<endl;
                    int wybor;
                    cin>>wybor;
                    string kod_przedmiotu, numer_indeksu;
                    switch(wybor)
                    {
                    case 1:
                    {
                        rep->zapisz_zapis(Zapis());
                        break;
                    }
                    case 2:
                        cout << "Podaj kod przedmiotu, do usuniecia go z listy: ";
                        cin >> kod_przedmiotu;
                        cout << "\nPodaj numer indeksu, do usuniecia go z listy: ";
                        cin >> numer_indeksu;
                        lz = rep->wycztaj_zapisy();
                        rep->anuluj_zapis(kod_przedmiotu, numer_indeksu, *lz);
                        goto cofnij;
                    case 3:
                        cout << "Podaj kod przedmiotu, do wyświetlenia go z listy: ";
                        cin >> kod_przedmiotu;
                        cout << "\nPodaj numer indeksu, do wyświetlenia go z listy: ";
                        cin >> numer_indeksu;
                        lz = rep->wycztaj_zapisy();
                        lz->znajdz_zapis(kod_przedmiotu, numer_indeksu);
                        goto cofnij;
                    case 4:
                        lz = rep->wycztaj_zapisy();
                        lz->wypisz_liste();
                        goto cofnij;
                    case 5:
                        lz = rep->wycztaj_zapisy();
                        delete lz;
                        delete rep;
                        goto cofnij;
                    default:
                        cout <<"Podaj liczbe nastepnym razem." << endl;
                        break;
                    }
                }
                break;
            case 4:
                delete rep;
                return 0;
            break;
        }
    }
}

