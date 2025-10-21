#include <iostream>

void allocateMatrix(int**& matrix, int m, int n) {
    matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[m];
	}
}
void deleteMatrix(int** matrix, int rows) {
    if (matrix == nullptr) {
        std::cout << "Pointer is NULL!\n";
        std::exit(1);
    }

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
void Bubble_Sort(int* array, int rows, int cols){
    int size = rows * cols;
    int* array = new int[size];
	for (int i = 0; i < size-1; i++) {
		for (int j = i - 1; j < size-i-1; j++) {
			if (abs(array[j]) < abs(array[j+1])) {
                std::swap(array[j], array[j+1]);
			}
		}
	}
    delete[] array;     
}
void insertSort(int* arr, int rows, int cols) {
    int size = rows * cols;
    int* array = new int[size];

	for (int i = 1; i < size; i++) {
		int x = arr[i];
		int j = i - 1;
			while (j >= 0 && abs(array[j]) > abs(x)) {
				arr[j + 1] = arr[j];
				j--;
			}
		arr[j + 1] = x;
	}
}
void merge(int* a, int left, int mid, int right, int* temp)
{
    int i = left;
    int j = mid;
    int k = left;

    while (i < mid && j < right)
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }
    while (i < mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    while (j < right)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    for (int t = left; t < right; t++)
        a[t] = temp[t];

}
void mergeSort(int* a, int left, int right, int* temp)
{
    if (right - left <= 1) return;

    int mid = (left + right) / 2;
    mergeSort(a, left, mid, temp);
    mergeSort(a, mid, right, temp);

    merge(a, left, mid, right, temp);
}
void quickSort(int *arr,int left, int right){
if (left >= right) return;

int pivot = arr[(left + right) / 2];
int i = left;
int j = right;

while (i <= j) {
    while (arr[i] < pivot) i++;
    while (arr[j] > pivot) j--;

    if (i <= j) {
        std::swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

quickSort(arr, left, j);
quickSort(arr, i, right);
}
void sort_count(int* array, int rows, int cols) {
    int size = rows * cols;
    int* result = new int[size];
    int* count = new int[size];
    int i, j;
    for (i = 0; i < size; i++)
        count[i] = 0;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (array[i] < array[j]) {
                count[j]++;
            }
            else{
                count[i]++;
        }
    }
    for (i = 0; i < size; i++){
        result[count[i]] = array[i];
}


void print_array(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows, i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << array[i]<< " "<<;
        }
    }
	std::cout << std::endl;
}
void random(int** matrix, int rows,int cols) {
    int lower_limit, upper_limit;

    std::cout << "Enter the range of random: ";

    if (!(std::cin >> lower_limit >> upper_limit) || lower_limit > upper_limit) {
        std::cout << "Incorrect input! 1st integer must be lower than 2nd.\n";

        deleteMatrix(matrix, rows);
        std::exit(1);
    }

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(lower_limit, upper_limit);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = distrib(gen);
        }
    }
}

int main() {
    int rows = 0; int cols = 0;

    int** matrix = nullptr;

    std::cout << "Enter the num of rows and columns: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cout << "Incorrect value! Must be integer > 0!\n";
        std::exit(1);
    }
    allocateMatrix(matrix, rows, cols);
    random(matrix, rows, cols);
    std::cout << " before sort: " << std::endl;
    print_array(matrix, rows, cols);
    char option; 
    std::cout << "Choose kind of sort (b/q/c/i/m): ";
    std::cin >> option;

    std::cin.ignore();
    switch (option) {
        case'b':
            Bubble_Sort(matrix, rows, cols);
            break;
        case'q':
            quickSort(matrix, rows, cols);
        case'c':
            sort_count(matrix, rows, cols);
            break;
        case 'i':
            insertSort(matrix, rows, cols);
            break;
        case 'm':
            mergeSort(matrix, rows, cols);
            break;
        default:
            std::cout << "Incorrect option input!\n";

            deleteMatrix(matrix, rows);
            std::exit(1);

    }