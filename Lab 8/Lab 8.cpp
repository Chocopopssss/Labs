#include <iostream>
#include <fstream>
#include <string>
#include <cctype> // Для функций isalpha
#include "function.hpp"

using namespace std;

int main() 
{
    setlocale(LC_ALL, "Russian");
    const int MAX_WORDS = 1000; // Максимальное количество слов
    const int MAX_LENGTH = 10000; // Максимальный размер текста

    char text[MAX_LENGTH];
    string wordsWithRepeatingVowels[MAX_WORDS];
    string invertedWords[MAX_WORDS];
    int vowelWordCount = 0, invertedWordCount = 0;

    // Чтение текста из файла input.txt
    ifstream inputFile("input.txt");
    if (!inputFile) 
    {
        cout << "Не удалось открыть файл input.txt" << endl;
        return 1;
    }

    inputFile.getline(text, MAX_LENGTH);
    inputFile.close();

    // Разделение текста на слова вручную
    string currentWord = "";
    for (int i = 0; text[i] != '\0'; i++) 
    {
        if (isalnum(text[i])) 
        {
            currentWord += text[i];
        }
        else if (!currentWord.empty()) 
        {
            if (hasRepeatingVowels(currentWord)) 
            {
                wordsWithRepeatingVowels[vowelWordCount++] = currentWord;
            }
            else 
            {
                invertedWords[invertedWordCount++] = invertWord(currentWord);
            }
            currentWord = "";
        }
    }
    // Добавляем последнее слово, если оно существует
    if (!currentWord.empty()) 
    {
        if (hasRepeatingVowels(currentWord)) 
        {
            wordsWithRepeatingVowels[vowelWordCount++] = currentWord;
        }
        else 
        {
            invertedWords[invertedWordCount++] = invertWord(currentWord);
        }
    }

    // Сортируем слова с повторяющимися гласными вручную
    manualSort(wordsWithRepeatingVowels, vowelWordCount);

    // Вывод результата
    cout << "Слова с повторяющимися гласными (в алфавитном порядке):" << endl;
    for (int i = 0; i < vowelWordCount; i++) 
    {
        cout << wordsWithRepeatingVowels[i] << endl;
    }

    cout << "Инвертированные слова:" << endl;
    for (int i = 0; i < invertedWordCount; i++) 
    {
        cout << invertedWords[i] << endl;
    }

    return 0;
}