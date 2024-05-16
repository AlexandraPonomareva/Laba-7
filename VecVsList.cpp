#include <iostream>
#include <vector>
#include <list>
#include <chrono>

/*
std::vector
������������:
������������ ������: ����� �������� ���� ������ �� ����� ����������.
������� ������ � ���������: ���������� ��������� ������ �������� ������ � ������ ��������.
����������� ������������� ������: ������ ��� �������� ��������������� � ������.
����������:
����������� ������� (���������� ��� �������� ���������) ����� ���� ���������, ��� ��� ������� ����������� ���������.
std::list
������������:
����� ������� ������� � �������� ���������: �������� ����������� �� ����������� ����� O(1).
�������� ��� �������� ������, ��� ����� ���������� ����� ��������.
����������:
����� ��������� ������ � ���������: ��������� ��������� ����� ������ �� ������� ��������.
������������� ������������� ������: ������ ������� �������� ������ �� ��������� � ���������� ��������, ��� ����������� ����������� ������.
*/

void measurePerformance(std::vector<int>&, std::list<int>&);

int main() {
    const int size = 1000000; // ������ ������� ��� ������������

    // ������� ������
    std::vector<int> vec(size);

    // ������� ������
    std::list<int> lst;

    //��������� ��� ���������� ���������� ����������
    for (int i = 0; i < size; ++i) {
        lst.push_back(rand());
        vec[i] = rand();
    }

    // ������� ����� ������, ���������� ������ �� �����������
    std::cout << "Vector uses " << sizeof(vec) << " bytes\n";
    std::cout << "List uses " << sizeof(lst) << " bytes\n";

    // �������� ������������������
    measurePerformance(vec, lst);


    return 0;
}

void measurePerformance(std::vector<int>& vec, std::list<int>& lst) {
    //������ ����� ��� ������ ���������� �������� � ������
    auto startV = std::chrono::high_resolution_clock::now();

    // ��������� ������� � ������ �������
    vec.insert(vec.begin(), rand());

    //������ ����� ��� ����� ���������� �������� � ������
    auto endV = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffV = endV - startV;

    std::cout << "Vector performance: " << diffV.count() << " seconds\n";

    //����������� ��� �������� ��� ������
    auto startl = std::chrono::high_resolution_clock::now();

    lst.push_front(rand());

    auto endl = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffl = endl - startl;

    std::cout << "List performance: " << diffl.count() << " seconds\n";
}