#ifndef GENERUJDANE_HPP_INCLUDED
#define GENERUJDANE_HPP_INCLUDED

class GenerujDane
{
public:
    void dajDane(int tab[],int liczbaElem);
    void dajDane(int tab[], int liczbaElem, int tab1[], int liczElem1);
    void dajDanePermutowane(int tab[], int liczbaElem);
private:
    bool jestWTablicy(int tab[], int licznik, int value);
};

#endif // GENERUJDANE_HPP_INCLUDED
