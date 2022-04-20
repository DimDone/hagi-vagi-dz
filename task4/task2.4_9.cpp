#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ifstream in("in.txt");
ofstream out("out.txt");


void print(int** arr, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			out << arr[i][j] << " ";
		}
		out << endl;
	}
}

int** input(int n) {
	string str;
	string line;
	string s;
	int j = 0;
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			in >> arr[i][j];
		}
	}
	return arr;
}

vector <int> combSort(vector <int> x) { // сортировка расческой
	int g = x.size() / 1.247f;
	while (g >= 1) {
		if (g < 1)
			g = 1;
		else
			for (int j = 0; j < x.size() - g; j++)
				if (x[j] > x[g + j])
					swap(x[j], x[g + j]);
		g /= 1.247f;
	}
	return x;
}

vector <int> combSortRev(vector <int> x) { // сортировка расческой по убыванию
	int g = x.size() / 1.247f; // шаг
	while (g >= 1) {
		if (g < 1)
			g = 1;
		else
			for (int j = 0; j < x.size() - g; j++)
				if (x[j] < x[g + j])
					swap(x[j], x[g + j]);
		g /= 1.247f; // уменьшаем шаг
	}
	return x;
}

auto combSortArr(int** arr, int n) {
	for (int j = 0; j < n; j++) {
		vector <int> x(n);
		for (int i = 0; i < n; i++) { // заполняем вектор элементами столбца 
			x[i] = arr[i][j];
		}
		if ((j + 1) % 3 != 0) // каждый не 3 столбец
			x = combSort(x);
		else
			x = combSortRev(x);
		for (int i = 0; i < n; i++)
			arr[i][j] = x[i];
	}
	return arr;
}

int main() {
	int n;
	string str;
	getline(in, str);
	n = stoi(str);
	int** arr;
	arr = input(n);
	arr = combSortArr(arr, n);
	print(arr, n);
}