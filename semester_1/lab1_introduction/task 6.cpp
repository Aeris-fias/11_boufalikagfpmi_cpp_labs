/* #include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "write n:" << endl;
	cin >> n;
	if (n <= 0) {
		cout << "Ошибка: число должно быть натуральным (n > 0)" << endl;
	}
	int sum = 0;
	int productOdd = 1;
	for (int i = 0; i < n; i++) {
		sum += productOdd;
		productOdd += 2;
	}
	cout << " сумма первых  " <<  n  << " нечётных чисел равна " <<  sum  << endl;
	return 0;
}
*/