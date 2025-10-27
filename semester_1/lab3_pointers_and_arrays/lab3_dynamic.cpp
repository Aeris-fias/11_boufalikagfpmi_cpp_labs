
// solve task with usage of
// dymanic arrays
#include <iostream>
#include <random>
#include <cmath>

// Функция для ручного ввода массива
void hand(double* hand_arr, int size) {

    std::cout << "Enter the elements of array: ";

    for (int i = 0; i < size; i++) {
        if (!(std::cin >> hand_arr[i])) {
            std::cout << "Incorrect Input!\n";
            std::exit(1);
        }
    }
}

// Функция для заполнения массива случайными числами
void random(double* random_arr, int size){
    int lower_limit, upper_limit;
    std::cout << "Enter the range of random: ";

    if (!(std::cin >> lower_limit >> upper_limit) || lower_limit > upper_limit) {
        std::cout << "Incorrect input!\n";
        std::exit(1);
    }

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<> distrib(lower_limit, upper_limit);

    for (int i = 0; i < size; i++) {
        random_arr[i] = distrib(gen);
    }
}

// Функция для вывода массива
void printArray(double* arr, int n) {
    std::cout << "Array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Нахождение номера максимального по модулю элемента
int findMaxAbsNumber(double* arr, int n) {
    int maxNumber = 1;
    double maxAbs = fabs(arr[0]);

    for (int i = 1; i < n; i++) {
        if (fabs(arr[i]) > maxAbs) {
            maxAbs = fabs(arr[i]);
            maxNumber= i+1;
        }
    }
    return maxNumber;
}

// Сумма элементов после первого положительного элемента
double sumAfterFirstPositive(double* arr, int n) {
    int firstPositiveIndex = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            firstPositiveIndex = i;
            break;
        }
    }

    if (firstPositiveIndex == -1 || firstPositiveIndex == n - 1) {
        std::cout << "Warning! Edge case: the last positive is either on n-th position or there are not positives at all, so the sum is ";
    }

    double sum = 0;
    for (int i = firstPositiveIndex + 1; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Преобразование массива
void transformArray(double* arr, int n) {
    int writePos = 0;
    
    for (int readPos = 0; readPos < n; readPos++) {
        int intPart = static_cast<int>(arr[readPos]);
        if (intPart >= 0 && intPart <= 10) {
            if (readPos != writePos) {
                double temp = arr[readPos];
                for (int j = readPos; j > writePos; j--) {
                    arr[j] = arr[j - 1];
                }
                arr[writePos] = temp;
            }
            writePos++;
        }
    }
}

int main() {
    int n;
    int choice;
    char option;

    std::cout << "Enter the array size: ";
    if (!(std::cin >> n) || n <= 0) {
		std::cout << "error. incorrect input!" << std::endl;
		std::exit(1);
	}

    double* arr = new double[n];

    std::cout << "\nChoose Hand Input or Random Input (h/r):" << std::endl;
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
        delete[] arr;
        std::exit(1);
    }      
    std::cout << "\nOriginal array:" << std::endl;
    printArray(arr, n);
    int maxAbsIndex = findMaxAbsNumber(arr, n);
    std::cout << "The number of the maximum element by module: " << maxAbsIndex << std::endl;
    std::cout << "   Meaning: " << arr[maxAbsIndex] << ", absolute: " << fabs(arr[maxAbsIndex]) << std::endl;
    double sum = sumAfterFirstPositive(arr, n);
    std::cout << "Sum after the first positive number: " << sum << std::endl;
    transformArray(arr, n);
    std::cout << "\nConverted array:" << std::endl;
    printArray(arr, n);
    delete[] arr;
    return 0;
}