
#include "Test.hpp"
//zbierajDane->dodajDoListy("INIT", NazwaAlgorytmu, LiczbaInitEle, 0, ((1000*(clock()-start))/CLOCKS_PER_SEC));
Test::Test()
{
    tabAlg[0] = new AlgorytmLST();
    tabAlg[1] = new AlgorytmBST();
    tabAlg[2] = new AlgorytmAVL();
    tabAlg[3] = new AlgorytmPOL();

    // inicjowanie tablicy dla testu wszystkiego

    for(int i = 0; i < LICZBA_KROKOW; i++)
    {
        testWszyAlg[i][0] = new AlgorytmLST();
        testWszyAlg[i][1] = new AlgorytmBST();
        testWszyAlg[i][2] = new AlgorytmAVL();
        testWszyAlg[i][3] = new AlgorytmPOL();
    }

}

Test::~Test()
{
    delete(tabAlg[0]);
    delete(tabAlg[1]);
    delete(tabAlg[2]);
    delete(tabAlg[3]);

    for(int i = 0; i < LICZBA_KROKOW; i++)
    {
        delete(testWszyAlg[i][0]);
        delete(testWszyAlg[i][1]);
        delete(testWszyAlg[i][2]);
        delete(testWszyAlg[i][3]);
    }

}

void Test::menu ()
{
    int opcja_prog = 0;
    while(true)
    {
        printf("Program zaliczeniowy Zuzana Dutkiewicz.\n");
        printf("Wybierz opcje programu.\n");
        printf(" 1.Stworz struktury.\n");
        printf(" 2.Wyszukaj element.\n");
        printf(" 3.Wstaw elementy do struktur.\n");
        printf(" 4.Usun element z struktur.\n");
        printf(" 5.Wypisz struktury w kolejnosci uporzadkowanej.\n");
        printf(" 6.Usun struktury.\n");
        printf(" 7.Policz elementy.\n");
        printf(" 8.Wysokosc drzewa\n");
        printf(" 9.Testuj wszystko\n");
        printf("10.Test tablicy permutowanej\n");
        printf(" 0. Zakoncz dzialanie programu.\n");
        printf("\nOpcja: ");
        scanf("%d", &opcja_prog);

        if (opcja_prog == 0)
            return;
        switch(opcja_prog)
        {
        case 1:
            stworzStruktury();
            break;
        case 2:
            wyszukajElement();
            break;
        case 3:
            wstawElementy();
            break;
        case 4:
            usunElementyzStruktur();
            break;
        case 5:
            wypiszStruktury();
            break;
        case 6:
            break;
        case 7:
            policzElementy();
            break;
        case 8:
            wysokoscDrzewa();
            break;
        case 9:
            testujWszystko();
            break;
        case 10:
            testTablicyPermutowanej();
            break;
        default:
            printf("Niepoprawna opcja!!!\n");
            break;
        }
    }
}

void Test::stworzStruktury()
{
    int a = 0;
    int b = 0;
    int liczbaElem = 0;
    int liczbaElem1 = 0;


    printf("7.Struktura losowa.\n8.Struktura podana przez uzytkownika.\n");
    scanf("%d", &a);
    if (a==7)
    {
        printf("Podaj liczbe elementow, ktora chcesz dodac.\n");
        scanf("%d", &liczbaElem);
        int *tab = new int[liczbaElem];
        GenerujDane generujDane;
        generujDane.dajDane(tab, liczbaElem);
        for (int i = 0; i<LICZBA_ALG; i++)
        {
            tabAlg[i]->usunWszystko();
            tabAlg[i]->dodajElementy(tab,liczbaElem);
        }
    }
    else if (a==8)
    {
        printf("Podaj ilosc elementow(liczba naturalna)\n");
        scanf("%d", &liczbaElem1);
        int *tab1 = new int[liczbaElem1];
        for(int i=0; i<liczbaElem1; i++)

        {
            printf("Podaj wartosc elementu\n");
            scanf("%d",&b);
            tab1[i] = b;
        }
        for (int i = 0; i<LICZBA_ALG; i++)
        {
            tabAlg[i]->usunWszystko();
            tabAlg[i]->dodajElementy(tab1,liczbaElem1);
        }
    }
    else
    {
        printf("Wybrales nie poprawna opcje\n.");
        return;
    }

}


