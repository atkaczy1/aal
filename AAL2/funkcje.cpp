// Autor: Artur Tkaczyk
// Nr. indeksu: 269356
//
// Temat:
// Na wejœcie otrzymujemy pewn¹ liczbê paczek o podanych wymiarach. Ka¿da paczka mo¿e pomieœciæ w sobie co najwy¿ej jedn¹ paczkê. Zaproponowaæ algorytm
// który oblicza najmniejsz¹ mo¿liw¹ do otrzymania pojemnoœæ wszystkich paczek.

#include "funkcje.h"
#include <cstdlib>
#define MAX 100

// Funkcja rekurencyjna ktora wyszukuje rozwiazania dla danego wektora paczek
// Funkcja ta "wklada" jedna paczke do drugiej, a nastepnie dla zmniejszonego wektora paczek wywoluje ta sama funkcje
// dane - wektor paczek (takze paczki ktora zawiraja juz inna paczke)
// @return minimalna pojemnosc dla danego wektora paczek
double funkcjaRekurencyjna(vector<paczka*> &dane);

// Kopiuje wektor paczek original do wektora copied
void copyVector(vector<paczka*> &original, vector<paczka*> &copied);

// Usuwa z wektora "dane" wszystkie powiazanie, ktore i tak nie maja zadnego sensu
void zmniejszLiczbeKrawedzi(vector<paczka*> &dane);

