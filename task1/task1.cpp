// task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <sstream>


using namespace std;

double procentil90(vector<double> & arr) {

	double fact = 0.00;
	double integer = 0;
	double proc = 90.00;
	double kol = 0.00;
	double result = 0.00;
	kol = ((proc/100 * (arr.size() - 1) + 1));
	fact = modf(kol, &integer);
	result = arr[integer - 1] + fact * (arr[integer] - arr[integer - 1]);

	return result;
}


double mediana(vector<double> & arr) {
	int const size = arr.size();
	double medval = 0.00;
	if (size % 2 != 0) // проверка на четность размера массива
		medval = arr[(size - 1) / 2];
	else
		medval = (arr[size / 2] + arr[size / 2 - 1]) / 2;
	
	return medval;
}

double sred(vector<double> & arr) {
	int const size = arr.size();
	double sum = 0;
	for (auto c : arr) {
		sum += c;
	}

	return sum / size;
}

int main( int argc, char *argv[] )
{
	vector<double> array;
	string val;
	ifstream file;
	double dobl = 0.00;
	
	if (argv[1] == NULL) {
		cout << "Not arg[1]" << endl;
			exit(1);
	}

	file.open(argv[1]);

	if (file.is_open()) {
		//cout << "file is open" << endl;
		while (getline(file, val)) {
			stringstream ss(val);
			ss >> dobl;
			array.push_back(dobl);
		}
	}
	else 
		cout << "Not open" << endl;
	file.close();
	sort(begin(array), end(array));

	cout << procentil90(array) << endl;
	cout << mediana(array) << endl;
	cout << array [array.size() - 1] << endl;
	cout << array[0] << endl;
	cout << sred(array) << endl;

	return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
