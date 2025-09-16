 #include <iostream>

int main()
{
	
	int n;
	std::cout << "write n:" << std::endl;
	std::cin >> n;
	if (!(std::cin>>n)) {
        std::cout << "error, incorrect n)" << std::endl;
		std::exit(1);
	}
	int sum = 0;
	int pr = 1;
	for (int i = 0; i < n; i++) {
		sum += pr;
		pr += 2;
	}
	std::cout << " sum of the first   " <<  n  << " odd numbers is equal to " <<  sum  << std::endl;
	return 0;
}
