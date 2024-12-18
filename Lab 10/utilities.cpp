#include "utilities.hpp"
#include <string>

// Функция для получения первой цифры числа
int getFirstDigit(int number) 
{
    while (number >= 10) 
    {
        number /= 10;
    }
    return number;
}

// Функция для получения последней цифры числа
int getLastDigit(int number) 
{
    return number % 10;
}

// Функция для проверки, является ли число палиндромом
bool isPalindrome(int number) 
{
    std::string str = std::to_string(number);
    int len = str.length();
    for (int i = 0; i < len / 2; ++i) 
    {
        if (str[i] != str[len - 1 - i]) 
        {
            return false;
        }
    }
    return true;
}