void generowanie(vector<paczka*> &dane, int ilosc)
{
    double a, b, c;
    for (int i = 0; i < ilosc; i++)
    {
        a = rand() % MAX + 1;
        b = rand() % MAX + 1;
        c = rand() % MAX + 1;
        paczka *p = new paczka(a, b, c);
        dane.push_back(p);
    }
}
double funkcja(vector<paczka*> &dane)
{
    // Wyszukuje wszystkie zaleznosci pomiedzy paczkami i uzupelnia listy "mniejsze", "wieksze"
    for (int i = 0; i < dane.size() - 1; i++)
    {
        for (int j = i + 1; j < dane.size(); j++)
        {
            (*dane[i]).sprawdzZaleznosc((*dane[j]));
        }
    }

    // Sortowanie topologiczne grafu paczek
    // Wszystkie paczki wieksze znajduja sie przed mniejszymi w wektorze
    for (int i = 0; i < dane.size() - 1; i++)
    {
        for (int j = i; j < dane.size(); j++)
        {
            bool flag = true;
            for (int k = 0; k < dane[j]->wieksze.size(); k++)
            {
                int m;
                for (m = 0; m < i; m++)
                {
                    if (dane[m] == dane[j]->wieksze[k]) break;
                }
                if (m == i)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                paczka *temp = dane[i];
                dane[i] = dane[j];
                dane[j] = temp;
                break;
            }
        }
    }

    // Zmniejsza liczbe powiazan
    zmniejszLiczbeKrawedzi(dane);

    // Wywolanie funkcji rekurencyjnej
    double wynik = funkcjaRekurencyjna(dane);
    return wynik;
}
double funkcjaRekurencyjna(vector<paczka*> &dane)
{
    // Jesli wektor paczek jest pusty, to zwroc 0
    if (dane.size() == 0) return 0;

    // W przypadku, gdy nie ma juz mniejszych paczek od pierwszego elementu wektora
    // Pojemnosc pierwszej paczki jest dodawana do minimalnej pojemnosci wektora dalszych paczek
    if (dane[0]->mniejsze.empty())
    {
        vector<paczka*> x;
        copyVector(dane, x);
        x[0]->usunPowiazania();
        x.erase(x.begin());
        double w = funkcjaRekurencyjna(x);
        for (int i = 0; i < x.size(); i++) delete x[i];
        x.clear();
        return w + dane[0]->pojemnosc();
    }

    // W przypadku, gdy sa mniejsze paczki, algorytm sprawdza wszystkie mozliwosci dokonania nastepnego kroku,
    // a nastepnie zwraca najmniejsza wartosc

    double minimum;
    bool init = false;  // Flaga - Czy wartosc "minimum" zostala juz zainicjowana
    for (int i = 0; i < dane[0]->mniejsze.size(); i++)
    {
        vector<paczka*> x;
        copyVector(dane, x);
        paczka *small = x[0]->mniejsze[i];
        x[0]->usunPowiazania();

        // Przypisz wymiary wiekszej paczki
        double temp[3];
        x[0]->getD(temp);
        small->setD(temp);

        // Usun wszystkie wskazania na mniejsza paczke we wszystkich listach "mniejsze"
        for (int k = 0; k < small->wieksze.size(); k++)
        {
            for (int j = 0; j < small->wieksze[k]->mniejsze.size(); j++)
            {
                if (small->wieksze[k]->mniejsze[j] == small)
                {
                    small->wieksze[k]->mniejsze.erase(small->wieksze[k]->mniejsze.begin() + j);
                    break;
                }
            }
        }

        // Wstawia do listy "wieksze" mniejszej paczki, wartosci z wiekszej paczki, a nastenie uzupelnia wskazania na ta paczke
        small->wieksze.clear();
        for (int j = 0; j < x[0]->wieksze.size(); j++)
        {
            small->wieksze.push_back(x[0]->wieksze[j]);
        }
        for (int j = 0; j < small->wieksze.size(); j++)
        {
            small->wieksze[j]->mniejsze.push_back(small);
        }

        // Usuniecie pierwszego elementu
        x.erase(x.begin());

        // Funkcja rekurencyjna
        double w = funkcjaRekurencyjna(x);

        // Aktualizuje wartosc "minimum"
        if (!init)
        {
            minimum = w;
            init = true;
        }
        else
        {
            if (minimum > w) minimum = w;
        }

        // Czysci wektor x
        for (int i = 0; i < x.size(); i++) delete x[i];
        x.clear();
    }
    return minimum;
}
void copyVector(vector<paczka*> &original, vector<paczka*> &copied)
{
    for (int i = 0; i < copied.size(); i++) delete copied[i];
    copied.clear();
    for (int i = 0; i < original.size(); i++)
    {
        double temp[3];
        original[i]->getD(temp);
        copied.push_back(new paczka(temp[0], temp[1], temp[2]));
    }
    for (int i = 0; i < original.size(); i++)
    {
        for (int j = 0; j < original[i]->mniejsze.size(); j++)
        {
            int k;
            for (k = 0; k < original.size(); k++)
            {
                if (original[k] == original[i]->mniejsze[j]) break;
            }
            copied[i]->mniejsze.push_back(copied[k]);
        }
        for (int j = 0; j < original[i]->wieksze.size(); j++)
        {
            int k;
            for (k = 0; k < original.size(); k++)
            {
                if (original[k] == original[i]->wieksze[j]) break;
            }
            copied[i]->wieksze.push_back(copied[k]);
        }
    }
}
void zmniejszLiczbeKrawedzi(vector<paczka*> &dane)
{
    // indeksy w liscie "mniejsze" ktore nalezy usunac
    vector<int> doUsun;

    for (int i = 0; i < dane.size(); i++)
    {
        for (int j = 0; j < dane[i]->mniejsze.size(); j++)
        {
            bool flag = false;
            for (int k = 0; k < dane[i]->mniejsze.size(); k++)
            {
                for (int m = 0; m < dane[i]->mniejsze[j]->wieksze.size(); m++)
                {
                    if (dane[i]->mniejsze[k] == dane[i]->mniejsze[j]->wieksze[m])
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) doUsun.push_back(j);
        }
        for (int j = doUsun.size() - 1; j >= 0; j--)
        {
            for (int k = 0; k < dane[i]->mniejsze[doUsun[j]]->wieksze.size(); k++)
            {
                if (dane[i]->mniejsze[doUsun[j]]->wieksze[k] == dane[i])
                {
                    dane[i]->mniejsze[doUsun[j]]->wieksze.erase(dane[i]->mniejsze[doUsun[j]]->wieksze.begin() + k);
                    break;
                }
            }
            dane[i]->mniejsze.erase(dane[i]->mniejsze.begin() + doUsun[j]);
        }
        doUsun.clear();
    }
}
