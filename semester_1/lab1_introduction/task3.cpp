#include <iostream>
#include <cmath>

int main()
{	
	

	int n;
	std::cout << "enter n: "<< std::endl;
	if (!(std::cin>>n)) {
        std::cout << "error, incorrect n)" << std::endl;
        std::exit(1);
	int s = 0;
	for (int i = 1; i <= n; i++) {
		s += pow(i, i);
	}
	std::cout << "sum= 1^1+2^2+...+" << n << " ^" << n << "=" << s;	
	
	return 0;
}

//  при больших n результат получается очень большим, тип данных int не может содержать такие большие числа. Вероятно нужно использовать другие типы данных (double, long, long double,long long)