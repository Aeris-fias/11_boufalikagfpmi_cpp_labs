#include <iostream>
#include <cmath>
void Bubble_Sort(int* array, int size)
for (i = 0; i < size; i++) {
	for (j = i - 1; j < size, j++) {
		if (abs(array[j]) < abs(array[i]) {
			std::swap(array[j];array[i])
		   }
		}
	}
}
void print_array(int *array, int size)
for (i = 0; i < size, i++) {
std::cout<<arrray[i];
}
std::cout<<std::endl;

int main()
const int max_length = 100;
int n;
int arr[max_length];
std::cout << " enter the length <100: " << std::endl;
if (!(std::cin >> n) || n < 0) {
	std::cout << "error! " << std::endl;
	std::exit(1);
}
std::cout << " enter the elements of array " << std::endl;
for (i = 0; i < n; i++) {
	if (!(std::cin >> array[i]))
		std::cout << " error " << std::endl;
}

