#include <iostream>
#include <vector>

using namespace std;

// Функция для проверки, начинается и заканчивается ли число одной и той же цифрой
bool startsAndEndsWithSameDigit(int number) 
{
    int startDigit = number;
    while (startDigit >= 10) 
    {
        startDigit /= 10;
    }
    int endDigit = number % 10;
    return startDigit == endDigit;
}

// Функция для обработки последовательности
void processSequence(int mas[], int& n) 
{
    int newSize = 0; // Новый размер массива

    for (int i = 0; i < n; i++) 
    {
        if (!startsAndEndsWithSameDigit(mas[i])) {
            mas[newSize] = mas[i]; // Сохраняем элемент, если он не подлежит удалению
            newSize++; // Увеличиваем новый размер массива
            // Если число начинается с 3, дублируем его
            int temp = mas[i];
            while (temp >= 10) 
            {
                temp /= 10;
            }
            if (temp == 3) 
            {
                if (newSize < 10000) // Проверяем, не превышает ли размер массива
                { 
                    mas[newSize] = mas[i];
                    newSize++; // Увеличиваем новый размер массива
                }
            }
        }
    }
    n = newSize; // Обновляем размер массива
}

// Функция для вывода последовательности
void printSequence(int mas[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        cout << mas[i] << " ";
    }
    cout << endl;
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    int n;

    cout << "Введите количество элементов в последовательности (максимум 10000): ";
    cin >> n;
    if (n <= 0 || n > 10000) 
    {
        cout << "Неверное количество элементов." << endl;
        return 1;
    }

    int mas[10000]; // Исходный массив для хранения последовательности

    cout << "Введите элементы последовательности: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> mas[i];
    }

    processSequence(mas, n); // Обработка последовательности

    cout << "Полученная последовательность: ";
    printSequence(mas, n); // Вывод результата

    return 0;
}