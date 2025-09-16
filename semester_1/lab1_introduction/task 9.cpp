#include <iostream>

int main()
{
	
	int n;
	std::cout << "input four-digit n:" << std::endl;
	std::cin >> n;
	if (n / 1000 == n % 10 &&
		(n / 100) % 10 == (n / 10) % 10) {
		std::cout << n << "- palindrom " << std::endl;
	}
	else {
		std::cout << n << " - no palindrom" << std::endl;

	}
	return 0;
}