#include <iostream> 
#include <limits>
#include <cmath> 
#include <iomanip>
using namespace std;

int main() 
{
    
    const int SIZE = 8; 
    double A[SIZE] = { -1.2, -2.5, 3.0, -4.0, -5.75, 1.5, -6.1, 2.2 };

    double pro = 1.0; 
    double minimum = 1.0; 
    int min_index = -1; 
    bool has_negative = false; 

    
    for (int i = 0; i < SIZE; ++i) 
    {
        
        if (A[i] < 0 && A[i] != static_cast<int>(A[i])) 
        {
            has_negative = true; 

            
            if (A[i] < minimum) 
            {
                minimum = A[i];
                min_index = i;
            }

            pro *= A[i];
        }
    }

    cout << "Pro: " << pro << endl;
    cout << "Min: " << minimum << endl;
    cout << "Number: " << min_index << endl;
    
    int n;
    cin >> n;
    int min = 9;
    if (n<10*10*10*10*10*10*10*10*10)
    { 
        while (n > 0)
        {
            int digit = n % 10;
            if (digit < min) min = digit;
            
            n /= 10;
            
        }
    }
    cout << min;
   
    return 0;
}

