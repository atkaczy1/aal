#include "paczka.h"

ostream& operator<<(ostream &os, paczka &p)
{
    for (int i = 0; i < 3; i++) os << p.wymiary[i];
    return os;
}
istream& operator>>(istream &is, paczka &p)
{
    double a, b, c;
    is >> a;
    is >> b;
    is >> c;
    paczka x(a, b, c);
    p = x;
    return is;
}
void paczka::sprawdzZaleznosc(paczka &p)
{
    if (wymiary[0] < p.wymiary[0])          // Jest mozliwosc, ze pierwsza paczka moze zmiescic sie do drugiej paczki
    {
        if (wymiary[1] < p.wymiary[1] && wymiary[2] < p.wymiary[2])     // Pierwsza paczka moze zmiescic sie do drugiej paczki
        {
            wieksze.push_back(&p);
            p.mniejsze.push_back(this);
        }
    }
    else if (wymiary[0] > p.wymiary[0])     // Jest mozliwosc, ze druga paczka moze zmiescic sie do pierwszej paczki
    {
        if (wymiary[1] > p.wymiary[1] && wymiary[2] > p.wymiary[2])     // Druga paczka moze zmiescic sie do pierwszej paczki
        {
            mniejsze.push_back(&p);
            p.wieksze.push_back(this);
        }
    }
}
void paczka::usunPowiazania()
{
    for (int i = 0; i < mniejsze.size(); i++)       // Usuwa wszystkie wskazania mniejszych paczek na ta paczke
    {
        for (int j = 0; j < mniejsze[i]->wieksze.size(); j++)   // Wyszukuje wskazania
        {
            if (mniejsze[i]->wieksze[j] == this) {mniejsze[i]->wieksze.erase(mniejsze[i]->wieksze.begin() + j); break;}
        }
    }
    for (int i = 0; i < wieksze.size(); i++)       // Usuwa wszystkie wskazania wiekszych paczek na ta paczke
    {
        for (int j = 0; j < wieksze[i]->mniejsze.size(); j++)   // Wyszukuje wskazania
        {
            if (wieksze[i]->mniejsze[j] == this) {wieksze[i]->mniejsze.erase(wieksze[i]->mniejsze.begin() + j); break;}
        }
    }
}
void paczka::przywrocPowiazania()
{
    for (int i = 0; i < mniejsze.size(); i++)
    {
        mniejsze[i]->wieksze.push_back(this);
    }
    for (int i = 0; i < wieksze.size(); i++)
    {
        wieksze[i]->mniejsze.push_back(this);
    }
}
