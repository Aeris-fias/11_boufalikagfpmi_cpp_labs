/**#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");

	int n, m;
	cout << "������� 2 ����������� ����� n � m: " << endl;
	cin >> n >> m;
	if (n <= 0 and m <= 0) {
		cout << "������, ����� ������ ���� ������������" << endl;
	}
	
	cout << "����� ��������: " << n << " and " << m << endl;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0 && m % i == 0) {
			cout << i << " ";
		}
	}
	cout << endl;

	return 0;
}
*/