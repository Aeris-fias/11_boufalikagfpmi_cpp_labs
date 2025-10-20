#include <iostream>
#include <random>
//функция выделения памяти и создания матрицы
void allocate_matrix(int**& matrix, int n) {
    matrix = new int* [n];

    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
}
//функция удаления динамической матрицы
void deleteMatrix(int** matrix, int n) {
    if (matrix == nullptr) {
        std::cout << "Pointer is NULL!\n";
        std::exit(1);
    }

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
// вывод матрицы
void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
// функция ручного ввода матрицы
void hand(int** matrix, int n) {
    std::cout << "Enter the elements of matrix: ";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!(std::cin >> matrix[i][j])) {
                std::cout << "Incorrect input! Elements must be integer!\n";

                deleteMatrix(matrix, n);
                std::exit(1);
            }
        }
    }
}

// функция заполнения матрицы рандомными числами
void random(int** matrix, int n) {
    int lower_limit, upper_limit;

    std::cout << "Enter the range of random: ";

    if (!(std::cin >> lower_limit >> upper_limit) || lower_limit > upper_limit) {
        std::cout << "Incorrect input! 1st integer must be lower than 2nd.\n";

        deleteMatrix(matrix, n);
        std::exit(1);
    }

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(lower_limit, upper_limit);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = distrib(gen);
        }
    }
}
// функция нахождения макс элемента в правом нижнем треугольнике
int findMaxInLowerRightTriangle(int** matrix, int n) {
    int maxElement = matrix[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j >= n - 1) {
                if (matrix[i][j] > maxElement) {
                    maxElement = matrix[i][j];
                }
            }
        }
        return maxElement;
    }
}
    //  Функция для поиска максимального положительного элемента и его позиции
    void findMaxPositiveElement(int** matrix, int n, int* maxRow, int* maxCol, int* maxValue) {
        *maxValue = -1;
        *maxRow = -1;
        *maxCol = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] > 0) {
                    if (*maxValue == -1 || matrix[i][j] > *maxValue) {
                        *maxValue = matrix[i][j];
                        *maxRow = i;
                        *maxCol = j;
                    }
                }
            }
        }
    }
// Функция для перестановки строк
void swapRows(int** matrix, int n, int row1, int row2) {
    for (int j = 0; j < n; j++) {
        int temp = matrix[row1][j];
        matrix[row1][j] = matrix[row2][j];
        matrix[row2][j] = temp;
    }
}
// Функция для перестановки столбцов
void swapColumns(int** matrix, int n, int col1, int col2) {
    for (int i = 0; i < n; i++) {
        int temp = matrix[i][col1];
        matrix[i][col1] = matrix[i][col2];
        matrix[i][col2] = temp;
    }
}
// Функция для перестановки строк и столбцов так, чтобы максимальный положительный элемент был в левом верхнем углу
void rearrangeMatrix(int** matrix, int n) {
    int maxRow, maxCol, maxValue;
    findMaxPositiveElement(matrix, n, &maxRow, &maxCol, &maxValue);
    if (maxValue == -1) {
        std::cout << "No positive elements found in the matrix!" << std::endl;
        return;
    }
    std::cout << "Maximum positive element: " << maxValue
        << " at position [" << maxRow << "][" << maxCol << "]" << std::endl;
    //  Переставляем строку с максимальным элементом на первую позицию
        if (maxRow != 0) {
        swapRows(matrix, n, 0, maxRow);
        std::cout << "Swapped rows 0 and " << maxRow << std::endl;
    }

    //  Переставляем столбец с максимальным элементом на первую позицию
    if (maxCol != 0) {
        swapColumns(matrix, n, 0, maxCol);
        std::cout << "Swapped columns 0 and " << maxCol << std::endl;
    }
}

int main() {
    int n;
    char option;

    int** matrix = nullptr;

    std::cout << "Enter the num of rows and columns: ";
    if (!(std::cin >> n) || n <= 0) {
        std::cout << "Incorrect value! Must be integer > 0!\n";
        std::exit(1);
    }
    allocate_matrix(matrix, n);

    std::cout << "Choose Hand Input or Random Input (h/r): ";
    std::cin >> option;

    std::cin.ignore();
     
    switch (option) {
    case 'h':
        hand(matrix, n);
        break;
    case 'r':
        random(matrix, n);
        break;
    default:
        std::cout << "Incorrect option input!\n";

        deleteMatrix(matrix, n);
        std::exit(1);

    }
    
    std::cout << "\nOriginal matrix:" << std::endl;
    printMatrix(matrix, n);

    int maxTriangle = findMaxInLowerRightTriangle(matrix, n);
    std::cout << "\n1) Maximum element of lower right triangle: "
        << maxTriangle << std::endl;

    std::cout << "\n2) Rearranging rows and columns:" << std::endl;
    rearrangeMatrix(matrix, n);

    std::cout << "\nResulting matrix:" << std::endl;
    printMatrix(matrix, n);
    deleteMatrix(matrix, n);
    return 0;
}