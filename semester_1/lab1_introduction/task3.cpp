/**#include <iostream>
#include <cmath>
using namespace std;
int main()
{	
	setlocale(LC_ALL, "Rus");

	int n;
	cout << "������� n: "<< endl;
	cin >> n;
	int s = 0;
	for (int i = 1; i <= n; i++) {
		s += pow(i, i);
	}
	cout << "sum= 1^1+2^2+...+" << n << " ^" << n << "=" << s;	
	
	return 0;
}
*/
// ��� ������� n ��������� ���������� ����� �������, ��� ������ int �� ����� ��������� ����� ������� �����. �������� ����� ������������ ������ ���� ������ (double, long, long double, long long)