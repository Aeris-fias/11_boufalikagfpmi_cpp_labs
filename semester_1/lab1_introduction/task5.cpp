#include <iostream>

int main()
{
	setlocale(LC_ALL, "Rus");

	int n, m;
	std::cout << "input 2 integers n и m: " << std::endl;
	std::cin >> n >> m;
	if (n <= 0 && m <= 0) {
		std::cout << "error" << std::endl;
	}
	
	std::cout << "common factors: " << n << " and " << m << std::endl;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0 && m % i == 0) {
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;

	return 0;
}
