#include <iostream>
using namespace std;

int getMax(int* mass, int n) {// Íàõîäèò ìàêñèìàëüíîå ÷èñëî â ìàññèâå
    int max = mass[0];
    for (int i = 1; i < n; i++) {
        if (mass[i] > max) {
            max = mass[i];
        }
    }
    return max;
}

void radix_sort_asc(int* mass, int n) {
    if (n <= 1) return;//ïðîâåðêà ìàññèâà íà ïóñòîòó

    int max = getMax(mass, n);//íàõîäèì ìàêñèìàëüíîå ÷èñëî
    int* temp = new int[n]; //ñîçäàåì âðåìåííûé ìàññèâ

    for (int exp = 1; max / exp > 0; exp *= 10) { // Ñîðòèðóåì ïî êàæäîìó ðàçðÿäó
        int count[10] = { 0 };

        for (int i = 0; i < n; i++) {// Ñ÷èòàåì öèôðû
            count[(mass[i] / exp) % 10]++;
        }
        for (int i = 1; i < 10; i++) {// Íàêîïëåíèå ñ÷åò÷èêîâ
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i--) {// Ñòðîèì âðåìåííûé ìàññèâ
            temp[count[(mass[i] / exp) % 10] - 1] = mass[i];
            count[(mass[i] / exp) % 10]--;
        }
        for (int i = 0; i < n; i++) {// Êîïèðóåì îáðàòíî
            mass[i] = temp[i];
        }
    }
    delete[] temp;
}

void radix_sort_desc(int* mass, int n) {
    if (n <= 1) return;//ïðîâåðêà ìàññèâà íà ïóñòîòó

    int max = getMax(mass, n);//íàõîäèì ìàêñèìàëüíîå ÷èñëî
    int* temp = new int[n];//ñîçäàåì âðåìåííûé ìàññèâ

    for (int exp = 1; max / exp > 0; exp *= 10) {
        int count[10] = { 0 };

        for (int i = 0; i < n; i++) {// Ñ÷èòàåì öèôðû
            count[(mass[i] / exp) % 10]++;
        }
        for (int i = 8; i >= 0; i--) {// Íàêîïëåíèå â îáðàòíîì ïîðÿäêå äëÿ óáûâàíèÿ
            count[i] += count[i + 1];
        }
        for (int i = n - 1; i >= 0; i--) {// Ñòðîèì âðåìåííûé ìàññèâ
            temp[count[(mass[i] / exp) % 10] - 1] = mass[i];
            count[(mass[i] / exp) % 10]--;
        }
        for (int i = 0; i < n; i++) {// Êîïèðóåì îáðàòíî
            mass[i] = temp[i];
        }
    }
    delete[] temp;
}
