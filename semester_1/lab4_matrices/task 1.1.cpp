#include <iostream>
#include <random>

int readInt(){
    int value;
    if (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"Expected integer value"<<std::endl;
    }
    return value;
}


void allocateMatrix(int**& matrix, int n_rows, int n_cols){
    matrix = new int* [n_rows];

    for (size_t i = 0; i < n_rows; i++){
        matrix[i] = new int [n_cols];
    }
}

int read_matrixSize() {
    int size = readInt(); 
    
    if (size <= 0) {
         std::cout<<"Size must be > 0"<< std::endl;
    }
    
    return size;
}

void deleteMatrix(int** matrix, int n_rows){
    if (matrix == nullptr){
        return;
    }
    
    for (size_t i = 0; i < n_rows; i++){
        if (matrix[i] != nullptr){
            delete [] matrix[i];
            matrix[i] = nullptr;
        } 
    }
    delete [] matrix;
}

std::pair<int, int> read_random_limits(){    
   
    std::cout << "Enter the range of random: ";
    int lower_limit = readInt();
    int upper_limit = readInt();

    if (lower_limit > upper_limit){
        std::swap(lower_limit, upper_limit);
    }

    return {lower_limit, upper_limit};
}

void fillRandom(int** matrix, int n_rows, int n_cols){
    if (matrix == nullptr) {
        std::cout<<"Null pointer passed to fill_random"<< std::endl;
    }
    
    auto limits = read_random_limits();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(limits.first, limits.second);  
    
    for (size_t i = 0; i < n_rows; i++) {
        for (size_t j = 0; j < n_cols; j++){
            matrix[i][j] = distrib(gen);
        }
    }
}

void fillHand(int** matrix, int n_rows, int n_cols){
    if (matrix == nullptr) {
        std::cout<<"Null pointer passed to fill_manual"<<std::endl;
    }
    std::cout << "Enter the elements of matrix: ";
    for (size_t i = 0; i < n_rows; i++){
        for (size_t j = 0; j < n_cols; j++){
            matrix[i][j] = readInt();
        }
    }
}

void fillMatrix(char option, int** matrix, int n_rows, int n_cols) {
    if (matrix == nullptr) {
        std::cout<<"Null pointer passed to fill_matrix"<<std::endl;
    }
    
    switch (option) {
        case 'H':
        case 'h':
            fillHand(matrix, n_rows, n_cols);
            break;
        case 'R':
        case 'r':
            fillRandom(matrix, n_rows, n_cols);
            break;
        default:
            std::cout<<"Invalid option. Use 'h' for manual or 'r' for random input"<<std::endl;
    }
}

void printMatrix(int** matrix, int n_rows, int n_cols){
    if (matrix == nullptr) {
        std::cout<<"Null pointer passed to print_matrix"<<std::endl;
    }
    
    for (size_t i = 0; i < n_rows; i++){
        for (size_t j = 0; j < n_cols; j++){
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << "\n";
    }
    
}

void bubbleSort(int* arr, int size, bool (*comp)(int, int)){
    
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (comp(arr[j], arr[j + 1])){
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void quickSort(int *arr,int left, int right, bool (*comp)(int, int)){
if (left >= right) return;

int pivot = arr[(left + right) / 2];
int i = left;
int j = right;

while (i <= j) {
    while (comp(pivot,arr[i])) i++;
    while (comp(arr[j],pivot)) j--;

    if (i <= j) {
        std::swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

quickSort(arr, left, j, comp);
quickSort(arr, i, right,comp);
}

void merge(int *a, int left, int mid, int right, int* temp, bool (*comp)(int, int)){
    int i = left;
    int j = mid;
    int k = left;

    while(i < mid && j < right){
        if(comp(a[j], a[i])) { 
            temp[k] = a[i];
            i++;
        } else {
            temp[k] = a[j];
            j++;
        }
        k++;
    }
    while(i < mid){
        temp[k] = a[i];
        i++;
        k++;
    }
    while(j < right){
        temp[k] = a[j];
        j++;
        k++;
    }

    for(int t = left; t < right; t++)
        a[t] = temp[t];
}

void mergeSort(int* a, int left, int right, int *temp, bool (*comp)(int, int)){
    if(right - left <= 1) return;

    int mid = (left + right) / 2;
    mergeSort(a, left, mid, temp, comp);
    mergeSort(a, mid, right, temp, comp);
    merge(a, left, mid, right, temp, comp);
}

void insertion_sort(int* arr, int n, bool (*comp)(int, int)) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && comp(arr[j], key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

bool ascending(int a, int b){
    return a > b;
}

bool descending(int a, int b){
    return a < b;
}

void order_choice(bool (*&comp)(int, int)){
    int order;
    std::cout << "Choose order of sorting (1 - ascending, 2 - descending): ";
    order = readInt();

    switch (order) {
        case 1:
            comp = ascending;
            break;
        case 2:
            comp = descending;
            break;
        default:
            std::cout<<"Invalid option. 1 or 2 only"<<std::endl;
    }
    
}

void sort_choice(int** mat, int n_rows, int n_cols, bool (*comp)(int, int)){
    if (mat == nullptr) {
        std::cout<<"Null pointer passed to sort_choice"<<std::endl;
    }  
    if (comp == nullptr) {
        std::cout<<"Comparison function not set"<<std::endl;
    }

    int option;
    std::cout << "Choose your sort: 1 - Bubble, 2 - Quick, 3 - Merge, 4 - Insertion : ";
    option = readInt();
    // Создаем временный массив для Merge Sort
    int* temp = new int[n_cols];
    for (size_t i = 0; i < n_rows; i++){
        switch (option){
             case 1:
            bubbleSort(mat[i], n_cols, comp);
            break;
        case 2:
            quickSort(mat[i], n_cols - 1, comp);
            break;
        case 3:
            mergeSort(mat[i], n_cols, temp , comp);
            break;
             case 4:
            insertion_sort(mat[i], n_cols, comp);
            break;
        default:
            std::cout << "Incorrect option input!\n";
            delete[] temp;
            exit (1);
}
    }
    delete[] temp;
}
int main(){
    int rows = 0, cols = 0;
    char option;
        
    bool (*comp)(int, int) = nullptr;
    int** mat = nullptr;        
        std::cout << "Enter the num of rows and columns: ";
        rows = read_matrixSize();
        cols = read_matrixSize();
        allocateMatrix(mat, rows, cols);

        std::cout << "Choose Hand Input or Random Input (h/r): ";
        std::cin >> option;
        std::cin.ignore();

        fillMatrix(option, mat, rows, cols);
        
        std::cout << "Before sort:\n";
        printMatrix(mat, rows, cols);
        
        order_choice(comp);
        sort_choice(mat, rows, cols, comp);
        printMatrix(mat, rows, cols);

        deleteMatrix(mat, rows);
        return 0;
    }