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
