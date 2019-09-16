Autor: Artur Tkaczyk
Nr. indeksu: 269356

Temat:
Na wejœcie otrzymujemy pewn¹ liczbê paczek o podanych wymiarach. Ka¿da paczka mo¿e pomieœciæ w sobie co najwy¿ej jedn¹ paczkê. Zaproponowaæ algorytm
który oblicza najmniejsz¹ mo¿liw¹ do otrzymania pojemnoœæ wszystkich paczek.

Obs³uga programu:
Program mo¿e byæ wywo³any w jednym z trzech trybów:
- tryb1:
	prog 1 < input > output

	Program pobiera przez standardowe wejœcie dane, a wynik wypisuje na standardowe wyjœcie
	Dane wejœciowe s¹ w postaci ci¹gu dodatnich liczb. Iloœæ liczb musi byæ podzielna przez 3
- tryb2:
	prog 2 n
	
	Program generuje losowe dane o liczbie n, a wynik wypisuje na standardowe wyjœcie
- tryb3:
	prog 3 n k s p

	n - iloœæ danych pocz¹tkowych do wygenerowania
	k - krok, co ile zwiêksza dane
	s - liczba stopni, poziomów o ró¿nej iloœci danych
	p - iloœæ powtórzeñ dla jednego stopnia

W wyniku wywo³ania jednego z dwóch pierwszych trybów wynikiem jest: wynik algorytmu, czas trwania algorytmu
W wyniku wywo³ania trzeciego trybu wynikiem tabela

Rozwi¹zania:
1.Rozwi¹zanie 1:
- Porównujemy wszystkie paczki ze sob¹, ¿eby znaleŸæ wszystkie sytuacje, w których mo¿emy w³o¿yæ jedn¹ paczkê do drugiej.
  Ka¿da paczka ma wskazania na paczki od niej mniejsze i wiêksze
- Dokonujemy sortowania topologicznego. Wszystkie paczki wiêksze znajduj¹ siê teraz na pocz¹tku wektora
- Wywo³ujemy funkcjê rekurencyjn¹, która:
	- Pobiera pierwszy element wektora
	- Przeszukuje wszystkie paczki, które mog¹ siê do niej zmieœciæ i dla ka¿dej z nich ³¹czy paczki
	- Nowy wektor zmniejszony o 1 wysy³a do funkcji rekurencyjnej
	- Zwraca najmniejsz¹ zwrócon¹ wartoœci¹
	- W przypadku, gdy nie ma ani jednej mniejszej paczki, to wywo³uje funkcjê rekurencyjn¹ dla pozosta³ych paczek,
	  a zwrócon¹ wartoœæ dodaje do pojemnoœci pierwszego elementu
2.Rozwi¹zanie 2:
Rozwi¹zanie jest prawie takie samo jak pierwsze. Ró¿nica polega na tym, ¿e w drugim rozwi¹zaniu algorytm usuwa niepotrzebne krawêdzie, a wiêc
zmniejsza liczbe œcie¿ek, którymi nale¿y przejœæ, by znaleŸæ rozwi¹zanie. Niepotrzebne krawêdzie to te, które ³¹cz¹ paczki, które mog¹ mieæ miêdzy
sob¹ jeszcze co najmniej jedn¹ paczkê
np.
gdy  a > b > c
to po³¹czenie miêdzy a i c jest niepotrzebne

Pliki:
main.cpp - interfejs programu
paczka.h - deklaracja klasy "paczka"
paczka.cpp - definicje metod klasy "paczka"
funkcje.h - deklaracja g³ównej funkcji algorytmu, a tak¿e deklaracja funkcji do generowania danych testowych
funkcje.cpp - definicje funkcji z funkcje.h, a tak¿e funkcje pomocnicze do tych funkcji