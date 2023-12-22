#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <utility>
#include <string>

#include "cwiczenia.h"
#include "struktury.h"


#define ndl "\n"
#define st first
#define nd second
#define ll long long
#define pb push_back
#define pob pop_back
#define all(x) (x).begin(), (x).end()

using namespace std;

void stworz_cwiczenia_analiza(vector<zajecia> &analiza_cwiczenia){

    analiza_cwiczenia[0].liczba_godzin = 4;
    analiza_cwiczenia[0].terminy.resize(4);
    analiza_cwiczenia[0].terminy[0] = {1, 4};
    analiza_cwiczenia[0].terminy[1] = {1, 5};
    analiza_cwiczenia[0].terminy[2] = {4, 2};
    analiza_cwiczenia[0].terminy[3] = {4, 3};
    analiza_cwiczenia[0].nazwa = "Analiza cwiczenia";
    analiza_cwiczenia[0].nr_grupy = 1;
    analiza_cwiczenia[0].prowadzacy = "Katarzyna Grabowska";

    analiza_cwiczenia[1].liczba_godzin = 4;
    analiza_cwiczenia[1].terminy.resize(4);
    analiza_cwiczenia[1].terminy[0] = {3, 6};
    analiza_cwiczenia[1].terminy[1] = {3, 7};
    analiza_cwiczenia[1].terminy[2] = {4, 0};
    analiza_cwiczenia[1].terminy[3] = {4, 1};
    analiza_cwiczenia[1].nazwa = "Analiza cwiczenia";
    analiza_cwiczenia[1].nr_grupy = 2;
    analiza_cwiczenia[1].prowadzacy = "Tomasz Smolka";

    analiza_cwiczenia[2].liczba_godzin = 4;
    analiza_cwiczenia[2].terminy.resize(4);
    analiza_cwiczenia[2].terminy[0] = {0, 5};
    analiza_cwiczenia[2].terminy[1] = {0, 6};
    analiza_cwiczenia[2].terminy[2] = {4, 0};
    analiza_cwiczenia[2].terminy[3] = {4, 1};
    analiza_cwiczenia[2].nazwa = "Analiza cwiczenia";
    analiza_cwiczenia[2].nr_grupy = 3;
    analiza_cwiczenia[2].prowadzacy = "Julia Lange";

    analiza_cwiczenia[3].liczba_godzin = 4;
    analiza_cwiczenia[3].terminy.resize(4);
    analiza_cwiczenia[3].terminy[0] = {2, 5};
    analiza_cwiczenia[3].terminy[1] = {2, 6};
    analiza_cwiczenia[3].terminy[2] = {4, 2};
    analiza_cwiczenia[3].terminy[3] = {4, 3};
    analiza_cwiczenia[3].nazwa = "Analiza cwiczenia";
    analiza_cwiczenia[3].nr_grupy = 4;
    analiza_cwiczenia[3].prowadzacy = "Adam Latosinski";


}

