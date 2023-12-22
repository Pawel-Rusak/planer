#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <utility>
#include <string>
#include <iomanip>
#include <set>
#include <sstream>


#include "wyklady.h"
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

void printSchedule(const vector<vector<bool>>& plan) {
    const int liczbaDni = 5;
    const int liczbaGodzin = 10;
    const string dniTygodnia[liczbaDni] = {"Pon", "Wt ", "Sr ", "Czw", "Pt "};

    cout << "  Godzina   | ";
    for (const auto& dzien : dniTygodnia) {
        cout << dzien << " | ";
    }
    cout << ndl;

    cout << "------------|-----|-----|-----|-----|-----" << ndl;

    for (int i = 0; i < liczbaGodzin; ++i) {
        cout << setw(6) << i + 1 << " blok | "; // Ustawienie szerokości pola na 6

        for (int j = 0; j < liczbaDni; ++j) {
            cout << (plan[j][i] ? " X " : " - ") << " | ";
        }
        cout << ndl;
    }
}

void print_wybrane_wyklady(const vector<zajecia>& wybrane_zajecia, bool all_wyklady, bool none_wyklady) {
    if(all_wyklady == true)
        cout << "Jestes zapisany na wszystkie wyklady" << ndl;
    else if(none_wyklady == true)
        cout << "Nie jestes zapisany na zadne wyklady" << ndl;
    else {
        cout << "Wybrane wyklady:" << ndl;
        for (const auto& zajecie : wybrane_zajecia) {
            cout << zajecie.nazwa << ", prowadzacy: " << zajecie.prowadzacy << ndl;
        }
    }
}

void print_wybrane_cwiczenia(const vector<zajecia>& przydzielone_cwiczenia, int &liczba_wygenerowanych_planow, vector<vector<bool>>& plan) {
    cout << "Plan nuner " << ++liczba_wygenerowanych_planow << ":" << ndl;
    for(int i = 0; i < przydzielone_cwiczenia.size(); i++) {
        cout << przydzielone_cwiczenia[i].nazwa << " grupa: " << przydzielone_cwiczenia[i].nr_grupy << ", prowadzacy: " << przydzielone_cwiczenia[i].prowadzacy << ndl;
    }
    printSchedule(plan);
    cout << ndl;
}

bool can_add(vector<vector<bool>> plan, zajecia this_zajecia) {
    bool can_add = true;
    for (int i = 0; i < this_zajecia.liczba_godzin; i++) {
        if (plan[this_zajecia.terminy[i].st][this_zajecia.terminy[i].nd] == true) {
            can_add = false;
            break;
        }
    }
    return can_add;
}

void add_to_plan(vector<vector<bool>>& plan, zajecia this_zajecia) {
    for (int i = 0; i < this_zajecia.liczba_godzin; i++) {
        plan[this_zajecia.terminy[i].st][this_zajecia.terminy[i].nd] = true;
    }
}


