#include <stdlib.h>

#include "Test.hpp"

using namespace std;

// brak wczytywania elementów do tablicy - poprawione (dodanie wywolanie funkcji)
// przy liczeniu wysokosci drzewa ostatni lisc zawsze zwracal 0 (poprawione - pusty lisc zwraca wysokosc)

int main()
{
    Test test = Test();
    test.menu();
    return 0;
}