void stworz_cwiczenia_algebra(vector<zajecia> &algebra_cwiczenia){

    algebra_cwiczenia[0].liczba_godzin = 2;
    algebra_cwiczenia[0].terminy.resize(2);
    algebra_cwiczenia[0].terminy[0] = {3, 5};
    algebra_cwiczenia[0].terminy[1] = {3, 6};
    algebra_cwiczenia[0].nazwa = "Algebra cwiczenia";
    algebra_cwiczenia[0].nr_grupy = 1;
    algebra_cwiczenia[0].prowadzacy = "Maciej Nieszporski";

    algebra_cwiczenia[1].liczba_godzin = 2;
    algebra_cwiczenia[1].terminy.resize(2);
    algebra_cwiczenia[1].terminy[0] = {0, 5};
    algebra_cwiczenia[1].terminy[1] = {0, 6};
    algebra_cwiczenia[1].nazwa = "Algebra cwiczenia";
    algebra_cwiczenia[1].nr_grupy = 2;
    algebra_cwiczenia[1].prowadzacy = "Igor Chelstwoski";

    algebra_cwiczenia[2].liczba_godzin = 2;
    algebra_cwiczenia[2].terminy.resize(2);
    algebra_cwiczenia[2].terminy[0] = {2, 5};
    algebra_cwiczenia[2].terminy[1] = {2, 6};
    algebra_cwiczenia[2].nazwa = "Algebra cwiczenia";
    algebra_cwiczenia[2].nr_grupy = 3;
    algebra_cwiczenia[2].prowadzacy = "Bartosz Zawora";

    algebra_cwiczenia[3].liczba_godzin = 2;
    algebra_cwiczenia[3].terminy.resize(2);
    algebra_cwiczenia[3].terminy[0] = {0, 5};
    algebra_cwiczenia[3].terminy[1] = {0, 6};
    algebra_cwiczenia[3].nazwa = "Algebra cwiczenia";
    algebra_cwiczenia[3].nr_grupy = 4;
    algebra_cwiczenia[3].prowadzacy = "Adam Szereszewski";

    algebra_cwiczenia[4].liczba_godzin = 2;
    algebra_cwiczenia[4].terminy.resize(2);
    algebra_cwiczenia[4].terminy[0] = {1, 4};
    algebra_cwiczenia[4].terminy[1] = {1, 5};
    algebra_cwiczenia[4].nazwa = "Algebra cwiczenia";
    algebra_cwiczenia[4].nr_grupy = 5;
    algebra_cwiczenia[4].prowadzacy = "Rafal Blaszkiewicz";

}

