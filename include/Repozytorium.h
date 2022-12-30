#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Student;
class Wyklad;
class Zapis;
class Lista_studentow;
class Lista_wykladow;
class Lista_zapisow;
class Repozytorium
{
private:
    fstream Student_plik;
    fstream Wyklad_plik;
    fstream Zapis_plik;
    ifstream Student_plik_odcz;
    ifstream Wyklad_plik_odcz;
    ifstream Zapis_plik_odcz;
public:
    Repozytorium();
    ~Repozytorium();
    void zapisz_studenta(Student student_zapisz);
    void zapisz_wyklad(Wyklad student_zapisz);
    void zapisz_zapis(Zapis student_zapisz);
    Lista_studentow wycztaj_studentow();
    Lista_wykladow wycztaj_wyklady();
    Lista_zapisow wycztaj_zapisy();
};
