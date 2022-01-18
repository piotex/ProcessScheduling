#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}






















/*
Szeregowanie procesów w œrodowisku jedno i wieloprocesowym - CO TO ZNACZY WIELOPROCESOWYM ???
i  - numer procesu
ri - czas wykonania
pi - priorytet 0-... 0-najwy¿szy priorytet

argv[ {nazwa}{kod_liczbowy_strategi}{liczba_procesorów}{wielkoœæ_kwantu_czasu_do_wyw³aszczenia}{} ]

Kody poszczególnych strategii:

0 - strategia FCFS (bez wyw³aszczania)
1 - strategia SJF (bez wyw³aszczania)
2 - strategia SRTF (z wyw³aszczaniem)
3 - strategia RR (z wyw³aszczaniem)
4 - szeregowanie priorytetowe z wyw³aszczaniem, zadania o takich samych priorytetach szeregowane algorytmem FCFS
5 - szeregowanie priorytetowe z wyw³aszczaniem, zadania o takich samych priorytetach szeregowane algorytmem SRTF
6 - szeregowanie priorytetowe bez wyw³aszczania, zadania o takich samych priorytetach szeregowane algorytmem FCFS

Strategie wieloprocesorowe - realizowane poprzez obsadzanie kolejnych procesorów

W przypadku nie rozstrzygniêcia pierwszeñstwa - najpierw najni¿szy numer - najni¿szy procesor

Dlugie zadania - wykonuj¹ sie na tym samym procesorze

Przychodz¹ce zadania - na koniec kolejki
W przypadku algorytmu RR zadania wyw³aszczane z kolejnych procesorów (od najni¿szego numeru procesora) po zakoñczeniu swojego kwantu czasu s¹ umieszczane w kolejce za nowo przyby³ymi.
Jeœli zadanie skoñczy siê przed up³ywem kwantu czasu, to nowe zadanie jest uruchamiane w tym samym momencie, i jego kwant czasu jest liczony od zera, niekoniecznie synchronicznie z kwantami czasu innych zadañ.

Program wczytuje dane ze stdin (lub potok ale to raczej nie)

Kolejne wiersze s¹ postaci:
t i pi ri j pj rj ...
gdzie t oznacza bie¿¹c¹ chwilê czasu

Przyk³adowo zapis:      [czas]--[numer]--[priorytet]--[czas_wykonania]
0 1 0 8 2 1 5           [0]-{1}{0}{8}-{2}{1}{5}
1                       [1]
2                       [2]
3 3 0 3                 [3]-{3}{0}{3}

// trzeba bedzie zrobic inny program ktory sobie przeczyta ca³y plik
// i przekieruje zawartoœæ linijka po linijce
// na stdin programu do szeregowania
// najlepiej jakby wprowadziæ zw³okê Thread.Sleep(1000) miêdzy kolejnymi linijkami
// 

Symulacja trwa do momentu wykonania siê wszystkich zadañ
Komunikat wyœwietlany na wyjœciu musi byæ postaci:

t p1 p2 .. pM

gdzie t oznacza chwilê czasu, p1 p2 .. pM oznaczaj¹ numery zadañ, które maj¹ byæ wykonywane przez procesory 1..M pomiêdzy chwil¹ t a t+1. Jeœli procesor nie ma przydzielonego zadania jest to oznaczane numerem -1. Przyk³adowy zapis:

10 -1 1 4 3             [10]-{proc1}{-1}-{proc2}{1}-{proc3}{4}-{proc4}{3}

!! Tryb krokowy - TO PÓNIEJ :<

1) przyjmowanie argumentów - na ich podstawie - wybor strategii
np. szeregowanie priorytetowe z wyw³aszczaniem: strategia SRTF - Shortest Remaining Time First

class Procesor{
}
class Proces{
int numer, priorytet, czas_wykonania
}

main:
-- przychodzi ci¹g liczb
-- rozdzielenie na procesy - mammy liste procesów
-- dodanie listy procesów do g³ównej listy procesów 
-- posortowanie g³ównej listy procesów wed³ug :: i to ju¿ zalo¿y od strategii!!! ::                 (priorytetów potem numerów - kube³ki + wstawianie?)

procesor:
- je¿eli nie wykonuje ¿adnego procesu
    - pobierz najbardziej priorytetowy proces z listy procesów 
    - podziel proces na X podprocesów w zale¿noœci od: czas_wykonania / kwant_czasu
    

kwant czasu:
    ?obsadŸ procesory taskami
    !œci¹gnij pod_proces z listy na procesorze
kwant czasu:
    ?obsadŸ procesory taskami
    !œci¹gnij pod_proces z listy na procesorze
kwant czasu:
    ?obsadŸ procesory taskami
    !œci¹gnij pod_proces z listy na procesorze
kwant czasu:
    ?obsadŸ procesory taskami
    !œci¹gnij pod_proces z listy na procesorze

Strategi Bez Wyw³aszczania:     - lista pod_procesów zostaje na procesorze
Strategia Z Wyw³aszczaniem:     - po czasie wyw³aszczenia (osobno liczony dla ka¿dego procka) policz czas potrzebny(który zosta³) do wykonania zadania i wrzuæ zadanie na koniec listy g³ównej procesów












*/
