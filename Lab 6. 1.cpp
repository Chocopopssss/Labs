#include <iostream>
using namespace std;

// Функция для вычисления суммы цифр числа
int sumOfDigits(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

// Функция для сортировки массива по невозрастанию
void sortDescending(int mas[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (mas[j] < mas[j + 1]) {
                swap(mas[j], mas[j + 1]);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    const int MAX_SIZE = 10000;
    int mas[MAX_SIZE];
    int n;

    cout << "Введите количество элементов (n <= 10000): ";
    cin >> n;

    cout << "Введите " << n << " натуральных чисел:\n";
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    bool found = false;

    // Проверка на наличие числа с суммой цифр, равной 19
    for (int i = 0; i < n; i++) {
        if (sumOfDigits(mas[i]) == 19) {
            found = true;
            break;
        }
    }

    // Если не найдено, сортируем массив
    if (!found) {
        sortDescending(mas, n);
        cout << "Упорядоченная последовательность:\n";
        for (int i = 0; i < n; i++) {
            cout << mas[i] << " ";
        }
        cout << endl;
    }
    else {
        cout << "Найдено число с суммой цифр, равной 19.\n";
    }

    return 0;
}
