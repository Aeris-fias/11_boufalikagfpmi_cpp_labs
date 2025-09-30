
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

    std::uniform_int_distribution<> distrib(lower_limit, upper_limit);

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
int findMaxAbsIndex(double* arr, int n) {
    int maxIndex = 0;
    double maxAbs = fabs(arr[0]);

    for (int i = 1; i < n; i++) {
        if (fabs(arr[i]) > maxAbs) {
            maxAbs = fabs(arr[i]);
            maxIndex = i;
        }
    }
    return maxIndex;
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

    // Если положительный элемент не найден или он последний
    if (firstPositiveIndex == -1 || firstPositiveIndex == n - 1) {
        return 0;
    }

    // Считаем сумму элементов после первого положительного
    double sum = 0;
    for (int i = firstPositiveIndex + 1; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

// Преобразование массива
void transformArray(double* arr, int n) {
    // Создаем временный массив для результата
    double* temp = new double[n];
    int index = 0;

    // Сначала добавляем элементы с целой частью в [0;10]
    for (int i = 0; i < n; i++) {
        int intPart = static_cast<int>(arr[i]);
        if (intPart >= 0 && intPart <= 10) {
            temp[index++] = arr[i];
        }
    }

    // Затем добавляем все остальные элементы
    for (int i = 0; i < n; i++) {
        int intPart = static_cast<int>(arr[i]);
        if (intPart < 0 || intPart > 10) {
            temp[index++] = arr[i];
        }
    }

    // Копируем результат обратно в исходный массив
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    delete[] temp;
}

int main() {
    int n;
    int choice;
    char option;

    std::cout << "Enter the array size: ";
    std::cin >> n;

    // Проверка корректности размера массива
    if (n <= 0) {
        std::cout << " The array size must be positive! " << std::endl;
        return 1;
    }

    // Создание динамического массива
    double* arr = new double[n];

    // Выбор способа заполнения
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
 
       
    

    // Вывод исходного массива
    std::cout << "\nOriginal array:" << std::endl;
    printArray(arr, n);

    // Номер максимального по модулю элемента
    int maxAbsIndex = findMaxAbsIndex(arr, n);
    std::cout << "The number of the maximum element by module: " << maxAbsIndex << std::endl;
    std::cout << "   Meaning: " << arr[maxAbsIndex] << ", absolute: " << fabs(arr[maxAbsIndex]) << std::endl;

    // Сумма элементов после первого положительного
    double sum = sumAfterFirstPositive(arr, n);
    std::cout << "Sum after the first positive number: " << sum << std::endl;

    // Преобразование массива
    transformArray(arr, n);
    std::cout << "\nConverted array:" << std::endl;
    printArray(arr, n);
    delete[] arr;

    return 0;
}