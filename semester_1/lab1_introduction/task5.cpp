#include <iostream>

int main()
{
	

	int n, m;
	std::cout << "input 2 integers n и m: " << std::endl;
	
	if (!(std::cin>>n>>m)) {
        std::cout << "error, incorrect n and m)" << std::endl;
        std::exit(1);
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