void Test::wyszukajElement()
{
    int eleSzuk = 0;
    printf("Podaj element, ktory chcesz wyszukac:\n");
    scanf("%d", &eleSzuk);
    for (int i = 0; i<LICZBA_ALG; i++)
    {
        tabAlg[i]->szukajEle(eleSzuk);
    }
}

void Test::policzElementy()
{
    int liczbaElem;
    for (int i = 0; i<LICZBA_ALG; i++)
    {
        liczbaElem = tabAlg[i]->policzElementy();
        printf("Algorym %s liczba elementow %d\n",
               tabAlg[i]->dajNazwaAlgorytmu().c_str(),
               liczbaElem);
    }
}

void Test::wstawElementy()
{
    int a = 0;
    int b = 0;
    int liczbaElem = 0;
    int liczbaElem1 = 0;
    int liczbaElem2 = 0;

    printf("7.Struktura losowa.\n8.Struktura podana przez uzytkownika.\n");
    scanf("%d", &a);
    if (a==7)
    {
        printf("Podaj liczbe elementow, ktora chcesz dodac.\n");
        scanf("%d", &liczbaElem);
        int *tab = new int[liczbaElem];
        GenerujDane generujDane;
        liczbaElem2 = tabAlg[0]->policzElementy();
        int *tab1 = new int[liczbaElem2];
        tabAlg[0]->dajTablice(tab1);
        generujDane.dajDane(tab, liczbaElem, tab1, liczbaElem2);
        for (int i = 0; i<LICZBA_ALG; i++)
        {
            tabAlg[i]->dodajElementy(tab,liczbaElem);
        }
    }
    else if (a==8)
    {
        printf("Podaj ilosc elementow(liczba naturalna)\n");
        scanf("%d", &liczbaElem1);
        int *tab1 = new int[liczbaElem1];
        for(int i=0; i<liczbaElem1; i++)

        {
            printf("Podaj wartosc elementu\n");
            scanf("%d",&b);
            tab1[i] = b;
        }
        for (int i = 0; i<LICZBA_ALG; i++)
        {
            tabAlg[i]->dodajElementy(tab1,liczbaElem1);
        }
    }
    else
    {
        printf("Wybrales nie poprawna opcje\n.");
        return;
    }
}

void Test::wysokoscDrzewa()
{
    for (int i = 0; i<LICZBA_ALG; i++)
    {
        cout << "Algorytm " << tabAlg[i]->dajNazwaAlgorytmu()
             << " Liczba elementow: " << tabAlg[i]->policzElementy()
             << " Wysokosc drzewa: " << tabAlg[i]->wysokoscDrzewa() << endl;
    }
}

