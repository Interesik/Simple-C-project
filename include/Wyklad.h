
#ifndef Wyklad_H
#define Wyklad_H
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
};
#endif

