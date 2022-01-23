#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include "Proces.h"
#include "Processor.h"

using std::vector;
using std::string;
using std::cout;
using std::cin;

bool isExpropriationStrategy(const int& strategyCode) {
    return (strategyCode == 2 || strategyCode == 3 || strategyCode == 4 || strategyCode == 5);
}

void FCFS(vector<Proces>& stackProcess) {
    //[czas] --[numer]-[priorytet]-[czas_wykonania]--[numer]-[priorytet]-[czas_wykonania]
    //0 1 2 3 4 4 4 6 5 4
    if (!stackProcess.empty()) {

    }
}
void SJF(vector<Proces>& stackProcess) {
    //0 1 0 6 4 0 4 6 0 4 7 0 3
    if (!stackProcess.empty()) {
        std::sort(stackProcess.begin(), stackProcess.end(), [](const Proces& lhs, const Proces& rhs) {
            return lhs.RemainingTimeToEndOfProces < rhs.RemainingTimeToEndOfProces;
        });
    }
}
void SRTF(vector<Proces>& stackProcess) {
    //0 1 0 10 2 0 11 3 0 15 4 0 7
    if (!stackProcess.empty()) {
        std::sort(stackProcess.begin(), stackProcess.end(), [](const Proces& lhs, const Proces& rhs) {
            return lhs.RemainingTimeToEndOfProces < rhs.RemainingTimeToEndOfProces;
        });
    }
}



void printProcessVector(vector<Proces>& vec) {
    std::cout << "-----------------\n";
    std::cout << "Stack of Processes: \n";
    for (auto x : vec)
        std::cout << "Idx: " << x.Index << " Prior: " << x.Priority << " RemTime: " << x.RemainingTimeToEndOfProces << "\n";
    std::cout << "-----------------\n";
}
void printProcessorsVector(vector<Processor>& vec) {
    for (auto x : vec)
        std::cout << "Processor: " << x.Index << " Proces: " << x.ActualProces.Index << "    ";
    std::cout << "\n";
}
void setOnEndOfStack(vector<Proces>& vec, const string& in_str) {
    int currentTime = 0;
    int processId = 0;
    int prioryty = 0;
    int remainingTime = 0;

    string tmp = "";
    int counter = 0;

    if (in_str.length() < 7)    //1 3 5 7 - min lenght of data
        return;

    for (int i = 0; i < in_str.length(); i++)
    {
        if (in_str[i] == ' ' || i == in_str.length()) {
            switch (counter)
            {
                case 0:
                    currentTime = std::stoi(tmp);
                    break;
                case 1:
                    processId = std::stoi(tmp);
                    break;
                case 2:
                    prioryty = std::stoi(tmp);
                    break;
                case 3:
                    remainingTime = std::stoi(tmp);
                    counter = 0;
                    vec.push_back(Proces(processId, prioryty, remainingTime));
                    break;
                default:
                    std::cout << "\nError: void setOnEndOfStack(vector<Proces>&, const string&)" << "\n\n";
                    break;
            }
            tmp = "";
            counter++;
        }
        else {
            tmp += in_str[i];
        }
    }
    remainingTime = std::stoi(tmp);
    vec.push_back(Proces(processId, prioryty, remainingTime));
}
void makeSortStrategy(const int& strategyCode, vector<Proces>& stackProcess, vector<Processor>& stackProcesors) {


    switch (strategyCode)
    {
        case 0:
            FCFS(stackProcess);
            break;
        case 1:
            SJF(stackProcess);
            break;
        case 2:
            SRTF(stackProcess);
            break;
        default:
            break;
    }
}
void expropriation(const int& strategyCode, const int& timeToExpropriation,vector<Proces>& stackProcess, vector<Processor>& stackProcesors) {
    if (isExpropriationStrategy(strategyCode))
    {
        for (int i = 0; i < stackProcesors.size(); i++)
        {
            if (stackProcesors[i].RemainingTimeToExpropriation == 0)
            {
                stackProcess.push_back(stackProcesors[i].ActualProces);
                stackProcesors[i].ActualProces = Proces();
                stackProcesors[i].RemainingTimeToExpropriation = timeToExpropriation;
            }
            if (stackProcesors[i].RemainingTimeToExpropriation < 0)
            {
                std::cout << "\n Error:  expropriation()  \n\n\n";
            }
        }
    }
}
void takeOffOnStack(vector<Proces>& stackProcess, vector<Processor>& stackProcesors) {
    for (int i = stackProcesors.size()-1; i >= 0; i--)
    {
        if (stackProcesors[i].ActualProces.Index != -1)                                        //-1  ->  brak procesu
        {
            if (stackProcesors[i].ActualProces.RemainingTimeToEndOfProces > 0)
            {
                stackProcess.insert(stackProcess.begin(), stackProcesors[i].ActualProces);          //dodanie elementu na poczatek
                stackProcesors[i].ActualProces = Proces();
                continue;
            }
            if (stackProcesors[i].ActualProces.RemainingTimeToEndOfProces == 0)
                stackProcesors[i].ActualProces = Proces();
            if (stackProcesors[i].ActualProces.RemainingTimeToEndOfProces < 0)
                std::cout << "\n Error:  takeOffOnStack()  \n\n\n";
        }
    }
}
void setProcessToProcessors(vector<Proces>& stackProcess, vector<Processor>& stackProcesors) {
    for (int i=0; i < stackProcesors.size(); i++)
    {
        if (i <= stackProcess.size() && stackProcess.size() != 0){
            stackProcesors[i].ActualProces = stackProcess[0];
            stackProcess.erase(stackProcess.begin());                                           //zabranie pierwszego elementu ze stosu 
        }
    }
}
void initProcessors(const int& count, const int& remainingTimeToExpropriation, vector<Processor>& stackProcesors) {
    for (int i = 0; i < count; i++)
    {
        stackProcesors.push_back(Processor(i, remainingTimeToExpropriation));
    }
}
void decreaseTime(const int& strategyCode, vector<Processor>& stackProcesors) {
    for (int i = 0; i < stackProcesors.size(); i++) {
        stackProcesors[i].ActualProces.RemainingTimeToEndOfProces--;
        if (isExpropriationStrategy(strategyCode)) {
            stackProcesors[i].RemainingTimeToExpropriation--;
        }
    }
}



