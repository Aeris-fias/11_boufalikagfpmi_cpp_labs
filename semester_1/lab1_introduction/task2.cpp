/*#include <iostream>
using namespace std;

 int main() {
    setlocale(LC_ALL, "Rus");

    int n;
    cout << "Введите натуральное число n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Ошибка: число должно быть натуральным (n > 0)" << endl;
        
    }

    int sumEven = 0;    
    int productOdd = 1; 

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            
            sumEven += i;
        }
        else {
            
            productOdd *= i;
        }
    }

    cout << "Сумма всех четных чисел от 1 до " << n << ": " << sumEven << endl;
    cout << "Произведение всех нечетных чисел от 1 до " << n << ": " << productOdd << endl;

    return 0;
}
*/