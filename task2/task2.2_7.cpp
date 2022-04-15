#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	string s = "Ехал Грека через реку? Ехал грека через реку. Видит грека в реке Рак! Сунул Грека Руку в реку? Рак за руку греку цап Цап?";
	string r = ".!?";
	multiset <string> c; set <string> p; multiset <string> v;
	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}
	while (s.length() != 0) {
		c.insert(s.substr(0, s.find_first_of(r) + 1)); // заполнение контейнера словами из строки
		s = s.substr(s.find_first_of(r) + 1, s.length() - s.find_first_of(r));
	}
	for (set <string>::iterator it = c.begin(); it != c.end(); it++) {
		string s1 = *it;
		if (s1[s1.length() - 1] == '.') {
			s1 = s1.replace(s1.length() - 1, s1.length() - 1, " ");
			while (s1.length() != 0) { // заполнение вспомогательного контейнера словами повествовательных предложений
				p.insert(s1.substr(0, s1.find_first_of(' ')));
				s1 = s1.substr(s1.find_first_of(' ') + 1, s1.length() - s1.find_first_of(' '));
			}
		}
		else {
			s1 = s1.replace(s1.length() - 1, s1.length() - 1, " ");
			while (s1.length() != 0) { // заполнение вспомогательного контейнера словами вопросительных и восклицательных предложений
				v.insert(s1.substr(0, s1.find_first_of(' ')));
				s1 = s1.substr(s1.find_first_of(' ') + 1, s1.length() - s1.find_first_of(' '));
			}
		}
			
	}
	for (set <string>::iterator it = p.begin(); it != p.end(); it++)
		while (v.find(*it) != v.end()) { // проверка на наличие слов из повествовательных предложений в вопросительных и восклицательных предложениях
			v.erase(v.find(*it));
	}
	p.clear();
	for (multiset <string>::iterator it = v.begin(); it != v.end(); it++)
		p.insert(*it);
	for (multiset <string>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
	cout << "Слов с повторениями: " << v.size() << endl << "Слов без повторений: " << p.size();
}