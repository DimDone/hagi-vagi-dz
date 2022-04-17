#include<iostream>

using namespace std;

struct queue {
	int inf;
	queue* next;
};

void push(queue*& h, queue*& t, int x) { // заполняем очередь
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

int pop(queue*& h, queue*& t) { // удаляем элемент из хвоста
	queue* r = h;
	int i = h->inf;
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
	queue* resh = NULL; // вспомогательные очереди
	queue* rest = NULL;
	queue* ph = NULL;
	queue* pt = NULL;
	while (h) {
		int c = pop(h, t);

		if (c > 0)
			push(ph, pt, c);
		else
			push(resh, rest, c);
	}
	while (ph)
		push(resh, rest, pop(ph, pt));
	output(resh, rest);
}

int main() {
	int n;
	cout << "n = "; cin >> n;
	queue* h = NULL;
	queue* t = NULL;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		push(h, t, x);
	}
	result(h, t);
}