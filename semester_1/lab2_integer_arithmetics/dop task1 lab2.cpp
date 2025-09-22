#include <iostream>
void TryRead(int& number) {
	if (!(std::cin >> number)) {
		std::cout << "failing on reading the number." << std::endl;
		exit(0);
	}
}
bool IsNotNegative(int number) {
	return abs(number) == number;
}
int main() {
	int number;
	std::cout << "enter the number:";
	TryRead(number);

	bool std_non_negative_check = (number >= 0);

	if (IsNotNegative(number) == std_non_negative_check) {
		std::cout << "try again..." << std::endl;
	}
	else {
		std::cout << "shit, you broke my programm :(" << std::endl;
		exit(1);
	}
	return 0;
}

//enter min number limit int(-2147483648)