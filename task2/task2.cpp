// task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct peaks
{
	float x, y;
};

map<int, peaks> read(ifstream & file) {
	map<int, peaks> val;
	int counter = 0;
	if (file.is_open()) {
		while (!file.eof()) {

			file >> val[counter].x >> val[counter].y;
			++counter;
		}
	}
	file.close();
	return val;
}

int proverka(map<int, peaks> &verch, peaks &point) {
	vector<float> valx;
	vector<float> valy;
	int result = -1;
	bool flag = false;
	float minx, miny, max_x, maxy;
	minx = miny = max_x = maxy = 0;
	for (auto c : verch) {
		valx.push_back(c.second.x);
		valy.push_back(c.second.y);
	}
	sort(begin(valx), end(valx));
	sort(begin(valy), end(valy));
	 minx = *valx.begin();
	 miny = *valy.begin();
	 max_x = valx[valx.size() - 1];
	 maxy = valy[valy.size() - 1];

	if (minx < point.x && miny < point.y && max_x > point.x && maxy > point.y) {
		result = 2;// точка внутри
	}
	else  {
		for (auto c : verch) {
			if (c.second.x == point.x && c.second.y == point.y) {

				result = 0; // точка на одной из вершин
				flag = true;
				break;
			}
			else if (c.second.x == point.x && miny < point.y && maxy > point.y ||
				c.second.y == point.y && minx < point.x && max_x > point.x) {
				result = 1; // на одной из сторон
				flag = true;
				break;
			}
		}
		if (!flag)
			result = 3; //вне четырехугольника
	}
	
	
	
	return result;
}


int main(int argc, char* argv[])
{
	map<int, peaks> p; // словарь состоящих из вершин четырехугольника
	map<int, peaks> points; // словарь точек
	ifstream peak;
	peak.open(argv[1]);
	p = read(peak);
	peak.open(argv[2]);
	points = read(peak);
    
	for (int i = 0; i < points.size(); ++i) {
		cout << proverka(p, points[i]) << endl;
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
