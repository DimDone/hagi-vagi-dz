#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;

vector <int> input (vector <int> c, int n){ // функция заполнения вектора
    srand(time(0));
    for (int i = 0; i < n; i++)
        c.push_back(1 + rand() % 10);
    return c;
}

void output(vector <int> n){ // функция вывода вектора
    for(vector<int>::iterator iter = n.begin(); iter != n.end(); iter++)
        cout << *iter << ' ';
    cout << endl;
}

int X;
bool kr (int x){ // проверка на кратность
    return (x % X == 0);
}

int A, B;
bool pr (int l){ // проверка на принадлежность к промежутку
    return (l >= A && l <= B);
}

int main(){
    int n;
    cout << "n = "; cin >> n;
    vector <int> a; vector <int> b;
    a = input (a, n);
    int n1 = n;
    cout << "n1 = "; cin >> n;
    b = input (b, n);
    cout << "vector a: "; output(a); 
    cout << "vector b: "; output(b);
    
    cout << "X = "; cin >> X;
    vector<int>::iterator it = remove_if(a.begin(), a.end(), kr); // удаление элементов, кратных Х
    a.erase(it , a.end());
    sort(a.begin(), a.end()); // сортировка
    cout << "A, B = "; cin >> A; cin >> B;
    int y;
    cout << "y = "; cin >> y;
    replace_if(b.begin(), b.end(), pr, y); // замена элементов, принадлежащих промежутку от А до В
    sort(b.begin(), b.end()); // сортировка
    cout << "sorted vector a: "; output(a); 
    cout << "sorted vector b: "; output(b);

    vector <int> c(a.size() + b.size()); // вспомогательный вектор 
    merge(a.begin(), a.end(), b.begin(), b.end(), c.begin()); // сортировка слиянием
    output(c);
}