void stworz_cwiczenia_fizyka(vector<zajecia> &fizyka_cwiczenia) {

    fizyka_cwiczenia[0].liczba_godzin = 4;
    fizyka_cwiczenia[0].terminy.resize(4);
    fizyka_cwiczenia[0].terminy[0] = {2, 5};
    fizyka_cwiczenia[0].terminy[1] = {2, 6};
    fizyka_cwiczenia[0].terminy[2] = {3, 3};
    fizyka_cwiczenia[0].terminy[3] = {3, 4};
    fizyka_cwiczenia[0].nazwa = "Fizyka cwiczenia";
    fizyka_cwiczenia[0].nr_grupy = 1;
    fizyka_cwiczenia[0].prowadzacy = "Jan Suffczysnki";

    fizyka_cwiczenia[1].liczba_godzin = 4;
    fizyka_cwiczenia[1].terminy.resize(4);
    fizyka_cwiczenia[1].terminy[0] = {3, 4};
    fizyka_cwiczenia[1].terminy[1] = {3, 5};
    fizyka_cwiczenia[1].terminy[2] = {4, 2};
    fizyka_cwiczenia[1].terminy[3] = {4, 3};
    fizyka_cwiczenia[1].nazwa = "Fizyka cwiczenia";
    fizyka_cwiczenia[1].nr_grupy = 2;
    fizyka_cwiczenia[1].prowadzacy = "Waldemar Urban";

    fizyka_cwiczenia[2].liczba_godzin = 4;
    fizyka_cwiczenia[2].terminy.resize(4);
    fizyka_cwiczenia[2].terminy[0] = {0, 8};
    fizyka_cwiczenia[2].terminy[1] = {0, 9};
    fizyka_cwiczenia[2].terminy[2] = {1, 4};
    fizyka_cwiczenia[2].terminy[3] = {1, 5};
    fizyka_cwiczenia[2].nazwa = "Fizyka cwiczenia";
    fizyka_cwiczenia[2].nr_grupy = 3;
    fizyka_cwiczenia[2].prowadzacy = "Ignacy Nalecz";

    fizyka_cwiczenia[3].liczba_godzin = 4;
    fizyka_cwiczenia[3].terminy.resize(4);
    fizyka_cwiczenia[3].terminy[0] = {0, 5};
    fizyka_cwiczenia[3].terminy[1] = {0, 6};
    fizyka_cwiczenia[3].terminy[2] = {4, 0};
    fizyka_cwiczenia[3].terminy[3] = {4, 1};
    fizyka_cwiczenia[3].nazwa = "Fizyka cwiczenia";
    fizyka_cwiczenia[3].nr_grupy = 4;
    fizyka_cwiczenia[3].prowadzacy = "Krzysztof Turzynski";

    fizyka_cwiczenia[4].liczba_godzin = 4;
    fizyka_cwiczenia[4].terminy.resize(4);
    fizyka_cwiczenia[4].terminy[0] = {0, 5};
    fizyka_cwiczenia[4].terminy[1] = {0, 6};
    fizyka_cwiczenia[4].terminy[2] = {3, 4};
    fizyka_cwiczenia[4].terminy[3] = {3, 5};
    fizyka_cwiczenia[4].nazwa = "Fizyka cwiczenia";
    fizyka_cwiczenia[4].nr_grupy = 5;
    fizyka_cwiczenia[4].prowadzacy = "Witold Bardyszewski";

    fizyka_cwiczenia[5].liczba_godzin = 4;
    fizyka_cwiczenia[5].terminy.resize(4);
    fizyka_cwiczenia[5].terminy[0] = {0, 5};
    fizyka_cwiczenia[5].terminy[1] = {0, 6};
    fizyka_cwiczenia[5].terminy[2] = {3, 7};
    fizyka_cwiczenia[5].terminy[3] = {3, 8};
    fizyka_cwiczenia[5].nazwa = "Fizyka cwiczenia";
    fizyka_cwiczenia[5].nr_grupy = 6;
    fizyka_cwiczenia[5].prowadzacy = "Teresa Rzaca-Urban";

    fizyka_cwiczenia[6].liczba_godzin = 4;
    fizyka_cwiczenia[6].terminy.resize(4);
    fizyka_cwiczenia[6].terminy[0] = {3, 2};
    fizyka_cwiczenia[6].terminy[1] = {3, 3};
    fizyka_cwiczenia[6].terminy[2] = {4, 0};
    fizyka_cwiczenia[6].terminy[3] = {4, 1};
    fizyka_cwiczenia[6].nazwa = "Fizyka cwiczenia";
    fizyka_cwiczenia[6].nr_grupy = 7;
    fizyka_cwiczenia[6].prowadzacy = "Maciej Dlugosz";

    fizyka_cwiczenia[7].liczba_godzin = 4;
    fizyka_cwiczenia[7].terminy.resize(4);
    fizyka_cwiczenia[7].terminy[0] = {3, 2};
    fizyka_cwiczenia[7].terminy[1] = {3, 3};
    fizyka_cwiczenia[7].terminy[2] = {4, 0};
    fizyka_cwiczenia[7].terminy[3] = {4, 1};
    fizyka_cwiczenia[7].nazwa = "Fizyka cwiczenia";
    fizyka_cwiczenia[7].nr_grupy = 8;
    fizyka_cwiczenia[7].prowadzacy = "Magdalena Posiadala-Zezula";

    fizyka_cwiczenia[8].liczba_godzin = 4;
    fizyka_cwiczenia[8].terminy.resize(4);
    fizyka_cwiczenia[8].terminy[0] = {3, 4};
    fizyka_cwiczenia[8].terminy[1] = {3, 5};
    fizyka_cwiczenia[8].terminy[2] = {4, 0};
    fizyka_cwiczenia[8].terminy[3] = {4, 1};
    fizyka_cwiczenia[8].nazwa = "Fizyka cwiczenia";
    fizyka_cwiczenia[8].nr_grupy = 9;
    fizyka_cwiczenia[8].prowadzacy = "Jerzy Kaminski";

}

