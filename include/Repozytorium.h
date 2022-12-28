#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Student;
class Wyklad;
class Zapis;
class Repozytorium
{
private:
    fstream Student_plik;
    fstream Wyklad_plik;
    fstream Zapis_plik;
public:
    Repozytorium();
    void Zapisz_studenta(Student student_zapisz);
    void Zapisz_wyklad(Wyklad student_zapisz);
    void Zapisz_zapis(Zapis student_zapisz);
    ~Repozytorium();
};
