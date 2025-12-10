#include <iostream>
#include "sorts.h"
using namespace std;

void odd_even_sort_asc(int* mass, int n) {
    bool sorted = false;//флаг для проверки

    while (!sorted) {
        sorted = true;
        for (int i = 1; i < n - 1; i += 2) { //нечетный проход
            if (mass[i] > mass[i + 1]) {
                int temp = mass[i];
                mass[i] = mass[i + 1];
                mass[i + 1] = temp;
                sorted = false;
            }
        }
        for (int i = 0; i < n - 1; i += 2) { //четный проход
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
    bool sorted = false;//флаг для проверки

    while (!sorted) {
        sorted = true;
        for (int i = 1; i < n - 1; i += 2) {//нечетный проход
            if (mass[i] < mass[i + 1]) {
                int temp = mass[i];
                mass[i] = mass[i + 1];
                mass[i + 1] = temp;
                sorted = false;
            }
        }
        for (int i = 0; i < n - 1; i += 2) {//четный проход
            if (mass[i] < mass[i + 1]) {
                int temp = mass[i];
                mass[i] = mass[i + 1];
                mass[i + 1] = temp;
                sorted = false;
            }
        }
    }
}
