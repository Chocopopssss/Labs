#include <iostream>
#include <fstream>
#include <string>
#include "utilities.hpp"

struct Node 
{
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList 
{
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Добавление элемента в конец списка
    void append(int value) 
    {
        Node* newNode = new Node(value);
        if (!head) 
        {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) 
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Чтение данных из файла
    void readFromFile(const std::string& filename) 
    {
        std::ifstream file(filename);
        int value;
        while (file >> value) 
        {
            append(value);
        }
    }

    // Удаление однозначных чисел
    void removeSingleDigitNumbers() 
    {
        Node* current = head;
        Node* prev = nullptr;
        while (current) 
        {
            if (current->data < 10) 
            {
                if (prev) 
                {
                    prev->next = current->next;
                }
                else 
                {
                    head = current->next;
                }
                delete current;
                current = prev ? prev->next : head;
            }
            else 
            {
                prev = current;
                current = current->next;
            }
        }
    }

    // Дублирование чисел-палиндромов длиной более 1 цифры
    void duplicatePalindromes() 
    {
        Node* current = head;
        while (current) 
        {
            if (isPalindrome(current->data) && current->data >= 10) 
            {
                Node* newNode = new Node(current->data);
                newNode->next = current->next;
                current->next = newNode;
                current = newNode->next;
            }
            else 
            {
                current = current->next;
            }
        }
    }

    // Функция для проверки упорядоченности последовательности
    bool isOrderedByFirstOrLastDigit() 
    {
        Node* current = head;
        bool byFirst = true, byLast = true;

        while (current && current->next) 
        {
            int firstCurrent = getFirstDigit(current->data);
            int firstNext = getFirstDigit(current->next->data);
            int lastCurrent = getLastDigit(current->data);
            int lastNext = getLastDigit(current->next->data);

            if (firstCurrent < firstNext) 
            {
                byFirst = false;
            }
            if (lastCurrent < lastNext) 
            {
                byLast = false;
            }
            current = current->next;
        }

        return byFirst || byLast;
    }

    // Упорядочивание по первой цифре (по неубыванию)
    void sortByFirstDigit() 
    {
        if (!head) return;

        bool swapped;
        do {
            swapped = false;
            Node* current = head;
            while (current && current->next) 
            {
                if (getFirstDigit(current->data) > getFirstDigit(current->next->data)) 
                {
                    std::swap(current->data, current->next->data);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }

    // Вывод списка в консоль
    void printList() const 
    {
        Node* current = head;
        while (current) 
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Запись списка в файл
    void writeToFile(const std::string& filename) 
    {
        std::ofstream file(filename);
        Node* current = head;
        while (current) 
        {
            file << current->data << " ";
            current = current->next;
        }
    }

    // Освобождение памяти
    ~LinkedList() 
    {
        Node* current = head;
        while (current) 
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList list;
    list.readFromFile("input.txt");
    if (list.isOrderedByFirstOrLastDigit()) 
    {
        list.removeSingleDigitNumbers();
        list.duplicatePalindromes();
    }
    else 
    {
        list.sortByFirstDigit();
    }

    list.printList();
    list.writeToFile("output.txt");

    return 0;
}