//int main(int argc, char** argv)
int main()
{
    //std::vector<std::string> arguments(argv, argv + argc);
    int strategyCode = 2; // std::stoi(argv[1]);
    int procesorsCount = 2; // std::stoi(argv[2]);
    int remainingTimeToExpropriation = 3; // std::stoi(argv[3]);

    

    vector<Proces> stackProcess;
    vector<Processor> stackProcesors;
    initProcessors(procesorsCount, remainingTimeToExpropriation, stackProcesors);

    while (1) 
    {
        string in_str;
        //wczytaj linie - dopisz do stosu
        getline(std::cin, in_str);
        setOnEndOfStack(stackProcess, in_str);
        //wywlasz
        expropriation(strategyCode, remainingTimeToExpropriation, stackProcess, stackProcesors);
        //sortuj
        makeSortStrategy(strategyCode, stackProcess, stackProcesors);
        //sciagnij z procka na stos
        takeOffOnStack(stackProcess, stackProcesors);
        //obsadz

        printProcessVector(stackProcess);                                           //print

        setProcessToProcessors(stackProcess, stackProcesors);
        //zmniejsz czas procesow i czas do wywlaszczenia


        printProcessorsVector(stackProcesors);                                      //print

        decreaseTime(strategyCode, stackProcesors);

        //printProcessVector(vec);
    }

    std::cout << "---------- Main End ----------\n";
}

/*

//          0 1 2 3 4 4 4 6 5 4
        printProcessVector(stackProcess);
        stackProcesors[0].ActualProces = Proces(9, 9, 9);
        takeOffOnStack(stackProcess, stackProcesors);
        std::cout << "--------------------\n";
        printProcessVector(stackProcess);
        return 0;













*/




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
