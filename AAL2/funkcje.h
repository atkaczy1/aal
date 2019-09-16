// Autor: Artur Tkaczyk
// Nr. indeksu: 269356
//
// Temat:
// Na wej�cie otrzymujemy pewn� liczb� paczek o podanych wymiarach. Ka�da paczka mo�e pomie�ci� w sobie co najwy�ej jedn� paczk�. Zaproponowa� algorytm
// kt�ry oblicza najmniejsz� mo�liw� do otrzymania pojemno�� wszystkich paczek.

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
