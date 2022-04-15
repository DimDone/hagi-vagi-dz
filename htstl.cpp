#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <set>

using namespace std;

void z1(vector <int> a, int n) {
    cout << "1)" << endl << "before: ";
    for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++)
        cout << *iter << ' ';
    cout << endl;
    nth_element(a.begin(), a.begin() + n, a.end()); // формирование последовательности таким образом, чтобы до n-го элемента были те, что меньше его, а после - больше
    cout << "after: ";
    for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++)
        cout << *iter << ' ';
    cout << endl;
}

void z2(list <int> b) {
    cout << "2)" << endl << "before: ";
    for (list <int>::iterator it = b.begin(); it != b.end(); it++)
        cout << *it << ' ';
    cout << endl;
    rotate(b.begin(), max_element(b.begin(), b.end()), b.end()); // сдвиг, чтобы максимальный был на первом месте
    cout << "after: ";
    for (list <int>::iterator it = b.begin(); it != b.end(); it++)
        cout << *it << ' ';
    cout << endl;
}

void z3(vector <int> a) {
    cout << "3)" << endl << "before: ";
    for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++)
        cout << *iter << ' ';
    cout << endl;
    make_heap(a.begin(), a.end()); // формирование кучи
    cout << "after: ";
    for (vector<int>::iterator iter = a.begin(); iter != a.end(); iter++)
        cout << *iter << ' ';
    cout << endl;
}

void z4(list <int> a, list <int> b) {
    cout << "4)" << endl;
    cout << "list 1: ";
    for (list<int>::iterator iter = a.begin(); iter != a.end(); iter++)
        cout << *iter << ' ';
    cout << endl;
    cout << "list 2: ";
    for (list<int>::iterator iter = b.begin(); iter != b.end(); iter++)
        cout << *iter << ' ';
    cout << endl;
    cout << "pr = " << inner_product(a.begin(), a.end(), b.begin(), 0) << endl; // перемножение значений на соответсвующих позициях
}

void z5(string b) {
    set <char> s;
    cout << "5) " << endl;
    cout << "string: ";
    for (string::iterator it = b.begin(); it != b.end(); it++) // заполнение контейнера различными символами строки
        cout << *it;
    cout << endl;
    for (string::iterator it = b.begin(); it != b.end(); it++) { // заполнение контейнера различными символами строки
        s.insert(*it);
    }
    cout << "count = " << s.size() << endl; // кол-во различных символов 
}

int main() {
    int n;
    cout << "n = "; cin >> n;
    vector <int> a = { 2, 7, 5, 8, 3, 1, 6, 4, 11, 9 };
    list <int> b = { 2, 3, 5, 8, 1, 7, 9, 4, 6, 10 };
    list <int> c = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    string m = "aaabbcdddde";
    z1(a, n); z2(b); z3(a); z4(b, c); z5(m);
}
