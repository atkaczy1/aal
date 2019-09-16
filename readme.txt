Autor: Artur Tkaczyk
Nr. indeksu: 269356

Temat:
Na wej�cie otrzymujemy pewn� liczb� paczek o podanych wymiarach. Ka�da paczka mo�e pomie�ci� w sobie co najwy�ej jedn� paczk�. Zaproponowa� algorytm
kt�ry oblicza najmniejsz� mo�liw� do otrzymania pojemno�� wszystkich paczek.

Obs�uga programu:
Program mo�e by� wywo�any w jednym z trzech tryb�w:
- tryb1:
	prog 1 < input > output

	Program pobiera przez standardowe wej�cie dane, a wynik wypisuje na standardowe wyj�cie
	Dane wej�ciowe s� w postaci ci�gu dodatnich liczb. Ilo�� liczb musi by� podzielna przez 3
- tryb2:
	prog 2 n
	
	Program generuje losowe dane o liczbie n, a wynik wypisuje na standardowe wyj�cie
- tryb3:
	prog 3 n k s p

	n - ilo�� danych pocz�tkowych do wygenerowania
	k - krok, co ile zwi�ksza dane
	s - liczba stopni, poziom�w o r�nej ilo�ci danych
	p - ilo�� powt�rze� dla jednego stopnia

W wyniku wywo�ania jednego z dw�ch pierwszych tryb�w wynikiem jest: wynik algorytmu, czas trwania algorytmu
W wyniku wywo�ania trzeciego trybu wynikiem tabela

Rozwi�zania:
1.Rozwi�zanie 1:
- Por�wnujemy wszystkie paczki ze sob�, �eby znale�� wszystkie sytuacje, w kt�rych mo�emy w�o�y� jedn� paczk� do drugiej.
  Ka�da paczka ma wskazania na paczki od niej mniejsze i wi�ksze
- Dokonujemy sortowania topologicznego. Wszystkie paczki wi�ksze znajduj� si� teraz na pocz�tku wektora
- Wywo�ujemy funkcj� rekurencyjn�, kt�ra:
	- Pobiera pierwszy element wektora
	- Przeszukuje wszystkie paczki, kt�re mog� si� do niej zmie�ci� i dla ka�dej z nich ��czy paczki
	- Nowy wektor zmniejszony o 1 wysy�a do funkcji rekurencyjnej
	- Zwraca najmniejsz� zwr�con� warto�ci�
	- W przypadku, gdy nie ma ani jednej mniejszej paczki, to wywo�uje funkcj� rekurencyjn� dla pozosta�ych paczek,
	  a zwr�con� warto�� dodaje do pojemno�ci pierwszego elementu
2.Rozwi�zanie 2:
Rozwi�zanie jest prawie takie samo jak pierwsze. R�nica polega na tym, �e w drugim rozwi�zaniu algorytm usuwa niepotrzebne kraw�dzie, a wi�c
zmniejsza liczbe �cie�ek, kt�rymi nale�y przej��, by znale�� rozwi�zanie. Niepotrzebne kraw�dzie to te, kt�re ��cz� paczki, kt�re mog� mie� mi�dzy
sob� jeszcze co najmniej jedn� paczk�
np.
gdy  a > b > c
to po��czenie mi�dzy a i c jest niepotrzebne

Pliki:
main.cpp - interfejs programu
paczka.h - deklaracja klasy "paczka"
paczka.cpp - definicje metod klasy "paczka"
funkcje.h - deklaracja g��wnej funkcji algorytmu, a tak�e deklaracja funkcji do generowania danych testowych
funkcje.cpp - definicje funkcji z funkcje.h, a tak�e funkcje pomocnicze do tych funkcji