#include <iostream>
using namespace std;

void obmen(int& a, int& b) {// Îáìåí äâóõ ýëåìåíòîâ
    int temp = a;
    a = b;
    b = temp;
}

int razvoz(int* mass, int low, int high) {// Ðàçäåëåíèå ìàññèâà äëÿ ñîðòèðîâêè ïî âîçðàñòàíèþ 
    int pivot = mass[high];// Îïîðíûé ýëåìåíò - ïîñëåäíèé ýëåìåíò ìàññèâà
    int i = low - 1;// Èíäåêñ, óêàçûâàþùèé íà ïîçèöèþ, ãäå áóäóò ýëåìåíòû ìåíüøå îïîðíîãî

    for (int j = low; j < high; j++) {
        if (mass[j] <= pivot) {
            i++;  
            obmen(mass[i], mass[j]);  
        }
    }
    obmen(mass[i + 1], mass[high]);// Ïîìåùàåì îïîðíûé ýëåìåíò íà ïðàâèëüíóþ ïîçèöèþ
    return i + 1;// Âîçâðàùàåì èíäåêñ îïîðíîãî ýëåìåíòà
}

int razyb(int* mass, int low, int high) {// Ðàçäåëåíèå ìàññèâà äëÿ ñîðòèðîâêè ïî óáûâàíèþ
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

void quickSortAscRecursive(int* mass, int low, int high) {// Ðåêóðñèâíàÿ áûñòðàÿ ñîðòèðîâêà ïî âîçðàñòàíèþ
    if (low < high) {// åñëè â ïîäìàññèâå áîëåå îäíîãî ýëåìåíòà
        int pivotIndex = razvoz(mass, low, high); // Ðàçäåëÿåì ìàññèâ è ïîëó÷àåì èíäåêñ îïîðíîãî ýëåìåíòà
        quickSortAscRecursive(mass, low, pivotIndex - 1);// Ðåêóðñèâíî ñîðòèðóåì ëåâóþ ÷àñòü 
        quickSortAscRecursive(mass, pivotIndex + 1, high);// Ðåêóðñèâíî ñîðòèðóåì ïðàâóþ ÷àñòü 
    }
}

void quickSortDescRecursive(int* mass, int low, int high) {// Ðåêóðñèâíàÿ áûñòðàÿ ñîðòèðîâêà ïî óáûâàíèþ
    if (low < high) {
        int pivotIndex = razyb(mass, low, high);
        quickSortDescRecursive(mass, low, pivotIndex - 1);
        quickSortDescRecursive(mass, pivotIndex + 1, high);
    }
}

void quick_sort_asc(int* mass, int n) {// Îñíîâíûå ôóíêöèè äëÿ èñïîëüçîâàíèÿ â ïðîãðàììå
    if (n <= 1) return;
    quickSortAscRecursive(mass, 0, n - 1);
}

void quick_sort_desc(int* mass, int n) {
    if (n <= 1) return;
    quickSortDescRecursive(mass, 0, n - 1);
}
