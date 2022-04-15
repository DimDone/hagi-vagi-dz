#include <iostream>
#include <vector>

using namespace std;

int fib(int n) {
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    int a = 0;
    int b = 1;
    for (int i = 0; i < n - 1; ++i) {
        int t = a;
        a = b;
        b = b + t;
    }

    return a;
}

void bubbleSort(vector<int>& x) {
    for (int i = 0; i < x.size() - 1; ++i) {
        bool f = false;
        for (int j = 0; j < x.size() - 1 - i; ++j)
            if (x[j] > x[j + 1]) {
                swap(x[j], x[j + 1]);
                f = true;
            }
        if (!f)
            break;
    }
}

int main()
{
    cout << "Hello, world!" << endl;
    cout << fib(10) << endl;
    vector<int> x = { 6, 2, 1, 4, 5, 6, 9, 12, 3, 1};
    for (vector<int>::iterator it = x.begin(); it != x.end(); it++)
	cout << *it << " ";
    cout << endl;
    bubbleSort(x);
    for (vector<int>::iterator it = x.begin(); it != x.end(); it++)
	cout << *it << " ";
    cout << endl;
}
