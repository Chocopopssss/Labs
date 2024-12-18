#include "function.hpp"

// Проверяет, содержит ли слово повторяющиеся гласные
bool hasRepeatingVowels(const string& word) 
{
    string vowels = "aeiouAEIOU";
    bool seen[256] = { false }; // Для отслеживания повторений
    for (char c : word) 
    {
        if (vowels.find(c) != string::npos) 
        {
            if (seen[c]) 
            {
                return true; // Найдено повторение гласной
            }
            seen[c] = true;
        }
    }
    return false;
}

// Инвертирует слово
string invertWord(const string& word) 
{
    string inverted = word;
    int n = word.length();
    for (int i = 0; i < n / 2; i++) 
    {
        swap(inverted[i], inverted[n - i - 1]);
    }
    return inverted;
}

// Сортирует массив строк вручную в алфавитном порядке
void manualSort(string arr[], int size) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}