void stworz_cwiczenia_programowanie(vector<zajecia>& programowanie_cwiczenia) {
    programowanie_cwiczenia[0].liczba_godzin = 2;
    programowanie_cwiczenia[0].terminy.resize(2);
    programowanie_cwiczenia[0].terminy[0] = {1, 0};
    programowanie_cwiczenia[0].terminy[1] = {1, 1};
    programowanie_cwiczenia[0].nazwa = "Programowanie cwiczenia";
    programowanie_cwiczenia[0].nr_grupy = 1;
    programowanie_cwiczenia[0].prowadzacy = "Julia Derlikiewicz";

    programowanie_cwiczenia[1].liczba_godzin = 2;
    programowanie_cwiczenia[1].terminy.resize(2);
    programowanie_cwiczenia[1].terminy[0] = {0, 8};
    programowanie_cwiczenia[1].terminy[1] = {0, 9};
    programowanie_cwiczenia[1].nazwa = "Programowanie cwiczenia";
    programowanie_cwiczenia[1].nr_grupy = 2;
    programowanie_cwiczenia[1].prowadzacy = "brak prowadzacego";

    programowanie_cwiczenia[2].liczba_godzin = 2;
    programowanie_cwiczenia[2].terminy.resize(2);
    programowanie_cwiczenia[2].terminy[0] = {0, 9};
    programowanie_cwiczenia[2].terminy[1] = {0, 10};
    programowanie_cwiczenia[2].nazwa = "Programowanie cwiczenia";
    programowanie_cwiczenia[2].nr_grupy = 3;
    programowanie_cwiczenia[2].prowadzacy = "brak prowadzacego";

    programowanie_cwiczenia[3].liczba_godzin = 2;
    programowanie_cwiczenia[3].terminy.resize(2);
    programowanie_cwiczenia[3].terminy[0] = {2, 5};
    programowanie_cwiczenia[3].terminy[1] = {2, 6};
    programowanie_cwiczenia[3].nazwa = "Programowanie cwiczenia";
    programowanie_cwiczenia[3].nr_grupy = 4;
    programowanie_cwiczenia[3].prowadzacy = "brak prowadzacego";

    programowanie_cwiczenia[4].liczba_godzin = 2;
    programowanie_cwiczenia[4].terminy.resize(2);
    programowanie_cwiczenia[4].terminy[0] = {1, 4};
    programowanie_cwiczenia[4].terminy[1] = {1, 5};
    programowanie_cwiczenia[4].nazwa = "Programowanie cwiczenia";
    programowanie_cwiczenia[4].nr_grupy = 5;
    programowanie_cwiczenia[4].prowadzacy = "Katarzyna Grzelak";

    programowanie_cwiczenia[5].liczba_godzin = 2;
    programowanie_cwiczenia[5].terminy.resize(2);
    programowanie_cwiczenia[5].terminy[0] = {3, 5};
    programowanie_cwiczenia[5].terminy[1] = {3, 6};
    programowanie_cwiczenia[5].nazwa = "Programowanie cwiczenia";
    programowanie_cwiczenia[5].nr_grupy = 6;
    programowanie_cwiczenia[5].prowadzacy = "bra prowadzacego";

    programowanie_cwiczenia[6].liczba_godzin = 2;
    programowanie_cwiczenia[6].terminy.resize(2);
    programowanie_cwiczenia[6].terminy[0] = {3, 6};
    programowanie_cwiczenia[6].terminy[1] = {3, 7};
    programowanie_cwiczenia[6].nazwa = "Programowanie cwiczenia";
    programowanie_cwiczenia[6].nr_grupy = 7;
    programowanie_cwiczenia[6].prowadzacy = "brak prowadzacego";

    programowanie_cwiczenia[7].liczba_godzin = 2;
    programowanie_cwiczenia[7].terminy.resize(2);
    programowanie_cwiczenia[7].terminy[0] = {0, 8};
    programowanie_cwiczenia[7].terminy[1] = {0, 9};
    programowanie_cwiczenia[7].nazwa = "Programowanie cwiczenia";
    programowanie_cwiczenia[7].nr_grupy = 8;
    programowanie_cwiczenia[7].prowadzacy = "brak prowadzacego";

    programowanie_cwiczenia[8].liczba_godzin = 2;
    programowanie_cwiczenia[8].terminy.resize(2);
    programowanie_cwiczenia[8].terminy[0] = {3, 6};
    programowanie_cwiczenia[8].terminy[1] = {3, 7};
    programowanie_cwiczenia[8].nazwa = "Programowanie cwiczenia";
    programowanie_cwiczenia[8].nr_grupy = 9;
    programowanie_cwiczenia[8].prowadzacy = "brak prowadzacego";

    programowanie_cwiczenia[9].liczba_godzin = 2;
    programowanie_cwiczenia[9].terminy.resize(2);
    programowanie_cwiczenia[9].terminy[0] = {2, 8};
    programowanie_cwiczenia[9].terminy[1] = {2, 9};
    programowanie_cwiczenia[9].nazwa = "Programowanie cwiczenia";
    programowanie_cwiczenia[9].nr_grupy = 10;
    programowanie_cwiczenia[9].prowadzacy = "brak prowadzacego";

}

