#include <iostream>
#include <string>
#include <fstream>
#include "../include/Repozytorium.h";
#include "../include/Student.h";
#include "../include/Student.h";

using namespace std;
int main()
{
    Student *stu1 = new Student();
    Repozytorium *rep = new Repozytorium();
    rep->Zapisz_studenta(*stu1);
    return 0;
}

// int main()
// {
//     lista_studentow studenci;
//     studenci.poczatek = nullptr;
//     studenci.koniec = nullptr;
//     while(true)
//     {
//         cout<<"Program zarzadzania zajeciami \n\n\n";
//         cout<<"Wybierz opcje:"<<endl;
//         cout<<"\t1.Dodaj studenta do listy"<< endl;
//         cout<<"\t2.Usun studenta z listy"<< endl;
//         cout<<"\t3.Szukaj studenta po nazwisku"<< endl;
//         cout<<"\t4.Wypisz liste studentow"<< endl;
//         cout<<"\t5.Oposc"<< endl<<endl;
//         int wybor;
//         cin>>wybor;
//         switch(wybor)
//         {
//         case 1:
//             studenci.dodaj_studenta();
//             break;
//         case 4:
//             studenci.wypisz_liste();
//             break;
//         }
//     }
//     return 0;
// }

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
