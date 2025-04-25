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

// ������� ������� ������ �������� ������ �����
void printArr(vector<int>& Arr, int& n);
//������� ���������� �����
int getRandomNumber(int min, int max);
// ������� ��� ������ ������� � ������ �������
void printDuration(microseconds duration);
// ������� ��������� ��� qsort
int compare(const void* a, const void* b);
void assignValuesFromFile(std::vector<int>& vec, int i);