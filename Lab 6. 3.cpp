#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

// Функция для нахождения строки с наибольшей по абсолютной величине суммой элементов
int findRowWithMaxAbsSum(int matrix[MAX_SIZE][MAX_SIZE], int n, int m) 
{
    int maxAbsSum = 0;
    int rowIndex = -1;

    for (int i = 0; i < n; i++) 
    {
        int currentSum = 0;
        for (int j = 0; j < m; j++) 
        {
            currentSum += matrix[i][j];
        }
        // Проверка на максимальную сумму по абсолютной величине
        if (abs(currentSum) > maxAbsSum) 
        {
            maxAbsSum = abs(currentSum);
            rowIndex = i;
        }
    }
    return rowIndex;
}

// Функция для замены элементов строки числом 9999
void replaceRowWith9999(int matrix[MAX_SIZE][MAX_SIZE], int rowIndex, int m) 
{
    for (int j = 0; j < m; j++) 
    {
        matrix[rowIndex][j] = 9999;
    }
}

// Функция для вывода матрицы
void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], int n, int m) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    int n, m;
    int matrix[MAX_SIZE][MAX_SIZE];

    cout << "Введите количество строк (n <= 100): ";
    cin >> n;
    cout << "Введите количество столбцов (m <= 100): ";
    cin >> m;

    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> matrix[i][j];
        }
    }

    // Находим строку с наибольшей по абсолютной величине суммой
    int rowIndex = findRowWithMaxAbsSum(matrix, n, m);

    if (rowIndex != -1) 
    {
        replaceRowWith9999(matrix, rowIndex, m);
        cout << "Матрица после замены:\n";
        printMatrix(matrix, n, m);
    }
    else 
    {
        cout << "Матрица пуста.\n";
    }

    return 0;
}
