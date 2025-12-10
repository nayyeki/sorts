#include <iostream>
#include "sorts.h"
using namespace std;

void insertion_sort_asc(int* mass, int n) {
    for (int i = 1; i < n; i++) {
        int key = mass[i];  // текущий элемент для вставки
        int j = i - 1;

        while (j >= 0 && mass[j] > key) {// Сдвигаем элементы больше key вправо
            mass[j + 1] = mass[j];
            j--;
        }
        mass[j + 1] = key;// Вставляем key на правильное место
    }
}

void insertion_sort_desc(int* mass, int n) {
    for (int i = 1; i < n; i++) {
        int key = mass[i];  // текущий элемент для вставки
        int j = i - 1;

        while (j >= 0 && mass[j] < key) {// Сдвигаем элементы меньше key вправо
            mass[j + 1] = mass[j];
            j--;
        }
        mass[j + 1] = key;// Вставляем key на правильное место
    }
}
