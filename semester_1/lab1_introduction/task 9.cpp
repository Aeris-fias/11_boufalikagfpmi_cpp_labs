#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "������� ������������� n:" << endl;
	cin >> n;
	if (n / 1000 == n % 10 &&
		(n / 100) % 10 == (n / 10) % 10) {
		cout << n << "- ��������� " << endl;
	}
	else {
		cout << n << " -�� ���������" << endl;

	}
	return 0;
}