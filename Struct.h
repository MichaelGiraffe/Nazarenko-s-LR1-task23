#pragma once
#include <iostream>
#include <queue>
#include <climits>
#include <fstream>//open_close .txt files
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <algorithm>
#include <thread>
#include <Windows.h>

using namespace std;
using namespace chrono;

// функция функция вывода значений вершин графа
void printArr(vector<int>& Arr, int& n);
//функция рандомного числа
int getRandomNumber(int min, int max);
// Функция для вывода времени в нужном формате
void printDuration(microseconds duration);
// Функция сравнения для qsort
int compare(const void* a, const void* b);
void assignValuesFromFile(std::vector<int>& vec, int i);
