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

vector <int> sortCh(vector <int> x) {
	int n = x.size();
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) { // пробегаем по четным элементам
			for (int j = 2; j < n; j += 2) {
				if (x[j - 1] > x[j]) swap(x[j - 1], x[j]);
			}
		}
		else { // пробегаем по нечетным элементам
			for (int j = 1; j < n; j += 2) {
				if (x[j - 1] > x[j]) swap(x[j - 1], x[j]);
			}
		}
	}
	return x;
}


int** sortChM(int** arr, int n) {
	vector <int> x;
	for (int k = 0; k < n - 1; k++) {
		for (int i = 0; i < n; i++)
			if (i + k < n)
				x.push_back(arr[i][i + k]); // идем по элементам над главной диагональю, закидывая их в вектор
		x = sortCh(x); //сортируем через чёт-нечёт
		int r = 0;
		for (int i = 0; i < n; i++) {
			if (i + k < n)
				arr[i][i + k] = x[r]; // возвращаем отсортированные значения в массив
			r++;
		}
		x.clear();
	}
	for (int k = 0; k < n - 1; k++) {
		for (int i = 0; i < n; i++)
			if (i + k < n)
				x.push_back(arr[i + k][i]); // идем по элементам под главной диагональю, закидывая их в вектор
		x = sortCh(x); //сортируем через чёт-нечёт
		int r = 0;
		for (int i = 0; i < n; i++) {
			if (i + k < n)
				arr[i + k][i] = x[r]; // возвращаем отсортированные значения в массив
			r++;
		}
		x.clear();
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
	arr = sortChM(arr, n);
	print(arr, n);
}