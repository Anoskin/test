// task3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <string>
#include <clocale>


using namespace std;
int main(int argc, char* argv[] )
{
	setlocale(LC_ALL, "ENG");
	WIN32_FIND_DATAA FindFileData;
	HANDLE hFind;
	vector<string> name  = { "Cash1.txt", "Cash2.txt", "Cash3.txt", "Cash4.txt", "Cash5.txt" };
	vector<double> interval;
	vector<int> number;
	double val = 0.00;
	ifstream file;
	//file.open(argv[1]);
	//LPCTSTR value = (LPCTSTR)(argv[1] + *name[0].c_str());
	for (int i = 0; i < 5; ++i) {
		hFind = FindFirstFileA(argv[1], &FindFileData);
		if (hFind == INVALID_HANDLE_VALUE)
		{
			cout << "FindFirstFile failed (%d)\n " << GetLastError() << endl;
			
		}
		else
		{
			double max = 0;
			int num = 0;
			file.open(FindFileData.cFileName);
			if (file.is_open()) {
				while (!file.eof()) {
					file >> val;
					interval.push_back(val);
				}
				for (int i = 0; i < interval.size(); ++i) {
					if (interval[i] > max)
					{
						max = interval[i];
						num = i;
					}
				}
				number.push_back(num);
			}
			FindClose(hFind);
		}
		for (auto c : number) {
			cout << c << endl;
		}
	
	}

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
