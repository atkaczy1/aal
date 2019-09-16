#ifndef FUNKCJE_H
#define FUNKCJE_H
#include <vector>
#include "paczka.h"

// Generowanie danych wejsciowych dla algorytmu
// dane - vector paczek, ktory bedzie uzupelniony losowymi danymi z tej funkcji
// ilosc - ilosc paczek do wylosowania
void generowanie(vector<paczka*> &dane, int ilosc);
// Glowna funkcja dla algorytmu
// Jej zadaniem jest przygotowanie danych wejsciowych (stworzenie polaczen miedzy paczkami itp.),
// a nastepnie wywoluje dla nich funkcje rekurencyjna
// dane - dane wejsciowe
// @return pojemnosc pozostalych paczek - wynik koncowy algorytmu
double funkcja(vector<paczka*> &dane);

#endif // FUNKCJE_H
