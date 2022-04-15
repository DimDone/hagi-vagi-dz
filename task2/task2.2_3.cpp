#include <iostream>
#include <set>

using namespace std;

int main(){
	int x; set <int> s; set <int> s1;
	int n; cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x;
		if ((abs(x) >= 10 && abs(x) <= 99) || (abs(x) >= 100 && abs(x) <= 999)) { // заполняем вспомогательный контейнер цифрами, которые есть в двузначных и трехзначных числах
			while (x != 0){
				s.insert(abs(x % 10));
				x = x / 10;
			}
		}
		else{
			while (x != 0){ // заполняем контейнер цифрами не двузначных и не трехзначных чисел
				s1.insert(abs(x % 10));
				x = x / 10;
			}
		}
	}
	for (set<int>::iterator it = s.begin(); it != s.end(); it++){
		if (s1.find(*it) != s1.end()) // если в контейнере встретилась цифра из вспомогательного контейнера, то она удаляется
			s1.erase(s1.find(*it));
	}
	if (s1.empty())
		cout << "no" << endl;
	else{
		for(set <int>::iterator it = s1.begin(); it != s1.end(); it++) //вывод
		cout << *it << ' ';
		}
}
