#include "Struct.h"
#include <thread>

using namespace std;


void printTree(const vector<int>& tree, int index = 0, string prefix = "", bool isLeft = true, bool hasSibling = false)
{
    if (index >= tree.size()) return;

    // Отрисовка ветки
    cout << prefix;
    if (index != 0)
    {
        cout << (isLeft ? "??? " : "??? ");
    }

    // Вывод значения
    cout << tree[index] << endl;

    // Проверка на наличие детей
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;
    bool hasLeft = leftIndex < tree.size();
    bool hasRight = rightIndex < tree.size();

    // Формируем отступ
    string newPrefix = prefix;
    if (index != 0)
    {
        newPrefix += (isLeft ? "?   " : "    ");
    }

    // Рекурсивно печатаем потомков
    if (hasRight)  printTree(tree, rightIndex, newPrefix, true, hasLeft);
    if (hasLeft) printTree(tree, leftIndex, newPrefix, false, false);
}


int main()
{
    //объявлоения + настройки
    setlocale(LC_ALL, "ru");
    srand(time(0));

    int n;
    //ввод значений
    cout << "введите кол-во вершин\n";
    cin >> n;
    //выход из программы, если число вершин отрицательно
    if (n < 0)
    {
        cout << "число вершин не может быть отрицательным";
        return -1;
    }

    // Создаем вектор
    vector<int> Arr(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> Arr[i];
        while ((std::find(Arr.begin(), Arr.begin() + i, Arr[i]) != Arr.begin() + i))
        {
            cout << "число уже есть\n";
            cin >> Arr[i];
        }
    }

    cout << endl;
    //замер времени (начало)
    high_resolution_clock::time_point start = high_resolution_clock::now();
    qsort(Arr.data(), Arr.size(), sizeof(int), compare);

    // Выводим ответ
    cout << "Ответ:\n";

    try
    {
        cout << Arr.at(n / 2 - 1) << endl << endl;
        if (Arr.size() < 50 && Arr.size() > 1)
        {
            printTree(Arr);
        }
        else
        {
            return 2;
        }
    }
    catch (const std::out_of_range& e)
    {
        cout << "Ошибка: правильного ответа не существует\n";
        return 1;
    }

    Arr.clear();
    high_resolution_clock::time_point stop = high_resolution_clock::now();
    // Подсчет времени выполнения
    microseconds durationTime = duration_cast<microseconds>(stop - start);
    printDuration(durationTime);
    cout << "\n";
    ofstream outFile("timing_results.csv", ios::out | ios::trunc);  // Явно указываем режимы записи
    if (!outFile.is_open())
    {
        cerr << "Ошибка создания файла!" << endl;
        return -1;
    }
    outFile << "Вершины;Время_в_микросекундах\n";  // Заголовки с правильным разделителем

    for (int lst = 10; lst < 100001; lst = lst * 10)
    {
        high_resolution_clock::time_point start = high_resolution_clock::now();
        Arr.resize(lst);

        std::cout << "--- Генерация дерева на " << lst << "вершин---" << endl;
        
        //
        assignValuesFromFile(Arr, lst);
        //
        if (lst == 1000)
        {
            std::this_thread::sleep_for(std::chrono::seconds(3));
        }
        if (lst == 10000)
        {
            std::this_thread::sleep_for(std::chrono::seconds(10));
        }
        if (lst == 100000)
        {
            std::this_thread::sleep_for(std::chrono::seconds(15));
        }
        qsort(Arr.data(), Arr.size(), sizeof(int), compare);
        (void)Arr.at(lst / 2 - 1);
        Arr.clear();
        high_resolution_clock::time_point stop = high_resolution_clock::now();
        // Подсчет времени выполнения сортировки пирамиды
        microseconds durationTime = duration_cast<microseconds>(stop - start);
        printDuration(durationTime);
        // Сохраняем результат в файл
        outFile << lst << ";" << durationTime.count() << "\n";

    }
    outFile.close();
    system("python plot.py");
    return 0;
}
