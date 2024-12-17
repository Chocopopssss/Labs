#include <iostream>
#include <cmath>
#include "utilities.hpp"

using namespace std;

int main()
{
	int n;
	cin >> n;

	int** A = create_and_fill_array(n);
	print_array(A, n);

	print_array(A, n);
	delete_array(A, n);


	return 0;
}