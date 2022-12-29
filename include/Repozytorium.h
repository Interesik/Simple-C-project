#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Student;
class Wyklad;
class Zapis;
class Lista_studentow;
class Repozytorium
{
private:
    fstream Student_plik;
    fstream Wyklad_plik;
    fstream Zapis_plik;
public:
    Repozytorium();
    void zapisz_studenta(Student student_zapisz);
    void zapisz_wyklad(Wyklad student_zapisz);
    void zapisz_zapis(Zapis student_zapisz);
    Lista_studentow Wycztaj_studentów();
    ~Repozytorium();
};
