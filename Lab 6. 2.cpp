#include <iostream>
using namespace std;

// Функция для вычисления суммы цифр числа
int sumOfDigits(int number) 
{
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

// Функция для получения первой цифры числа
int firstDigit(int number) 
{
    while (number >= 10) 
    {
        number /= 10;
    }
    return number;
}

// Функция сортировки массива по сумме цифр и первой цифре
void sortArray(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            int sum_j = sumOfDigits(arr[j]);
            int sum_j1 = sumOfDigits(arr[j + 1]);
            int first_j = firstDigit(arr[j]);
            int first_j1 = firstDigit(arr[j + 1]);

            if (sum_j > sum_j1 || (sum_j == sum_j1 && first_j > first_j1)) 
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    const int MAX_SIZE = 1000;
    int arr[MAX_SIZE];
    int n;

    cout << "Введите количество элементов (n <= 1000): ";
    cin >> n;

    cout << "Введите " << n << " натуральных чисел:\n";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    // Сортируем массив
    sortArray(arr, n);

    cout << "Упорядоченная последовательность:\n";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}