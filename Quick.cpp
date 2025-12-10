#include <iostream>
#include "sorts.h"
using namespace std;

void obmen(int& a, int& b) {// Обмен двух элементов
    int temp = a;
    a = b;
    b = temp;
}

int razvoz(int* mass, int low, int high) {// Разделение массива для сортировки по возрастанию 
    int pivot = mass[high];// Опорный элемент - последний элемент массива
    int i = low - 1;// Индекс, указывающий на позицию, где будут элементы меньше опорного

    for (int j = low; j < high; j++) {
        if (mass[j] <= pivot) {
            i++;  
            obmen(mass[i], mass[j]);  
        }
    }
    obmen(mass[i + 1], mass[high]);// Помещаем опорный элемент на правильную позицию
    return i + 1;// Возвращаем индекс опорного элемента
}

int razyb(int* mass, int low, int high) {// Разделение массива для сортировки по убыванию
    int pivot = mass[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (mass[j] >= pivot) {
            i++;
            obmen(mass[i], mass[j]);
        }
    }
    obmen(mass[i + 1], mass[high]);
    return i + 1;
}

void quickSortAscRecursive(int* mass, int low, int high) {// Рекурсивная быстрая сортировка по возрастанию
    if (low < high) {// если в подмассиве более одного элемента
        int pivotIndex = razvoz(mass, low, high); // Разделяем массив и получаем индекс опорного элемента
        quickSortAscRecursive(mass, low, pivotIndex - 1);// Рекурсивно сортируем левую часть 
        quickSortAscRecursive(mass, pivotIndex + 1, high);// Рекурсивно сортируем правую часть 
    }
}

void quickSortDescRecursive(int* mass, int low, int high) {// Рекурсивная быстрая сортировка по убыванию
    if (low < high) {
        int pivotIndex = razyb(mass, low, high);
        quickSortDescRecursive(mass, low, pivotIndex - 1);
        quickSortDescRecursive(mass, pivotIndex + 1, high);
    }
}

void quick_sort_asc(int* mass, int n) {// Основные функции для использования в программе
    if (n <= 1) return;
    quickSortAscRecursive(mass, 0, n - 1);
}

void quick_sort_desc(int* mass, int n) {
    if (n <= 1) return;
    quickSortDescRecursive(mass, 0, n - 1);
}