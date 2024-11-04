
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a > 0 && c < 10 * 10 * 10 * 10 && b)
    {
        cout << a * b * c;
    }
    else
    {
        cout << "Неправильные стороны.";
    }

    return 0;
}

