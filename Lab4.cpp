#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b, c;                         // Подзадача №1
    cin >> a >> b >> c;
    
    if(a < b && b < c)
    {
        cout << c - b - a << endl;
    }
    else if(a % c == 0)
    {
        cout << a / c + b << endl;
    }
    else
    {
        cout << a + b + c << endl;
    }
    
    int n;                              // Подзадача №2
    cin >> n;
    switch (n)
        {
            case 1: cout << "Булочка с изюмом." << endl;
                break;
            case 2: cout << "Булочка с маком." << endl;
                break;
            case 3: cout << "Булочка с карамелью." << endl;
                break;
            case 4: cout << "Булочка с шоколадом." << endl;
                break;
            case 5: cout << "Булочка с корицей." << endl;
                break;
            default: cout << "Товар не найден." << endl;
                break;
        }
    int z;                             // Подзадача №3
    cin >> z;
    cout << (z < 0 ? "Negative number" : "Positive number") << endl; //Выбрала данный оператор, т.к. хорошо работает на маленьких конструкциях.
    
    return 0;
}
