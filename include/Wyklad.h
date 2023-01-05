#include <string>
using namespace std;

class Wyklad
{
private:
    string nazwa_przedmiotu;
    string nazwisko_prowadzacego;
    string kod_przedmiotu;
public:
    Wyklad();

    Wyklad(string nazwa_przedmiotu, string nazwisko_prowadzacego, 
            string kod_przedmiotu);

    ~Wyklad();

    string pobierz_nazwa_przedmiotu();

    string pobierz_nazwisko_prowadzacego();

    string pobierz_kod_przedmiotu();
    
    Wyklad *nastepny;
};


