#include <iostream>
#include <map>
#include <list>
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

void DFS(map<int, list<int>> gr, int v, bool*& visited) { //обход в глубину
    visited[v] = true;
    for (auto it = gr.begin(); it != gr.end(); it++) {
        if (it->first == v) {
            list<int> a = it->second;
            for (auto iter = a.begin(); iter != a.end(); iter++)
                if (!visited[*iter]) DFS(gr, *iter, visited);
            break;
        }
    }
}

int main() {
    map<int, list<int>> grr = MakeGr(1);
    int p;
    cout << "point: ";
    cin >> p;
    bool* visited = new bool[grr.size()];
    for (int i = 0; i < grr.size(); i++)
        visited[i] = false;
    DFS(grr, p, visited);
    for (int i = 0; i < grr.size(); i++)
        if (visited[i] == false)
            cout << i << " ";
    return 0;
}