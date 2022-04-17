#include<iostream>

using namespace std;

struct queue {
	string inf;
	queue* next;
};

void push(queue*& h, queue*& t, string x) { // заполняем очередь
	queue* r = new queue;
	r->inf = x;
	r->next = NULL;
	if (!h && !t) {
		h = t = r;
	}
	else {
		t->next = r;
		t = r;
	}
}

string pop(queue*& h, queue*& t) { // удаляем элемент из хвоста
	queue* r = h;
	string i = h->inf;
	h = h->next;
	if (!h)
		t = NULL;
	delete r;
	return i;
}

void output(queue* h, queue* t) { // вывод очереди
	while (h)
		cout << pop(h, t) << ' ';
}

void result(queue*& h, queue*& t) {
	queue* resh = NULL;
	queue* rest = NULL;
	if (h == t) return;
	else {
		queue* h1 = NULL;
		queue* t1 = NULL;
		string a = pop(h, t);
		push(resh, rest, a);
		while (h) {
			string b = pop(h, t);
			if (b != a) push(h1, t1, b); // если слова совпадают
		}
		result(h1, t1);
	}
	output(resh, rest);
}

int main() {
	int n;
	cout << "n = "; cin >> n;
	queue* h = NULL;
	queue* t = NULL;
	for (int i = 0; i < n; i++) {
		string x; cin >> x;
		push(h, t, x);
	}
	result(h, t);;
}