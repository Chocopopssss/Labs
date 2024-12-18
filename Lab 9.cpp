#include <iostream>

using namespace std;


int main()
{
	unsigned long long a; //Переменная a - это целое число типа unsigned long long.
	cin >> a;
	unsigned char* p = (unsigned char*)&a; // Эта строка создает указатель p, который указывает на начало памяти, где хранится переменная а
										   // Unsigned char работает с каждым байтом переменной, так как его размер равен 1 байту
	for (int i = 0; i < sizeof(a); i++) // Размер переменной а (в байтах) определяется с помощью sizeof(a) и равен 8 байтов (для типа unsigned long long)
	{
		int b = *(p + i); // Указатель p смещается на i байтов, чтобы получить значение текущего байта. Это значение сохраняется в переменную b
		cout << hex << b << " ";
	}
	
	return 0;
}
