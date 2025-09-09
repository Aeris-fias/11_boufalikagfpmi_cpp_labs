 #include <iostream>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	std::cout << "write n:" << std::endl;
	std::cin >> n;
	if (n <= 0) {
		std::cout << "error, n must be > 0" << std::endl;
	}
	int sum = 0;
	int productOdd = 1;
	for (int i = 0; i < n; i++) {
		sum += productOdd;
		productOdd += 2;
	}
	std::cout << " sum of the first   " <<  n  << " odd numbers is equal to " <<  sum  << std::endl;
	return 0;
}
