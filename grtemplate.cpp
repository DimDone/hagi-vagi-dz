#include <iostream>

#include <map>

#include <list>

#include <fstream>

using namespace std;


map<int, list<int>> MakeGr(bool orient){ //создание списка смежности графа

    map<int, list<int>> gr;

    int x, y; // x<->y or x->y

    while (in.peek() != EOF) {

        in >> x >> y;

        auto it_x = gr.find(x);

        bool fl = true;

        if (it_x != gr.end())

        {

            list<int> a = it_x->second;

            for (auto iter = a.begin(); iter != a.end(); iter++)

                if (*iter == y)

                {

                    fl = false;

                    break;

                }

        }

        if (orient)

        {

            if (fl)

            {

                gr[x].push_back(y);

                if (gr.find(y) == gr.end())

                {

                    gr[y].push_back(0);

                    auto it = gr.find(y);

                    it->second.erase(it->second.begin());

                }

            }

        }

        else if (fl)

        {

            gr[x].push_back(y);

            gr[y].push_back(x);

        }

    }

    return gr;

}