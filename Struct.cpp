#include "Struct.h"

// функция функция вывода значений вершин графа
void printArr(vector<int>& Arr, int& n)
{
    for (int i = 0; i < n; i++)
    {
        cout << Arr[i] << endl;
    }
}

//функция рандомного числа
int getRandomNumber(int min, int max)
{
    return rand() % (max - min) + min;
}

// Функция для вывода времени в нужном формате
void printDuration(microseconds duration)
{
    milliseconds millisec = duration_cast<milliseconds>(duration); // Получаем время в миллисекундах
    int microsec = duration.count() % 1000; // Остаток времени в микросекундах

    cout << millisec.count()
        << setfill('0') << setw(3) << microsec
        << " microsec" << endl;
}

// Функция сравнения для qsort
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

void assignValuesFromFile(vector<int>& vec, int lst) {
    string txt;

    // Выбираем имя файла в зависимости от lst
    if (lst == 10)       txt = "text1.txt";
    else if (lst == 100) txt = "text2.txt";
    else if (lst == 1000) txt = "text3.txt";
    else if (lst == 10000) txt = "text4.txt";
    else if (lst == 100000) txt = "text5.txt";
    else {
        throw runtime_error("Unsupported lst value: " + to_string(lst));
    }

    ifstream file(txt);
    if (!file.is_open()) {
        throw runtime_error("Failed to open file: " + txt);
    }

    string line;
    size_t index;
    int value;

    while (getline(file, line)) {
        istringstream iss(line);
        if (!(iss >> index >> value)) {
            continue; // Пропускаем некорректные строки
        }

        if (index >= vec.size()) {
            vec.resize(index + 1); // Расширяем вектор при необходимости
        }

        vec[index] = value;
    }
}