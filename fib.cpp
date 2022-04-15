#include <iostream>
using namespace std;

void fib(int n){
        int a = 0; int b = 1;
        for (int i = 0; i < n; i++){
                cout << a << endl;
                int c = b;
                b = a + b;
                a = c;
        }
}

int main() {
        cout<< "Hello World!"<< endl;
        fib(10);
}
