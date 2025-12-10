#include <iostream>
using namespace std;

void odd_even_sort_asc(int* mass, int n) {
    bool sorted = false;//ôëàã äëÿ ïðîâåðêè

    while (!sorted) {
        sorted = true;
        for (int i = 1; i < n - 1; i += 2) { //íå÷åòíûé ïðîõîä
            if (mass[i] > mass[i + 1]) {
                int temp = mass[i];
                mass[i] = mass[i + 1];
                mass[i + 1] = temp;
                sorted = false;
            }
        }
        for (int i = 0; i < n - 1; i += 2) { //÷åòíûé ïðîõîä
            if (mass[i] > mass[i + 1]) {
                int temp = mass[i];
                mass[i] = mass[i + 1];
                mass[i + 1] = temp;
                sorted = false;
            }
        }
    }
}

void odd_even_sort_desc(int* mass, int n) {
    bool sorted = false;//ôëàã äëÿ ïðîâåðêè

    while (!sorted) {
        sorted = true;
        for (int i = 1; i < n - 1; i += 2) {//íå÷åòíûé ïðîõîä
            if (mass[i] < mass[i + 1]) {
                int temp = mass[i];
                mass[i] = mass[i + 1];
                mass[i + 1] = temp;
                sorted = false;
            }
        }
        for (int i = 0; i < n - 1; i += 2) {//÷åòíûé ïðîõîä
            if (mass[i] < mass[i + 1]) {
                int temp = mass[i];
                mass[i] = mass[i + 1];
                mass[i + 1] = temp;
                sorted = false;
            }
        }
    }
}
