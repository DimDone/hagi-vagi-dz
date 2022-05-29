#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <cmath>

using namespace std;

ifstream in("workers.txt");

const int m = 16;

int hashFuction(float x){
    x *= 0.618034;
    float z;
    return modf(x, &z) * m;
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
        if (n[k].size() == 0)
            n[k].push_back(s);
        else{
            k++;
            n[k].push_back(s);
        }
    }
    return n;
}

void outputTable(vector <list <string>> n){
    for(vector <list<string>>:: iterator it = n.begin(); it != n.end(); it++){
         list<string> a = *it;
         for(list<string>::iterator iter = a.begin(); iter != a.end(); iter++)
            cout << *iter;
         if (a.size() == 0)
            cout << "NULL" << endl;
         else cout << endl;
         }
}
int main() {
    vector <list <string>> n = createTeble();
    outputTable(n);
}