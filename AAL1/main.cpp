#include <iostream>
#include <sstream>
#include "paczka.h"
#include "funkcje.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <cstdio>
#include <cmath>

using namespace std;
typedef std::chrono::high_resolution_clock Clock;

double T(int n);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "ERR: Za malo argumentow";
        return -1;
    }
    srand(time(NULL));
    vector<paczka*> dane;
    stringstream ss;
    int tryb;
    ss << argv[1];
    ss >> tryb;
    if (tryb == 1)
    {
        // Wczytuje dane z wejscia
        while (!cin.eof())
        {
            paczka *x = new paczka;
            cin >> *x;
            dane.push_back(x);
        }
        auto t1 = Clock::now();
        cout << funkcja(dane);
        auto t2 = Clock::now();
        cout << " " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "ms" << endl;
        for (int i = 0; i < dane.size(); i++) delete dane[i];
    }
    else if (tryb == 2)
    {
        if (argc < 3)
        {
            cout << "ERR: Za malo argumentow";
            return -1;
        }
        // Ilosc paczek
        int ilosc_danych;
        ss.clear();
        ss << argv[2];
        ss >> ilosc_danych;
        generowanie(dane, ilosc_danych);
        auto t1 = Clock::now();
        cout << funkcja(dane);
        auto t2 = Clock::now();
        cout << " " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "ms" << endl;
        for (int i = 0; i < dane.size(); i++) delete dane[i];
    }
    else if (tryb == 3)
    {
        if (argc < 6)
        {
            cout << "ERR: Za malo argumentow";
            return -1;
        }
        // Poczatkowa wartosc - ilosc paczek
        int ilosc_start;
        ss.clear();
        ss << argv[2];
        ss >> ilosc_start;
        int poczatek = ilosc_start;
        // Odstep do nastepnej wyliczanej ilosci paczek
        int krok;
        ss.clear();
        ss << argv[3];
        ss >> krok;
        // Ilosc stopni o roznych ilosciach paczek
        int ilosc;
        ss.clear();
        ss << argv[4];
        ss >> ilosc;
        // Ilosc powtorzen dla kazdego stopnia
        int powtorzenia;
        ss.clear();
        ss << argv[5];
        ss >> powtorzenia;
        // Tabela z czasami dla kazdego stopnia
        long wyniki[ilosc];
        for (int i = 0; i < ilosc; i++) wyniki[i] = 0;
        for (int i = 0; i < ilosc; i++)
        {
            for (int j = 0; j < powtorzenia; j++)
            {
                generowanie(dane, ilosc_start);
                auto t1 = Clock::now();
                cout << funkcja(dane);
                auto t2 = Clock::now();
                wyniki[i] += (long) std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
                cout << endl;
                for (int k = 0; k < dane.size(); k++) delete dane[k];
                dane.clear();
            }
            ilosc_start += krok;
            wyniki[i] /= powtorzenia;
        }
        int mediana = ilosc / 2;
        int n_mediana = poczatek + mediana * krok;
        printf("       n    t(n)    q(n)\n");
        for (int i = 0; i < ilosc; i++)
        {
            printf("%8d", poczatek);
            printf("%8d", wyniki[i]);
            printf("%8.2f\n", (wyniki[i] * T(n_mediana))/(T(poczatek) * wyniki[mediana]));
            poczatek += krok;
        }
    }
    else
    {
        cout << "ERR: Nie ma takiego trybu";
        return -1;
    }
    return 0;
}
double T(int n)
{
    return pow(n, n);
}
