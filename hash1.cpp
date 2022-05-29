#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>

using namespace std;

ifstream in("workers.txt");

const int m = 10;

int hashFuction(int x){
    return x%m;
}

int findYear(string s){
    return stoi(s.substr(s.length() - 4));
}


vector <list<string>> createTeble(){
    string s;
    vector <list <string>> n(m);
    while (in.peek() != EOF){
        getline(in, s);
        int k = hashFuction(findYear(s));
        n[k].push_back(s);
    }
    return n;
}

void outputTable(vector <list <string>> n){
    for(vector <list<string>>:: iterator it = n.begin(); it != n.end(); it++){
         list<string> a = *it;
         for(list<string>::iterator iter = a.begin(); iter != a.end(); iter++)
            cout << *iter << " | ";
         if (a.size() == 0)
            cout << "NULL" << endl;
         else cout << endl;
         }
}

void findEl(vector <list <string>> &n, int x){
    list <string> f = n[hashFuction(x)];
    for (list <string>::iterator iter = f.begin(); iter != f.end(); iter++)
        cout << *iter << " | ";
    cout << endl;
}

void delEl(vector <list <string>> &n, int x){
     n.erase(n.begin() + hashFuction(x));
}

int main() {
    vector <list <string>> n = createTeble();
    outputTable(n);
    cout << "Введите год, который хотите найти и удалить: ";
    int x; cin >> x;
    cout << "Вы искали: "; findEl(n, x);
    delEl(n, x);
    outputTable(n);
}