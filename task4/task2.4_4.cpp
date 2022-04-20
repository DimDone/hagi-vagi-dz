#include <iostream>
#include <vector>
#include <fstream>
#include <string>

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

vector <int> insertionSort(vector <int> x){ // сортировка вектора вставками
	int b = 0;
	for (int a = 1; a < x.size(); a++)
	{
		auto key = x[a];
		b = a - 1;
		while (b >= 0 && key > x[b])
		{
			x[b + 1] = x[b];
			b--;
		}
		x[b + 1] = key;
	}
	return x;
}

auto bucketSort(int** arr, int n) { 
	for (int i = 0; i < n; i++) {
		vector <vector <int>> x(10);
		int* a = new int[n];
		for (int j = 0; j < n; j++) {
			a[j] = arr[i][j];
		}
		for (int h = 0; h < n; h++) { // записываем строку в массив и разбиваем её по элементам на блоки
			if (a[h] / 10 == 10)
				x[a[h] / 10 - 1].push_back(a[h]);
			else
				x[(a[h]) / 10].push_back(a[h]);
		}
		for (int h = 0; h < 10; h++) // сортируем вектор блоков вставками
			x[h] = insertionSort(x[h]);
		int k = 0;
		for (int h = 9; h >= 0; h--)
			for (int j = 0; j < x[h].size(); j++) { // возвращаем элементы в массив
				a[k] = x[h][j];
				k++;
			}
		for (int j = 0; j < n; j++) // возвращаем массив в строку
			arr[i][j] = a[j];
	}
	return arr;
}


int main(){
	int n;
	string str;
	getline(in, str);
	n = stoi(str);
	int** arr;
	arr = input(n);
	arr = bucketSort(arr, n);
	print(arr, n);
}