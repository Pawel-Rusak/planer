#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <utility>
#include <string>

#include "wyklady.h"
#include "struktury.h"


#define ndl "\n"
#define st first
#define nd second
#define ll long long
#define pb push_back
#define pob pop_back
#define all(x) (x).begin(), (x).end()

using namespace std;

void stworz_wyklady(vector<zajecia> &wyklady){
    wyklady[0].liczba_godzin = 4;
    wyklady[0].terminy.resize(4);
    wyklady[0].terminy[0] = {1, 2};
    wyklady[0].terminy[1] = {1, 3};
    wyklady[0].terminy[2] = {4, 4};
    wyklady[0].terminy[3] = {4, 5};
    wyklady[0].nazwa = "Analiza wyklad";
    wyklady[0].nr_grupy = 1;
    wyklady[0].prowadzacy = "Adam Latosinki";

    wyklady[1].liczba_godzin = 2;
    wyklady[1].terminy.resize(2);
    wyklady[1].terminy[0] = {4, 6};
    wyklady[1].terminy[1] = {4, 7};
    wyklady[1].nazwa = "Algebra wyklad";
    wyklady[1].nr_grupy = 2;
    wyklady[1].prowadzacy = "Szymon Charzynski";

    wyklady[2].liczba_godzin = 3;
    wyklady[2].terminy.resize(3);
    wyklady[2].terminy[0] = {2, 1};
    wyklady[2].terminy[1] = {2, 2};
    wyklady[2].terminy[2] = {2, 3};
    wyklady[2].nazwa = "Fizyka wyklad";
    wyklady[2].nr_grupy = 3;
    wyklady[2].prowadzacy = "Aneta Drabinska";

    wyklady[3].liczba_godzin = 1;
    wyklady[3].terminy.resize(1);
    wyklady[3].terminy[0] = {0, 7};
    wyklady[3].nazwa = "Programowanie wyklad";
    wyklady[3].nr_grupy = 4;
    wyklady[3].prowadzacy = "Katarzyna Grzelak";

    wyklady[4].liczba_godzin = 2;
    wyklady[4].terminy.resize(2);
    wyklady[4].terminy[0] = {1, 7};
    wyklady[4].terminy[1] = {1, 8};
    wyklady[4].nazwa = "ANP wyklad";
    wyklady[4].nr_grupy = 5;
    wyklady[4].prowadzacy = "Andrzej Majhofer";

    wyklady[5].liczba_godzin = 1;
    wyklady[5].terminy.resize(1);
    wyklady[5].terminy[0] = {2, 4};
    wyklady[5].nazwa = "Fizyka cwiczenia wykladowe";
    wyklady[5].nr_grupy = 6;
    wyklady[5].prowadzacy = "Krzysztof Turzynski";

}

