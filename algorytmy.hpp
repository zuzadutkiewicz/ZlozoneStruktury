#ifndef ALGORYTMY_HPP_INCLUDED
#define ALGORYTMY_HPP_INCLUDED

class Algorytm{
public:
    Algorytm(ZbierajDane zbierajDane);
    virtual void utworz();
    virtual void szukaj();
    virtual void usunEle();
    virtual void usunWszy();
    virtual void szukajEle();
    virtual void dodajEle();

protected:
    ZbierajDane zbierajDane;

    };

#endif // ALGORYTMY_HPP_INCLUDED
