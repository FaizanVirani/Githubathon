#pragma once
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

bool accounts();
bool validInt(string);
bool validDouble(string);
void writeToFile(string, int, string, int);
void setName(string);
void setPoints(double);
void mafia(int, string, int);
void citizen(int, string, int);
void exchangeSort(vector <string>&);
int randomize();
