#include <iostream>
#include "sorts.h"
using namespace std;

void shell_sort_asc(int* mass, int n) {
    int gap = 1;
    while (gap < n / 3) {
        gap = gap * 3 + 1;  // 1, 4, 13, 40, 121, ...
    }
    while (gap > 0) {
        for (int i = gap; i < n; i++) { // Сортировка вставками с шагом gap
            int temp = mass[i];
            int j = i;
            while (j >= gap && mass[j - gap] > temp) {// Сдвигаем элементы, пока не найдем правильное место
                mass[j] = mass[j - gap];
                j -= gap;
            }
            mass[j] = temp;
        }
        gap = (gap - 1) / 3;// Уменьшаем шаг
    }
}

void shell_sort_desc(int* mass, int n) {
    int gap = 1;
    while (gap < n / 3) {
        gap = gap * 3 + 1;
    }

    while (gap > 0) {
        for (int i = gap; i < n; i++) {// Сортировка вставками с шагом gap
            int temp = mass[i];
            int j = i;
            while (j >= gap && mass[j - gap] < temp) {// Сдвигаем элементы, пока не найдем правильное место
                mass[j] = mass[j - gap];
                j -= gap;
            }
            mass[j] = temp;
        }
        gap = (gap - 1) / 3;// Уменьшаем шаг
    }
}
