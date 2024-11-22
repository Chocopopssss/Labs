#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int x;
    cin >> x;
    if (0 < x < 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10)
    {
        int i = 2;
        cout << (x | (0 << i));
    }

    return 0;
}

