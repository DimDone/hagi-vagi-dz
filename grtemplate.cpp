#include <iostream>
#include <map>
#include <list>
#include <fstream>

using namespace std;

ifstream in("data.txt");

map<int, list<int>> MakeGr(bool orient) { //создание списка смежности графа
    map<int, list<int>> l_Adj;
    int x, y; // x<->y or x->y
    while (in.peek() != EOF) {
        in >> x >> y;
        auto it_x = l_Adj.find(x);
        bool fl = true;
        if (it_x != l_Adj.end()) {
            list<int> a = it_x->second;
            for (auto iter = a.begin(); iter != a.end(); iter++)
                if (*iter == y) {
                    fl = false;
                    break;
                }
        }
        if (orient) {
            if (fl) {
                l_Adj[x].push_back(y);
                if (l_Adj.find(y) == l_Adj.end()) {
                    l_Adj[y].push_back(0);
                    auto it = l_Adj.find(y);
                    it->second.erase(it->second.begin());
                }
            }
        }
        else if (fl) {
            l_Adj[x].push_back(y);
            l_Adj[y].push_back(x);
        }
    }
    return l_Adj;
}
void output(map<int, list<int>> gr) { //функция вывода
    for (auto it = gr.begin(); it != gr.end(); it++) {
        cout << "point " << it->first << ": ";
        list<int> a = it->second;
        for (auto iter = a.begin(); iter != a.end(); iter++)
            cout << *iter << " ";
        cout << endl;
    }
}

int main() {
    cout << "A and B: ";
    int a, b;
    cin >> a >> b;
    map<int, list<int>> gr = MakeGr(0);
    gr[a].remove(b); //просто удаляем путь из a в b 
    gr[b].remove(a); //и путь из b в a 
    cout << "Done: " << endl;
    output(gr);
    return 0;
}