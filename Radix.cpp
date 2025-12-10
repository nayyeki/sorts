#include <iostream>
#include "sorts.h"
using namespace std;

int getMax(int* mass, int n) {// Находит максимальное число в массиве
    int max = mass[0];
    for (int i = 1; i < n; i++) {
        if (mass[i] > max) {
            max = mass[i];
        }
    }
    return max;
}

void radix_sort_asc(int* mass, int n) {
    if (n <= 1) return;//проверка массива на пустоту

    int max = getMax(mass, n);//находим максимальное число
    int* temp = new int[n]; //создаем временный массив

    for (int exp = 1; max / exp > 0; exp *= 10) { // Сортируем по каждому разряду
        int count[10] = { 0 };

        for (int i = 0; i < n; i++) {// Считаем цифры
            count[(mass[i] / exp) % 10]++;
        }
        for (int i = 1; i < 10; i++) {// Накопление счетчиков
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {// Строим временный массив
            temp[count[(mass[i] / exp) % 10] - 1] = mass[i];
            count[(mass[i] / exp) % 10]--;
        }
        for (int i = 0; i < n; i++) {// Копируем обратно
            mass[i] = temp[i];
        }
    }
    delete[] temp;
}

void radix_sort_desc(int* mass, int n) {
    if (n <= 1) return;//проверка массива на пустоту

    int max = getMax(mass, n);//находим максимальное число
    int* temp = new int[n];//создаем временный массив

    for (int exp = 1; max / exp > 0; exp *= 10) {
        int count[10] = { 0 };

        for (int i = 0; i < n; i++) {// Считаем цифры
            count[(mass[i] / exp) % 10]++;
        }
        for (int i = 8; i >= 0; i--) {// Накопление в обратном порядке для убывания
            count[i] += count[i + 1];
        }
        for (int i = n - 1; i >= 0; i--) {// Строим временный массив
            temp[count[(mass[i] / exp) % 10] - 1] = mass[i];
            count[(mass[i] / exp) % 10]--;
        }
        for (int i = 0; i < n; i++) {// Копируем обратно
            mass[i] = temp[i];
        }
    }
    delete[] temp;
}