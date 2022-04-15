#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

vector <int> input (vector <int> c, int n){ // функция заполнение вектора
    srand(time(0));
    for (int i = 0; i < n; i++)
        c.push_back(1 + rand() % 10);
    return c;
}

bool chet (int x){ // проверка на четность
    return (x % 2 == 0);
}

int X;
bool krat (int x){ // проверка на кратность
    return (x % X == 0);
}

void output(vector <int> n){ // функция вывода
    for(vector<int>::iterator iter = n.begin(); iter != n.end(); iter++)
        cout << *iter << ' ';
    cout << endl;
}

int main(){
    vector <int> a; 
    int n; 
    cout << "n = "; cin >> n;
    a = input (a, n);
    output(a);
    
    cout << "X = "; cin >> X;
    int c = count_if(a.begin(), a.end(), krat); // количество элементов, кратных Х
    cout << "Count = " << c << '\n';
    vector<int>::iterator it = remove_if(a.begin(), a.end(), chet); // удаление четных элементов
    a.erase(it , a.end());
    output(a);
    
    int ma = *max_element(a.begin(), a.end()); // выделение максимума
    int mi = *min_element(a.begin(), a.end()); // выделение минимума
    replace(a.begin(), a.end(), ma, mi); // замена всех максимальных на минимальный
    output(a);
}