void stworz_laboratorium(vector<zajecia>& laboratorium) {
    laboratorium[0].liczba_godzin = 3;
    laboratorium[0].terminy.resize(3);
    laboratorium[0].terminy[0] = {0, 5};
    laboratorium[0].terminy[1] = {0, 6};
    laboratorium[0].terminy[2] = {0, 7};
    laboratorium[0].nazwa = "Pracownia wstepna";
    laboratorium[0].nr_grupy = 1;
    laboratorium[0].prowadzacy = "brak prowadzacego";

    laboratorium[1].liczba_godzin = 3;
    laboratorium[1].terminy.resize(3);
    laboratorium[1].terminy[0] = {1, 4};
    laboratorium[1].terminy[1] = {1, 5};
    laboratorium[1].terminy[2] = {1, 6};
    laboratorium[1].nazwa = "Pracownia wstepna";
    laboratorium[1].nr_grupy = 2;
    laboratorium[1].prowadzacy = "brak prowadzacego";

    laboratorium[2].liczba_godzin = 3;
    laboratorium[2].terminy.resize(3);
    laboratorium[2].terminy[0] = {3, 4};
    laboratorium[2].terminy[1] = {3, 5};
    laboratorium[2].terminy[2] = {3, 6};
    laboratorium[2].nazwa = "Pracownia wstepna";
    laboratorium[2].nr_grupy = 3;
    laboratorium[2].prowadzacy = "brak prowadzacego";

    laboratorium[3].liczba_godzin = 3;
    laboratorium[3].terminy.resize(3);
    laboratorium[3].terminy[0] = {3, 1};
    laboratorium[3].terminy[1] = {3, 2};
    laboratorium[3].terminy[2] = {3, 3};
    laboratorium[3].nazwa = "Pracownia wstepna";
    laboratorium[3].nr_grupy = 4;
    laboratorium[3].prowadzacy = "brak prowadzacego";

    laboratorium[4].liczba_godzin = 3;
    laboratorium[4].terminy.resize(3);
    laboratorium[4].terminy[0] = {2, 5};
    laboratorium[4].terminy[1] = {2, 6};
    laboratorium[4].terminy[2] = {2, 7};
    laboratorium[4].nazwa = "Pracownia wstepna";
    laboratorium[4].nr_grupy = 5;
    laboratorium[4].prowadzacy = "brak prowadzacego";

    laboratorium[5].liczba_godzin = 3;
    laboratorium[5].terminy.resize(3);
    laboratorium[5].terminy[0] = {4, 1};
    laboratorium[5].terminy[1] = {4, 2};
    laboratorium[5].terminy[2] = {4, 3};
    laboratorium[5].nazwa = "Pracownia wstepna";
    laboratorium[5].nr_grupy = 6;
    laboratorium[5].prowadzacy = "brak prowadzacego";



}