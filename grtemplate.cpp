#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <fstream>

using namespace std;

ifstream in("data2.txt");

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

vector<int> BFS(map<int, list<int>> gr, int v, bool*& visited) { //обход в глубину
    visited[v] = true;
    queue<int> q;
    q.push(v);
    vector<int> path;
    path.push_back(v);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto it = gr.begin(); it != gr.end(); it++) {
            if (it->first == u) {
                list<int> a = it->second;
                for (auto iter = a.begin(); iter != a.end(); iter++)
                    if (!visited[*iter]) {
                        visited[*iter] = true;
                        path.push_back(*iter);
                        q.push(*iter);
                    }
                break;
            }
        }
    }
    return path;
}

int main() {
    map<int, list<int>> grr = MakeGr(1);
    bool *visited = new bool[grr.size()];
    for (int i = 0; i < grr.size(); i++)
        visited[i] = false;
    for (auto it = grr.begin(); it != grr.end(); it++) {
        vector<int> path = BFS(grr, it->first, visited);
        bool f = true; //флаг истока
        for (int i = 0; i < grr.size(); i++) {
            if (visited[i] == false) {
                f = false; //если хотя бы 1 точка осталась непосещенной после обхода в ширину, то основная точка - не исток
                break; //ОпТиМИзаЦиЯ
            }
        }
        if (f) { //если все посещены, то говорим, что точка - исток и выводим результат обхода
            cout << "point " << it->first << " is source: ";
            for (vector<int>::iterator it1 = path.begin(); it1 != path.end(); it1++)
                cout << *it1 << " ";
            cout << endl;
        }
        for (int i = 0; i < grr.size(); i++) visited[i] = false;//опускаем все флаги, для инициализации следующей вершины
    }
    return 0;
}