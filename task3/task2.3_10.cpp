#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct date {
	int dd, mm, yy;
};

struct people {
	string surname;
	string work;
	date dateOfBirth;
	int exp;
	int money;
};

date strDate(string s) {
	date x;
	string t = s.substr(0, 2);
	x.dd = atoi(t.c_str());
	t = s.substr(3, 2);
	x.mm = atoi(t.c_str());
	t = s.substr(6, 4);
	x.yy = atoi(t.c_str());
	return x;
}

ifstream in("workmans.txt"); // ����� �����
ofstream out("workmansSort.txt"); // ����� ������

vector <people> read() {
	vector <people> p;
	people n;
	while (in.peek() != EOF) {
		in >> n.surname;
		in >> n.work;
		string d;
		in >> d;
		n.dateOfBirth = strDate(d);
		in >> n.exp;
		in >> n.money;
		p.push_back(n);
	}
	return p;
}

void print(people x) {						// ����� � ����
	out << setw(20) << left << x.surname;	// �� ������ ���� 15 ������� �� ������� 
	out << setw(35) << left << x.work;		// 27 ������� �� ���������
	if (x.dateOfBirth.dd < 10)				// ��������� ����� ���� ����� �����, ���� ��� ������ 10
		out << '0' << x.dateOfBirth.dd << '.';
	else out << left << x.dateOfBirth.dd << '.';
	if (x.dateOfBirth.mm < 10)
		out << '0' << x.dateOfBirth.mm << '.';
	else out << x.dateOfBirth.mm << '.';
	out << left << setw(5) << x.dateOfBirth.yy;	// ��� �� ��������� ����������� ���-�� ������� �� ����-���
	out << left << setw(5) << x.exp;
	out << left << setw(5) << x.money << endl;
}

bool operator < (people a, people b) {//�������������� �������� < � ����������� � ��������
		if (a.work < b.work) return true;
		if (a.work == b.work && a.money < b.money) return true;
		return false;
	}

void gnomeSort(vector <people>& x) {

	int i = 1, n = x.size();
	while (i < n)
	{
		if (i == 0) i++;

		if (x[i - 1] < x[i]) i++;

		else
		{
			swap(x[i - 1], x[i]);
			i--;
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	people n;
	vector <people> p;
	p = read();
	gnomeSort(p); // ����� �-��
	for (int i = 0; i < p.size(); i++) // ������ � ����
		print(p[i]);
	out.close();
	in.close();
	return 0;
}