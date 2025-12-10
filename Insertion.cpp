#include <iostream>
using namespace std;

void insertion_sort_asc(int* mass, int n) {
    for (int i = 1; i < n; i++) {
        int key = mass[i];  // òåêóùèé ýëåìåíò äëÿ âñòàâêè
        int j = i - 1;

        while (j >= 0 && mass[j] > key) {// Ñäâèãàåì ýëåìåíòû áîëüøå key âïðàâî
            mass[j + 1] = mass[j];
            j--;
        }
        mass[j + 1] = key;// Âñòàâëÿåì key íà ïðàâèëüíîå ìåñòî
    }
}

void insertion_sort_desc(int* mass, int n) {
    for (int i = 1; i < n; i++) {
        int key = mass[i];  // òåêóùèé ýëåìåíò äëÿ âñòàâêè
        int j = i - 1;

        while (j >= 0 && mass[j] < key) {// Ñäâèãàåì ýëåìåíòû ìåíüøå key âïðàâî
            mass[j + 1] = mass[j];
            j--;
        }
        mass[j + 1] = key;// Âñòàâëÿåì key íà ïðàâèëüíîå ìåñòî
    }
}
