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
int main() {
    vector <list <string>> n = createTeble();
    outputTable(n);
}