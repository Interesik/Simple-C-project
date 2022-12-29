#include <string>
using namespace std;
class Zapis
{
private:
    string numer_indeksu;
    string kod_przedmiotu;
public:
    Zapis();
    Zapis(string numer_indeksu, string kod_przedmiotu);
    ~Zapis();
    string pobierz_numer_indeksu();
    string pobierz_kod_przedmiotu();
};
