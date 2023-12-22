// cwiczenie.h
#ifndef CWICZENIA_H
#define CWICZENIA_H

#include "struktury.h"

#include <vector>
#include <string>

using namespace std;



void stworz_cwiczenia_analiza(vector<zajecia> &analiza_cwiczenia);
void stworz_cwiczenia_algebra(vector<zajecia> &algebra_cwiczenia);
void stworz_cwiczenia_fizyka(vector<zajecia> &fizyka_cwiczenia);
void stworz_cwiczenia_programowanie(vector<zajecia> &programowanie_cwiczenia);
void stworz_laboratorium(vector<zajecia> &laboratorium);

#endif