int main(){
    int liczba_wygenerowanych_planow = 0;
    bool all_wyklady = false, none_wyklady = false;

    vector<vector<bool>> plan(5, vector<bool>(10, false));

    string zadeklarowane_wyklady;
    vector<zajecia> wybrane_wyklady;

    vector<zajecia> wyklady (6);
    stworz_wyklady(wyklady);

    vector<zajecia> analiza_cwiczenia(4);
    stworz_cwiczenia_analiza(analiza_cwiczenia);

    vector<zajecia> algebra_cwiczenia(5);
    stworz_cwiczenia_algebra(algebra_cwiczenia);

    vector<zajecia> fizyka_cwiczenia(9);
    stworz_cwiczenia_fizyka(fizyka_cwiczenia);

    vector<zajecia> programowanie_cwiczenia(10);
    stworz_cwiczenia_programowanie(programowanie_cwiczenia);

    vector<zajecia> labolatorium(10);
    stworz_laboratorium(labolatorium);

    //start

    //wyklady

    cout << "Witaj w generatorze planu zajec!" << ndl;
    cout << "Na jakie wyklady chcesz sie zapisac?" << ndl;
    cout << "Dostepne wyklady:" << ndl;
    for (int i = 0; i < 6; i++) {
        cout << i + 1 << ". " << wyklady[i].nazwa << ", prowadzacy: " << wyklady[i].prowadzacy << ndl;
    }
    cout << "Wybierz wyklady wpisujac ich numery oddzielone spacja (np. \"1 2 4 6\")" << ndl;
    cout << "Wpisz \"a\", aby zapisac sie na wszystkie wyklady." << ndl;
    cout << "Jezeli nie chcesz sie zapisywac na zadne wyklady, wpisz \"0\"" << ndl;

    string line;
    getline(cin, line);

    if (line == "a") {
        all_wyklady = true;
        for (int i = 0; i < 6; i++) {
            wybrane_wyklady.pb(wyklady[i]);
            for (int j = 0; j < wyklady[i].liczba_godzin; j++) {
                plan[wyklady[i].terminy[j].st][wyklady[i].terminy[j].nd] = true;
            }
        }
    } else if (line == "0") {
        none_wyklady = true;
    } else {
        stringstream ss(line);
        int numer;
        set<int> wybraneNumery;

        while (ss >> numer) {
            if (numer < 1 || numer > 6) {
                cout << "Nieprawidlowy numer wykladu: " << numer << ". Prosze wprowadzić numery od 1 do 6." << ndl;
                return 1;
            }
            wybraneNumery.insert(numer);
        }

        for (int numer : wybraneNumery) {
            int indeksWykladu = numer - 1; // Odejmowanie 1 dla prawidłowego mapowania
            wybrane_wyklady.pb(wyklady[indeksWykladu]);
            for (int j = 0; j < wyklady[indeksWykladu].liczba_godzin; j++) {
                plan[wyklady[indeksWykladu].terminy[j].st][wyklady[indeksWykladu].terminy[j].nd] = true;
            }
        }
    }

    //analiza cwiczenia

    cout << "Do jakich grup cwiczeniowych z analizy chcesz sie zapisac?" << ndl;
    cout << "Dostepne grupy:" << ndl;
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". " << analiza_cwiczenia[i].nazwa << ", prowadzacy: " << analiza_cwiczenia[i].prowadzacy << ndl;
    }
    cout << "Wybierz grupy wpisujac ich numery oddzielone spacja (np. \"1 2 4\")" << ndl;
    cout << "Wpisz \"a\", aby zapisac sie na wszystkie grupy." << ndl;
    string line2;
    getline(cin, line2);
    vector<zajecia> wybrane_analiza_cwiczenia;
    if (line2 == "a") {
        for (int i = 0; i < 4; i++) {
            wybrane_analiza_cwiczenia.pb(analiza_cwiczenia[i]);
        }
    } else {
        stringstream ss(line2);
        int numer;
        set<int> wybraneNumery;

        while (ss >> numer) {
            if (numer < 1 || numer > 4) {
                cout << "Nieprawidlowy numer grupy: " << numer << ". Prosze wprowadzić numery od 1 do 4." << ndl;
                return 1;
            }
            wybraneNumery.insert(numer);
        }

        for (int numer : wybraneNumery) {
            int indeksGrupy = numer - 1; // Odejmowanie 1 dla prawidłowego mapowania
            wybrane_analiza_cwiczenia.pb(analiza_cwiczenia[indeksGrupy]);
        }
    }

    //algebra cwiczenia
    cout << "Do jakich grup cwiczeniowych z algebry chcesz sie zapisac?" << ndl;
    cout << "Dostepne grupy:" << ndl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << algebra_cwiczenia[i].nazwa << ", prowadzacy: " << algebra_cwiczenia[i].prowadzacy << ndl;
    }
    cout << "Wybierz grupy wpisujac ich numery oddzielone spacja (np. \"1 2 4\")" << ndl;
    cout << "Wpisz \"a\", aby zapisac sie na wszystkie grupy." << ndl;
    string line3;
    getline(cin, line3);
    vector<zajecia> wybrane_algebra_cwiczenia;
    if (line3 == "a") {
        for (int i = 0; i < 5; i++) {
            wybrane_algebra_cwiczenia.pb(algebra_cwiczenia[i]);
        }
    } else {
        stringstream ss(line3);
        int numer;
        set<int> wybraneNumery;

        while (ss >> numer) {
            if (numer < 1 || numer > 5) {
                cout << "Nieprawidlowy numer grupy: " << numer << ". Prosze wprowadzić numery od 1 do 5." << ndl;
                return 1;
            }
            wybraneNumery.insert(numer);
        }

        for (int numer : wybraneNumery) {
            int indeksGrupy = numer - 1; // Odejmowanie 1 dla prawidłowego mapowania
            wybrane_algebra_cwiczenia.pb(algebra_cwiczenia[indeksGrupy]);
        }
    }

    //fizyka cwiczenia

    cout << "Do jakich grup cwiczeniowych z fizyki chcesz sie zapisac?" << ndl;
    cout << "Dostepne grupy:" << ndl;
    for (int i = 0; i < 9; i++) {
        cout << i + 1 << ". " << fizyka_cwiczenia[i].nazwa << ", prowadzacy: " << fizyka_cwiczenia[i].prowadzacy << ndl;
    }
    cout << "Wybierz grupy wpisujac ich numery oddzielone spacja (np. \"1 2 4\")" << ndl;
    cout << "Wpisz \"a\", aby zapisac sie na wszystkie grupy." << ndl;
    string line4;
    getline(cin, line4);
    vector<zajecia> wybrane_fizyka_cwiczenia;
    if (line4 == "a") {
        for (int i = 0; i < 9; i++) {
            wybrane_fizyka_cwiczenia.pb(fizyka_cwiczenia[i]);
        }
    } else {
        stringstream ss(line4);
        int numer;
        set<int> wybraneNumery;

        while (ss >> numer) {
            if (numer < 1 || numer > 9) {
                cout << "Nieprawidlowy numer grupy: " << numer << ". Prosze wprowadzić numery od 1 do 9." << ndl;
                return 1;
            }
            wybraneNumery.insert(numer);
        }

        for (int numer : wybraneNumery) {
            int indeksGrupy = numer - 1; // Odejmowanie 1 dla prawidłowego mapowania
            wybrane_fizyka_cwiczenia.pb(fizyka_cwiczenia[indeksGrupy]);
        }
    }

    //programowanie cwiczenia

    cout << "Do jakich grup cwiczeniowych z programowania chcesz sie zapisac?" << ndl;
    cout << "Dostepne grupy:" << ndl;
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << ". " << programowanie_cwiczenia[i].nazwa << ", prowadzacy: " << programowanie_cwiczenia[i].prowadzacy << ndl;
    }
    cout << "Wybierz grupy wpisujac ich numery oddzielone spacja (np. \"1 2 4\")" << ndl;
    cout << "Wpisz \"a\", aby zapisac sie na wszystkie grupy." << ndl;
    string line5;
    getline(cin, line5);
    vector<zajecia> wybrane_programowanie_cwiczenia;
    if (line5 == "a") {
        for (int i = 0; i < 10; i++) {
            wybrane_programowanie_cwiczenia.pb(programowanie_cwiczenia[i]);
        }
    } else {
        stringstream ss(line5);
        int numer;
        set<int> wybraneNumery;

        while (ss >> numer) {
            if (numer < 1 || numer > 10) {
                cout << "Nieprawidlowy numer grupy: " << numer << ". Prosze wprowadzić numery od 1 do 10." << ndl;
                return 1;
            }
            wybraneNumery.insert(numer);
        }

        for (int numer : wybraneNumery) {
            int indeksGrupy = numer - 1; // Odejmowanie 1 dla prawidłowego mapowania
            wybrane_programowanie_cwiczenia.pb(programowanie_cwiczenia[indeksGrupy]);
        }
    }

    //laborki

    cout << "Do jakich grup pracowni wstepnej chcesz sie zapisac?" << ndl;
    cout << "Dostepne grupy:" << ndl;
    for (int i = 0; i < 6; i++) {
        cout << i + 1 << ". " << labolatorium[i].nazwa << ", prowadzacy: " << labolatorium[i].prowadzacy << ndl;
    }
    cout << "Wybierz grupy wpisujac ich numery oddzielone spacja (np. \"1 2 4\")" << ndl;
    cout << "Wpisz \"a\", aby zapisac sie na wszystkie grupy." << ndl;
    string line6;
    getline(cin, line6);
    vector<zajecia> wybrane_labolatorium;
    if (line6 == "a") {
        for (int i = 0; i < 6; i++) {
            wybrane_labolatorium.pb(labolatorium[i]);
        }
    } else {
        stringstream ss(line6);
        int numer;
        set<int> wybraneNumery;

        while (ss >> numer) {
            if (numer < 1 || numer > 6) {
                cout << "Nieprawidlowy numer grupy: " << numer << ". Prosze wprowadzić numery od 1 do 6." << ndl;
                return 1;
            }
            wybraneNumery.insert(numer);
        }

        for (int numer : wybraneNumery) {
            int indeksGrupy = numer - 1; // Odejmowanie 1 dla prawidłowego mapowania
            wybrane_labolatorium.pb(labolatorium[indeksGrupy]);
        }
    }


    print_wybrane_wyklady(wybrane_wyklady, all_wyklady, none_wyklady);
    cout << ndl;

    vector <zajecia> zajecia_przydzielone;

    //backtracking


    for(int a = 0; a < wybrane_analiza_cwiczenia.size(); a++){
        if(can_add(plan, wybrane_analiza_cwiczenia[a])){
            vector<vector<bool>> plan_copy1 = plan;
            add_to_plan(plan, wybrane_analiza_cwiczenia[a]);
            zajecia_przydzielone.pb(wybrane_analiza_cwiczenia[a]);

            for(int b = 0; b < wybrane_algebra_cwiczenia.size(); b++) {
                if (can_add(plan, wybrane_algebra_cwiczenia[b])) {
                    vector<vector<bool>> plan_copy2 = plan;
                    zajecia_przydzielone.pb(wybrane_algebra_cwiczenia[b]);
                    add_to_plan(plan, wybrane_algebra_cwiczenia[b]);

                    for(int c = 0; c < wybrane_fizyka_cwiczenia.size(); c++) {
                        if (can_add(plan, wybrane_fizyka_cwiczenia[c])) {
                            vector<vector<bool>> plan_copy3 = plan;
                            zajecia_przydzielone.pb(wybrane_fizyka_cwiczenia[c]);
                            add_to_plan(plan, wybrane_fizyka_cwiczenia[c]);

                            for (int d = 0; d < wybrane_programowanie_cwiczenia.size(); d++) {
                                if (can_add(plan, wybrane_programowanie_cwiczenia[d])) {
                                    vector<vector<bool>> plan_copy4 = plan;
                                    zajecia_przydzielone.pb(wybrane_programowanie_cwiczenia[d]);
                                    add_to_plan(plan, wybrane_programowanie_cwiczenia[d]);

                                    for (int e = 0; e < wybrane_labolatorium.size(); e++) {
                                        if(can_add(plan, wybrane_labolatorium[e])){
                                            vector<vector<bool>> plan_copy5 = plan;
                                            zajecia_przydzielone.pb(wybrane_labolatorium[e]);
                                            add_to_plan(plan, wybrane_labolatorium[e]);

                                            print_wybrane_cwiczenia(zajecia_przydzielone, liczba_wygenerowanych_planow, plan);

                                            zajecia_przydzielone.pob();
                                            plan = plan_copy5;

                                        }
                                    }
                                    zajecia_przydzielone.pob();
                                    plan = plan_copy4;
                                }
                            }
                            zajecia_przydzielone.pob();
                            plan = plan_copy3;
                        }
                    }
                    zajecia_przydzielone.pob();
                    plan = plan_copy2;

                }
            }
            zajecia_przydzielone.pob();
            plan = plan_copy1;
        }
    }
    cout << "Zeby zakonczyc program, napisz \"exit\" i nacisnij enter." << ndl;
    string s;
    cin >> s;
    while(s != "exit"){
        cin >> s;
    }
    return 0;
}