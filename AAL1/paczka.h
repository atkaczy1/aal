#ifndef PACZKA_H
#define PACZKA_H
#include <vector>
#include <iostream>
using namespace std;

class paczka
{
private:
    // Wymiary paczki
    double wymiary[3];
public:
    // Wskazania na paczki wieksze od niej, czyli te, ktore moga pomiescic ta paczke
    vector<paczka*> wieksze;
    // Wskazania na paczki mniejsze od niej, czyli te, ktore moga zostac umieszczone wewnatrz tej paczki
    vector<paczka*> mniejsze;
    paczka()
    {
        wymiary[0] = wymiary[1] = wymiary[2] = 0;
    }
    // Konstruktor ze wszystkimi wymiarami jako argumentami
    // Konstruktor ponadto dokonuje od razu sortowania wymiarow
    // Ma to na celu ulatwienie wyszukania zaleznosci pomiedzy paczkami
    paczka(double a, double b, double c)
    {
        if (a <= b && a <= c)
        {
            wymiary[0] = a;
            if (b <= c) {wymiary[1] = b; wymiary[2] = c;}
            else {wymiary[2] = b; wymiary[1] = c;}
        }
        else if (b <= a && b <= c)
        {
            wymiary[0] = b;
            if (a <= c) {wymiary[1] = a; wymiary[2] = c;}
            else {wymiary[2] = a; wymiary[1] = c;}
        }
        if (c <= a && c <= b)
        {
            wymiary[0] = c;
            if (b <= a) {wymiary[1] = b; wymiary[2] = a;}
            else {wymiary[2] = b; wymiary[1] = a;}
        }
    }
    paczka& operator=(const paczka &x)
    {
        for (int i = 0; i < 3; i++) wymiary[i] = x.wymiary[i];
        return *this;
    }
    // Wyszukuje zaleznosci pomiedzy ta paczka, a paczka p
    // a nastenie jesli ja znajdzie to uzupelnia w obydwu paczkach listy "wieksze" i "mniejsze"
    void sprawdzZaleznosc(paczka &p);
    friend ostream& operator<<(ostream &os, paczka &p);
    friend istream& operator>>(istream &os, paczka &p);
    // Uzupelnia wymiary paczki danymi z tab
    void setD(double tab[])
    {
        for (int i = 0; i < 3; i++) wymiary[i] = tab[i];
    }
    // Uzupelnia tab danymi o wymiarach paczki
    void getD(double tab[])
    {
        for (int i = 0; i < 3; i++) tab[i] = wymiary[i];
    }
    // Zwraca pojemnosc paczki
    double pojemnosc()
    {
        return wymiary[0] * wymiary[1] * wymiary[2];
    }
    // Usuwa wszystkie wskazania na ta paczke, ktore znajduja sie w listach "wieksze", "mniejsze" pozostalych paczek
    void usunPowiazania();
    // Przywraca wszystkie wskazania na ta paczke w listach "wieksze", "mniejsze" powiazanych paczek
    void przywrocPowiazania();
};
#endif // PACZKA_H
