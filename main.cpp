#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
// Функция для вычисления факториала
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}
int main() {
    setlocale(LC_ALL, "Russian");
    int N, n;

    // Ввод N
    cout << "Введите значение N: ";
    cin >> N;

    // Ввод n
    cout << "Введите значение n (0 <= n <= N): ";
    cin >> n;

    if (n < 0 || n > N) {
        cout << "n должна быть в диапазоне от 0 до N." << endl;
        return 1;
    }

    int S = 0;  // Сумма S
    cout << "\nN; n; t, наносекунд | | O(log2 n) |" << endl;
    for (int i = 0; i <= n; ++i) {
        int nechet = 2 * i + 1;

        // Измерение времени выполнения факториала
        clock_t start = clock();
        int fact = factorial(nechet);
        clock_t end = clock();

        S += fact;  // Обновление суммы S
        double timeElapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e9; // перевод в наносекунды

        // Расчет O(log2 i)
        double log2i = (i > 0) ? log2(i) : 0;

        cout << N << "; " << i << "; " << timeElapsed << "; " << log2i << ";" << endl;
    }

    cout << "Сумма S = " << S << endl;

    return 0;
}

