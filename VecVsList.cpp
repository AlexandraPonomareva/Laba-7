#include <iostream>
#include <vector>
#include <list>
#include <chrono>

/*
std::vector
Преимущества:
Динамический размер: может изменять свой размер во время выполнения.
Быстрый доступ к элементам: индексация позволяет быстро получить доступ к любому элементу.
Эффективное использование памяти: хранит все элементы последовательно в памяти.
Недостатки:
Модификация размера (добавление или удаление элементов) может быть медленной, так как требует перемещения элементов.
std::list
Преимущества:
Очень быстрая вставка и удаление элементов: операции выполняются за константное время O(1).
Подходит для структур данных, где часто происходят такие операции.
Недостатки:
Более медленный доступ к элементам: требуется проходить через список до нужного элемента.
Неэффективное использование памяти: каждый элемент содержит ссылку на следующий и предыдущий элементы, что увеличивает потребление памяти.
*/

void measurePerformance(std::vector<int>&, std::list<int>&);

int main() {
    const int size = 1000000; // Размер массива для тестирования

    // Создаем вектор
    std::vector<int> vec(size);

    // Создаем список
    std::list<int> lst;

    //Заполняем оба контейнера рандомными значениями
    for (int i = 0; i < size; ++i) {
        lst.push_back(rand());
        vec[i] = rand();
    }

    // Выводим объем памяти, занимаемый каждым из контейнеров
    std::cout << "Vector uses " << sizeof(vec) << " bytes\n";
    std::cout << "List uses " << sizeof(lst) << " bytes\n";

    // Измеряем производительность
    measurePerformance(vec, lst);


    return 0;
}

void measurePerformance(std::vector<int>& vec, std::list<int>& lst) {
    //Ставим метку для начала добавления элемента в вектор
    auto startV = std::chrono::high_resolution_clock::now();

    // Добавляем элемент в начало вектора
    vec.insert(vec.begin(), rand());

    //Ставим метку для конца добавления элемента в вектор
    auto endV = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffV = endV - startV;

    std::cout << "Vector performance: " << diffV.count() << " seconds\n";

    //Аналогичный ход действий для списка
    auto startl = std::chrono::high_resolution_clock::now();

    lst.push_front(rand());

    auto endl = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffl = endl - startl;

    std::cout << "List performance: " << diffl.count() << " seconds\n";
}