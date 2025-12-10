// сортировки.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include "sorts.h"
using namespace std;

void print_mass(int* mass, int n) {
	for (int i = 0; i < n; i++)
		cout << mass[i] << " ";
	cout << endl;
}
void random_mass(int* mass, int n) {
	for (int i = 0; i < n; i++)
		mass[i] = rand() % 1000;
}
int main(){
	setlocale(LC_ALL, "ru");
	int n, sorts, naprav;
	cout << "Введите количество элементов массива:";
	cin >> n;
	int* mass = new int[n];
	random_mass(mass, n);
	cout << "\n Исходний массив:";
	print_mass(mass, n);

	cout << "\nМеню сортировок" << endl;
	cout << "Выберете направление сортировки" << endl;
	cout << "1. По убыванию" << endl;
	cout << "2. По возрастанию" << endl;
	cout << "3. Выход" << endl;
	cin >> naprav;
	cout << "\nВыберите алгоритм сортировки:" << endl;
	cout << "1. Сортировка парным обменом" << endl;
	cout << "2. Сортировка простым выбором" << endl;
	cout << "3. Сортировка простыми вставками" << endl;
	cout << "4. Сортировка Шелла" << endl;
	cout << "5. Быстрая сортивока" << endl;
	cout << "6. Поразрядная сортирвока" << endl;
	cin >> sorts;
	
	switch (sorts) {
	case 1: 
		if (naprav == 1) {
			radix_sort_desc(mass, n);
		}
		else radix_sort_asc(mass, n);
		break;
	case 2:
		if (naprav == 1) {
			odd_even_sort_desc(mass, n);
		}
		else odd_even_sort_asc(mass, n);
		break;
	case 3:
		if (naprav == 1) {
			insertion_sort_desc(mass, n);
		}
		else insertion_sort_asc(mass, n);
		break;
	case 4:
		if (naprav == 1) {
			selection_sort_desc(mass, n);
		}
		else selection_sort_asc(mass, n);
		break;
	case 5:
		if (naprav == 1) {
			shell_sort_desc(mass, n);
		}
		else shell_sort_asc(mass, n);
		break;
	case 6:
		if (naprav == 1) {
			quick_sort_desc(mass, n);
		}
		else quick_sort_asc(mass, n);
		break;
	default:
		cout << "Нет такого варианта ответа!" << endl;
		delete[] mass;
		return 1;
	}
	cout << "Результат:";
	print_mass(mass, n);

	delete[] mass;

	return 0;
   
}

