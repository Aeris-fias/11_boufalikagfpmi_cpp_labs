
// solve task with usage of
// static arrays
#include <iostream>
#include <random>

const int MAX_SIZE = 100;
void random(int* random_arr, int size) {
	int lower_limit, upper_limit;

	std::cout << "Enter the range of random: ";

	if (!(std::cin >> lower_limit >> upper_limit) || lower_limit > upper_limit) {
		std::cout << "Incorrect input!\n";
		std::exit(1);
	}

	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> distrib(lower_limit, upper_limit);

	for (int i = 0; i < size; i++) {
		random_arr[i] = distrib(gen);
	}
}

void hand(int *hand_arr, int size) {

	std::cout << "Enter the elements of array: ";

	for (int i = 0; i < size; i++) {
		if (!(std::cin >> hand_arr[i])) {
			std::cout << "Incorrect Input!\n";
			std::exit(1);
		}
	}

}
int min() {
	int arr[MAX_SIZE];
	int n;
	char option;
	   
	std::cout << "enter number of elements not more than " << MAX_SIZE << ":";
	if (!(std::cin >> n) || n <= 0 || n > MAX_SIZE) {
		std::cout << "error. incorrect input!" << std::endl;
		std::exit(1);
	}
	std::cout << "Choose Hand Input or Random Input (h/r): ";
	std::cin >> option;
	switch (option) {
	case 'h':
		hand(arr, n);
		break;
	case 'r':
		random(arr, n);
		break;
	default:
		std::cout << "Incorrect option input!\n";
		std::exit(1);
	}
	std::cout << " \nOriginal array: "  ;
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " " ;
	}
	std::cout << std::endl;

	int changes = 0;
	for (int i = 1; i < n; i++) {
		if ((arr[i - 1] >= 0 && arr[i] < 0) || (arr[i - 1] < 0 && arr[i] >= 0)) {
			changes++;
		}
	}
	std::cout << " Sign changes:  " << changes << std::endl;
	int zero1 = -1, zero2 = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			if (zero1 == -1) {
				zero1 = i;
			}
			else if (zero2 == -1) {
				zero2 = i;
				break;
			}
		}
	}
	if (zero2 == -1) {
		std::cout << " Less than two zeros! " << std::endl;
	}
	else {
		int prod = 1;
		for (int i = zero1 + 1; i < zero2; i++) {
			prod *= arr[i];
		}
		std::cout << " Productodd between two zeros:  " << prod << std::endl;
	}
	int temp[MAX_SIZE];
	int evenIndex;
	for (int i = 0; i < n; i++) {	
		if (arr[i] % 2 ==0) {
			temp[evenIndex++] = arr[i];
        }
    }
			for (int i = 0; i < n; i++) {
				if (arr[i] % 2 !=0) {
			 temp[evenIndex++] = arr[i];
        }
    }
		for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }	
		
	std::cout << " \nConverted array:  ";
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
