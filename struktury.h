// struktury.h
#ifndef STRUKTURY_H
#define STRUKTURY_H

#include <vector>
#include <string>

using namespace std;

struct zajecia {
    int liczba_godzin;
    vector<pair<int, int>> terminy;
    string nazwa;
    int nr_grupy;
    string prowadzacy;
};

#endif