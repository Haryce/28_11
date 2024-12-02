#include <iostream>
#include <time.h>
using namespace std;

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int N, n;
    cout << "Введите n: ";
    cin >> n;
    cout << "Введите N: ";
    cin >> N;
    clock_t start = clock();
    int S = 0;
    for (int i = 1; i <= n; i++) {
        S += factorial(2 * i + 1);
    }
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000000000;
    cout << "Время выполнения: " << time_taken << " наносекунд" << endl;
    cout << "О(log2 n): " << log2(n) << endl;
    return 0;
}
