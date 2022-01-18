#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}






















/*
Szeregowanie proces�w w �rodowisku jedno i wieloprocesowym - CO TO ZNACZY WIELOPROCESOWYM ???
i  - numer procesu
ri - czas wykonania
pi - priorytet 0-... 0-najwy�szy priorytet

argv[ {nazwa}{kod_liczbowy_strategi}{liczba_procesor�w}{wielko��_kwantu_czasu_do_wyw�aszczenia}{} ]

Kody poszczeg�lnych strategii:

0 - strategia FCFS (bez wyw�aszczania)
1 - strategia SJF (bez wyw�aszczania)
2 - strategia SRTF (z wyw�aszczaniem)
3 - strategia RR (z wyw�aszczaniem)
4 - szeregowanie priorytetowe z wyw�aszczaniem, zadania o takich samych priorytetach szeregowane algorytmem FCFS
5 - szeregowanie priorytetowe z wyw�aszczaniem, zadania o takich samych priorytetach szeregowane algorytmem SRTF
6 - szeregowanie priorytetowe bez wyw�aszczania, zadania o takich samych priorytetach szeregowane algorytmem FCFS

Strategie wieloprocesorowe - realizowane poprzez obsadzanie kolejnych procesor�w

W przypadku nie rozstrzygni�cia pierwsze�stwa - najpierw najni�szy numer - najni�szy procesor

Dlugie zadania - wykonuj� sie na tym samym procesorze

Przychodz�ce zadania - na koniec kolejki
W przypadku algorytmu RR zadania wyw�aszczane z kolejnych procesor�w (od najni�szego numeru procesora) po zako�czeniu swojego kwantu czasu s� umieszczane w kolejce za nowo przyby�ymi.
Je�li zadanie sko�czy si� przed up�ywem kwantu czasu, to nowe zadanie jest uruchamiane w tym samym momencie, i jego kwant czasu jest liczony od zera, niekoniecznie synchronicznie z kwantami czasu innych zada�.

Program wczytuje dane ze stdin (lub potok ale to raczej nie)

Kolejne wiersze s� postaci:
t i pi ri j pj rj ...
gdzie t oznacza bie��c� chwil� czasu

Przyk�adowo zapis:      [czas]--[numer]--[priorytet]--[czas_wykonania]
0 1 0 8 2 1 5           [0]-{1}{0}{8}-{2}{1}{5}
1                       [1]
2                       [2]
3 3 0 3                 [3]-{3}{0}{3}

// trzeba bedzie zrobic inny program ktory sobie przeczyta ca�y plik
// i przekieruje zawarto�� linijka po linijce
// na stdin programu do szeregowania
// najlepiej jakby wprowadzi� zw�ok� Thread.Sleep(1000) mi�dzy kolejnymi linijkami
// 

Symulacja trwa do momentu wykonania si� wszystkich zada�
Komunikat wy�wietlany na wyj�ciu musi by� postaci:

t p1 p2 .. pM

gdzie t oznacza chwil� czasu, p1 p2 .. pM oznaczaj� numery zada�, kt�re maj� by� wykonywane przez procesory 1..M pomi�dzy chwil� t a t+1. Je�li procesor nie ma przydzielonego zadania jest to oznaczane numerem -1. Przyk�adowy zapis:

10 -1 1 4 3             [10]-{proc1}{-1}-{proc2}{1}-{proc3}{4}-{proc4}{3}

!! Tryb krokowy - TO PӏNIEJ :<

1) przyjmowanie argument�w - na ich podstawie - wybor strategii
np. szeregowanie priorytetowe z wyw�aszczaniem: strategia SRTF - Shortest Remaining Time First

class Procesor{
}
class Proces{
int numer, priorytet, czas_wykonania
}

main:
-- przychodzi ci�g liczb
-- rozdzielenie na procesy - mammy liste proces�w
-- dodanie listy proces�w do g��wnej listy proces�w 
-- posortowanie g��wnej listy proces�w wed�ug :: i to ju� zalo�y od strategii!!! ::                 (priorytet�w potem numer�w - kube�ki + wstawianie?)

procesor:
- je�eli nie wykonuje �adnego procesu
    - pobierz najbardziej priorytetowy proces z listy proces�w 
    - podziel proces na X podproces�w w zale�no�ci od: czas_wykonania / kwant_czasu
    

kwant czasu:
    ?obsad� procesory taskami
    !�ci�gnij pod_proces z listy na procesorze
kwant czasu:
    ?obsad� procesory taskami
    !�ci�gnij pod_proces z listy na procesorze
kwant czasu:
    ?obsad� procesory taskami
    !�ci�gnij pod_proces z listy na procesorze
kwant czasu:
    ?obsad� procesory taskami
    !�ci�gnij pod_proces z listy na procesorze

Strategi Bez Wyw�aszczania:     - lista pod_proces�w zostaje na procesorze
Strategia Z Wyw�aszczaniem:     - po czasie wyw�aszczenia (osobno liczony dla ka�dego procka) policz czas potrzebny(kt�ry zosta�) do wykonania zadania i wrzu� zadanie na koniec listy g��wnej proces�w












*/
