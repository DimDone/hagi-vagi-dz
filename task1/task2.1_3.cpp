#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

vector <int> input (vector <int> c, int n){ // функция заполнения вектора
    srand(time(0));
    for (int i = 0; i < n; i++)
        c.push_back(1 + rand() % 10);
    return c;
}

void output(vector <int> n){ // функция вывода
    for(vector<int>::iterator iter = n.begin(); iter != n.end(); iter++)
        cout << *iter << ' ';
    cout << endl;
}

bool nechet (int x){ // проверка на нечетность
    return (x % 2 != 0);
}

int main(){
    vector <int> a;
    int n; 
    cout << "n = "; cin >> n;
    a = input (a, n);
    output(a);
    replace_if(a.begin(), a.end(), nechet, 0); // замена нечетных элементов на 0
    output(a);
}