void Test::testujWszystko()
{
    // wygenerowanie tablicy pomocniczej
    GenerujDane generujDane;
    ZbierajDane zbierajDane;

    cout << "Test::testujWszystko:generowanie danych" << endl;

    int *tab = new int[LICZBA_KROKOW * JEDEN_KROK + LICZBA_KROKOW * JEDEN_KROK / LICZBA_PODZIALU];

    generujDane.dajDanePermutowane(tab, LICZBA_KROKOW * JEDEN_KROK +
                        LICZBA_KROKOW * JEDEN_KROK  / LICZBA_PODZIALU );
    cout << "Test::testujWszystko:inicjuj" << endl;
    // inicjowanie elementow
    for(int j = 0; j < LICZBA_KROKOW; j++)
        for (int i = BEZ_ALGORYTMU_LST; i<LICZBA_ALG; i++)
        {
            clock_t start = clock();
            testWszyAlg[j][i]->dodajElementy(tab, j * JEDEN_KROK + JEDEN_KROK);
            zbierajDane.dodajDoListy("INIT",
                                     testWszyAlg[j][i]->dajNazwaAlgorytmu(),
                                     testWszyAlg[j][i]->wysokoscDrzewa(),
                                     testWszyAlg[j][i]->dajLiczbaInitEle(),
                                     0,
                                     ((1000*(clock()-start))/CLOCKS_PER_SEC));
        }

    int *tabDodajUsun = &tab[LICZBA_KROKOW * JEDEN_KROK];

    // dodawanie elementow

    cout << "Test::testujWszystko:dodaj" << endl;
    for(int j = 0; j < LICZBA_KROKOW; j++)
        for (int i = BEZ_ALGORYTMU_LST; i<LICZBA_ALG; i++)
        {
            clock_t start = clock();
            testWszyAlg[j][i]->dodajElementy(tabDodajUsun, (j * JEDEN_KROK + JEDEN_KROK) / LICZBA_PODZIALU);
            zbierajDane.dodajDoListy("DODAJ",
                                     testWszyAlg[j][i]->dajNazwaAlgorytmu(),
                                     testWszyAlg[j][i]->wysokoscDrzewa(),
                                     testWszyAlg[j][i]->dajLiczbaInitEle(),
                                     (j * JEDEN_KROK + JEDEN_KROK) / LICZBA_PODZIALU,
                                     ((1000*(clock()-start))/CLOCKS_PER_SEC));
        }

    // usuwanie elementow

    cout << "Test::testujWszystko:usun" << endl;
    for(int j = 0; j < LICZBA_KROKOW; j++)
        for (int i = BEZ_ALGORYTMU_LST; i<LICZBA_ALG; i++)
        {
            clock_t start = clock();
            testWszyAlg[j][i]->usunElementy(tabDodajUsun, (j * JEDEN_KROK + JEDEN_KROK) / LICZBA_PODZIALU);
            zbierajDane.dodajDoListy("USUN",
                                     testWszyAlg[j][i]->dajNazwaAlgorytmu(),
                                     testWszyAlg[j][i]->wysokoscDrzewa(),
                                     testWszyAlg[j][i]->dajLiczbaInitEle(),
                                     (j * JEDEN_KROK + JEDEN_KROK) / LICZBA_PODZIALU,
                                     ((1000*(clock()-start))/CLOCKS_PER_SEC));
        }


    // czyszczenie danych

    delete(tab);
    cout << "Test::testujWszystko:usunWszystko" << endl;
    for(int j = 0; j < LICZBA_KROKOW; j++)
        for (int i = BEZ_ALGORYTMU_LST; i<LICZBA_ALG; i++)
        {
            int liczbaInitElem = testWszyAlg[j][i]->dajLiczbaInitEle();
            int liczbaElem = testWszyAlg[j][i]->policzElementy();
            clock_t start = clock();
            testWszyAlg[j][i]->usunWszystko();
            zbierajDane.dodajDoListy("USUNW",
                                     testWszyAlg[j][i]->dajNazwaAlgorytmu(),
                                     testWszyAlg[j][i]->wysokoscDrzewa(),
                                     liczbaInitElem,
                                     liczbaElem,
                                     ((1000*(clock()-start))/CLOCKS_PER_SEC));
        }

    zbierajDane.wyswietl();

    return;
}

void Test::usunElementyzStruktur()
{
    int elemDoUsu;

    printf("Podaj element, ktory chcesz usunac:\n");
    scanf("%d", &elemDoUsu);
    for (int i = 0; i<LICZBA_ALG; i++)
    {
        tabAlg[i]->usunEle(elemDoUsu);
    }
    return;

}

void Test::wypiszStruktury()
{
    for (int i = 0; i<LICZBA_ALG; i++)
    {
        cout << "Algorytm " << tabAlg[i]->dajNazwaAlgorytmu()<<endl;
        tabAlg[i]->wyswietlPosortowane();
    }
    return;
}

void Test::usunStruktury()
{
    for (int i = 0; i<LICZBA_ALG; i++)
    {
        tabAlg[i]->usunWszystko();
    }
    return;
}

void Test::testTablicyPermutowanej()
{
    int liczElem = 200000;
    int *tab = new int[liczElem];
    GenerujDane generujDane = GenerujDane();
    clock_t start = 0;

    printf("testTablicyPermutowanej:poczatek liczba elementow=%d\n", liczElem);
    start = clock();
    generujDane.dajDanePermutowane(tab, liczElem);
    // for(int i = 0; i < liczElem; i++)
    //    printf("tab[%d]=%d\n", i, tab[i]);
    printf("testTablicyPermutowanej:koniec czas=%d\n", (int)((1000*(clock()-start))/CLOCKS_PER_SEC));

    printf("testTablicySprawdzanej:poczatek\n");
    start = clock();
    generujDane.dajDane(tab, liczElem);
    // for(int i = 0; i < liczElem; i++)
    //    printf("tab[%d]=%d\n", i, tab[i]);
    printf("testTablicySprawdzanej:koniec czas=%d\n", (int)((1000*(clock()-start))/CLOCKS_PER_SEC));

}
