#ifndef TEST_HPP_INCLUDED
#define TEST_HPP_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <random>
#include <ctime>

#include "Algorytm.hpp"
#include "AlgorytmLST.hpp"
#include "AlgorytmBST.hpp"
#include "AlgorytmAVL.hpp"
#include "AlgorytmPOL.hpp"

#include "GenerujDane.hpp"
#include "ZbierajDane.hpp"
// liczba algorytmow
#define LICZBA_ALG 4
// liczba krokow testu glownego
#define LICZBA_KROKOW 10
// liczba danych w jednym kroku
#define JEDEN_KROK 10000
// przez ile dzielic usuwanie i dodawanie
#define LICZBA_PODZIALU 10
// mozliwosc ustawienia generowania bez algorytmu LST (poniewaz za dlugo trwa)
// 0 - generowanie z algorytmem LST
// 1 - generowanie bez algorytmu LST
// nalezy ustawiac na 1 w przypadku generowania danych powyzej 10000 na krok
#define BEZ_ALGORYTMU_LST 0



class Test
{
public:
    Test();
    ~Test();
    void menu ();
    void stworzStruktury();
    void wyszukajElement();
    void policzElementy();
    void wstawElementy();
    void wysokoscDrzewa();
    void testujWszystko();
    void usunElementyzStruktur();
    void wypiszStruktury();
    void usunStruktury();
    void testTablicyPermutowanej();

private:
    Algorytm* tabAlg[LICZBA_ALG];
    Algorytm *testWszyAlg[LICZBA_KROKOW][LICZBA_ALG];
};


#endif // TEST_HPP_INCLUDED
