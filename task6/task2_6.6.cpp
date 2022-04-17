#include <iostream>
using namespace std;

struct list {
	int inf;
	list* next;
	list* prev;
};

void push(list*& h, list*& t, int x) { // заполнение списка
	list* r = new list;
	r->inf = x;
	r->next = NULL;
	if (!h && !t) {
		r->prev = NULL;
		h = r;
	}
	else {
		t->next = r;
		r->prev = t;
	}
	t = r;
}

void print(list*& h, list*& t) { // вывод
	list* p = h;
	while (p) {
		cout << p->inf << ' ';
		p = p->next;
	}
	cout<<  endl;
}

void delNode(list*& h, list*& t, list* r) {//удаляем элемент
	if (r == h && r == t) {
		h = t = NULL;
	}
	else if (r == h) {
		h = h->next;
		h->prev = NULL;
	}
	else if (r == t) {
		t = t->prev;
		t->next = NULL;
	}
	else {
		r->next->prev = r->prev;
		r->prev->next = r->next;
	}
	delete r;
}


void chotNechot(list*& h, list*& t) {
	list* h1 = NULL;
	list* t1 = NULL;
	list* h2 = NULL;
	list* t2 = NULL;
	while (h) {
		if (h->inf % 2 == 0) { // заполняем первый вспом. список
			push(h2, t2, h->inf);
		}
		else {
			push(h1, t1, h->inf); // заполняем второй вспом. список
		}
		h = h->next;
	}
	h = h2; // мёрджим списки
	t2->next = h1;
	h1->prev = t2;
	t = t1;
}

int main() {
	int n;
	cout << "n = "; cin >> n; //кол-во элементов
	list* h = NULL;
	list* t = NULL;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		push(h, t, x);
	}
	chotNechot(h, t);
	print(h, t);
}
