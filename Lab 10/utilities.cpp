#include "utilities.hpp"
#include <string>

// ������� ��� ��������� ������ ����� �����
int getFirstDigit(int number) 
{
    while (number >= 10) 
    {
        number /= 10;
    }
    return number;
}

// ������� ��� ��������� ��������� ����� �����
int getLastDigit(int number) 
{
    return number % 10;
}

// ������� ��� ��������, �������� �� ����� �����������
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