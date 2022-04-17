#include <iostream>
#include <string>

using namespace std;

struct stack { // объ€вление строкового стека
	string inf;
	stack* next;
};

void push(stack*& h, string x) { // заполн€ем стек (первый элемент будет в самом "низу" стека
	stack* r = new stack;
	r->inf = x;
	r->next = h;
	h = r;
}

string pop(stack*& h) { // удал€ем элемент "сверху"
	string i = h->inf;
	stack* r = h;
	h = h->next;
	delete r;
	return i;
}

void reverse(stack*& h) { // переворачиваем стек
	stack* h1 = NULL;
	while (h)
		push(h1, pop(h));
	h = h1;
}

stack* result(stack*& h, char c) { // функци€ дл€ заполнени€ вспомогательного стека элементами, которые не заканчиваютс€ на указанный символ
	stack* res = NULL;
	while (h) {
		string a = pop(h);
		if (a[a.length() - 1] != c)
			push(res, a);
	}
	reverse(res);
	return res;
}

void output(stack* h) { // вывод стека
	while (h)
		cout << pop(h) << ' ';
}
	
int main() {
	int n; 
	cout << "n= ";  cin >> n;
	stack* h = NULL;
	char c;
	cout << "char = ";  cin >> c;
	string x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		push(h, x);
	}
	reverse(h);
	stack* k = result(h, c);
	output(k);
}