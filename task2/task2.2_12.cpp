#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	multiset <string> ch; set <string> b;
	string s = "� � �� �� 12 ��� �� ��� � �� 6 ��� �� ����.";
	string n = "0123456789";
	string::size_type pos = 0, k;
	k = s.find_first_of(" .");
	while (k != string::npos) {
		ch.insert(s.substr(pos, k - pos)); // ���������� ���������� ������� �� ������
		pos = k + 1;
		k = s.find_first_of(" .", pos);
	}
	for (multiset <string>::iterator it = ch.begin(); it != ch.end(); it++) {
		string c = *it;
		if (c.find_first_not_of(n) == string::npos) // ��������, �������� �� ������� ���������� ������
			b.insert(*it);
	}
	for (set <string>::iterator it = b.begin(); it != b.end(); it++)
		while (ch.find(*it) != ch.end()) { // ���� ��������� �����, ������� ��
			ch.erase(ch.find(*it));
		}
	for (multiset <string>::iterator it = ch.begin(); it != ch.end(); it++) // ����� ����������
		cout << *it << endl;
	cout << "���������� ����, �� ���������� ������: " << ch.size();
}