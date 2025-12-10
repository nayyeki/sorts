#include <iostream>
#include "sorts.h"
using namespace std;

void selection_sort_asc(int* mass, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < n; j++) {// Поиск минимального элемента
            if (mass[j] < mass[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {// Обмен минимального элемента с текущим
            int temp = mass[i];
            mass[i] = mass[min_index];
            mass[min_index] = temp;
        }
    }
}

void selection_sort_desc(int* mass, int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_index = i;

        for (int j = i + 1; j < n; j++) {// Поиск максимального элемента
            if (mass[j] > mass[max_index]) {
                max_index = j;
            }
        }

        if (max_index != i) {// Обмен максимального элемента с текущим
            int temp = mass[i];
            mass[i] = mass[max_index];
            mass[max_index] = temp;
        }
    }
}