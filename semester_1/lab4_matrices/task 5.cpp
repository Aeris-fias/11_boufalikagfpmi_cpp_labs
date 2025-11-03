#include <iostream>
#include <random>
#include <exception>

//проверка целочисленных данных
int read_int() {
    int value;
    if (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore();
        throw std::invalid_argument("Expected integer value");
    }
    return value;
}

//проверка размера матрицы
int read_matrix_size() {
    int size = read_int();

    if (size <= 0) {
        throw std::out_of_range("Size must be > 0");
    }

    return size;
}

//функция выделения памяти и создания матрицы
void allocate_matrix(int**& matrix, int n) {
    matrix = new int* [n];

    for (size_t i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }
}

//функция удаления динамической матрицы
void delete_mat(int** matrix, int n) {
    if (matrix == nullptr) {
        return;
    }

    for (size_t i = 0; i < n; i++) {
        if (matrix[i] != nullptr) {
            delete[] matrix[i];
            matrix[i] = nullptr;
        }
    }
    delete[] matrix;
}

//функция ручного ввода элементов матрицы
void hand(int** matrix, int n) {
    if (matrix == nullptr) {
        throw std::invalid_argument("Null pointer passed to fill_manual");
    }
    std::cout << "Enter the elements of matrix: ";
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            matrix[i][j] = read_int();
        }
    }
}

//границы рандома
std::pair<int, int> read_random_limits() {

    std::cout << "Enter the range of random: ";
    int lower_limit = read_int();
    int upper_limit = read_int();

    if (lower_limit > upper_limit) {
        std::swap(lower_limit, upper_limit);
    }

    return { lower_limit, upper_limit };
}

//функция заполнения элементов матрицы рандомными числами
void random(int** matrix, int n) {
    if (matrix == nullptr) {
        throw std::invalid_argument("Null pointer passed to fill_random");
    }

    auto limits = read_random_limits();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(limits.first, limits.second);

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            matrix[i][j] = distrib(gen);
        }
    }
}

//выбор заполнения
void fill_matrix(char option, int** matrix, int n) {
    if (matrix == nullptr) {
        throw std::invalid_argument("Null pointer passed to fill_matrix");
    }

    switch (option) {
    case 'h':
    case 'H':
        hand(matrix, n);
        break;
    case 'r':
    case 'R':
        random(matrix, n);
        break;
    default:
        throw std::invalid_argument("Invalid option. Use 'h' for manual or 'r' for random input");
    }
}

//функция вывода матрицы
void print_matrix(int** matrix, int n) {
    if (matrix == nullptr) {
        throw std::invalid_argument("Null pointer passed to print_array");
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << "\n";
    }

}
// Функция нахождения макс элемента в правом нижнем треугольнике
int findMaxInLowerRightTriangle(int** matrix, int n) {
    if (matrix == nullptr) {
        throw std::invalid_argument("Matrix is null");
    }

    int maxElement = matrix[n - 1][n - 1];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j >= n - 1) {
                if (matrix[i][j] > maxElement) {
                    maxElement = matrix[i][j];
                }
            }
        }
    }
    return maxElement;
}

// Функция для поиска максимального положительного элемента и его позиции
void findMaxPositiveElement(int** matrix, int n, int* maxRow, int* maxCol, int* maxValue) {
    if (matrix == nullptr) {
        throw std::invalid_argument("Matrix is null");
    }

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
    if (matrix == nullptr) {
        throw std::invalid_argument("Matrix is null");
    }
    if (row1 < 0 || row1 >= n || row2 < 0 || row2 >= n) {
        throw std::out_of_range("Row index out of range");
    }

    for (int j = 0; j < n; j++) {
        int temp = matrix[row1][j];
        matrix[row1][j] = matrix[row2][j];
        matrix[row2][j] = temp;
    }
}

// Функция для перестановки столбцов
void swapColumns(int** matrix, int n, int col1, int col2) {
    if (matrix == nullptr) {
        throw std::invalid_argument("Matrix is null");
    }
    if (col1 < 0 || col1 >= n || col2 < 0 || col2 >= n) {
        throw std::out_of_range("Column index out of range");
    }

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
        throw std::runtime_error("No positive elements found in the matrix!");
    }

    std::cout << "Maximum positive element: " << maxValue
        << " at position [" << maxRow << "][" << maxCol << "]" << std::endl;

    if (maxRow != 0) {
        swapRows(matrix, n, 0, maxRow);
        std::cout << "Swapped rows 0 and " << maxRow << std::endl;
    }

    if (maxCol != 0) {
        swapColumns(matrix, n, 0, maxCol);
        std::cout << "Swapped columns 0 and " << maxCol << std::endl;
    }
}

int main() {
    int** matrix = nullptr;
    int n;
    char option;
    try {
        std::cout << "Enter the num of rows and columns: ";
        n = read_matrix_size();
        n = read_matrix_size();


        allocate_matrix(matrix, n);
        std::cout << "Choose Hand Input or Random Input (h/r): ";
        std::cin >> option;
        std::cin.ignore();

        fill_matrix(option, matrix, n);
        
        std::cout << "\nOriginal matrix:" << std::endl;
        print_matrix(matrix, n);

        std::cout << " Task 1 \n";
        try {
            std::cout << "Maximum element in lower right triangle: " << findMaxInLowerRightTriangle(matrix, n) << "\n";
        }
        catch (const std::exception& e) {
            std::cout<< e.what() << "\n";
        }

        std::cout << " Task 2 \n";
        try {
            rearrangeMatrix(matrix, n);
            std::cout << "Matrix after rearrangement:"<<  "\n";
            print_matrix(matrix, n);
        }
        catch (const std::exception& e) {
            std::cout << e.what() << "\n";
        }

    }
    catch (const std::exception& e) {
        std::cerr << "Critical error: " << e.what() << "\n";
        if (matrix != nullptr) {
            delete_mat(matrix, n);
        }
        return 1;
    }
    
    try {
        if (matrix != nullptr) {
            delete_mat(matrix, 0);
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    catch (...)
    {
        std::cout << "Unknown error" << std::endl;
        delete_mat(matrix, n);
        return 1;
    }
    return 0;
}