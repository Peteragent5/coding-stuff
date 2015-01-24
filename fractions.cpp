#include <iostream>
#include <cmath>
using namespace std;

void simplify_fraction(int num, int denom) {
	for (int i = denom; i>=2; i--) {
		if (num % i == 0 && denom % i == 0) {
		num = num/i;
		denom = denom/i;
		}
	}
	cout << "Fraction: ";
	if (denom == 1) cout << num;
	else cout << num << "/" << denom;
	cout << endl;
}


int main() {
	double number;
	cout << "Enter Number: ";
	cin >> number;
	double fractional_part = number - floor(number);

	for (double i = 0.1, j = 10;  ; i/=10, j*=10) {
		if ( fractional_part >= i ) {
			simplify_fraction(number * j, j);
			break;
		}
	}
	return 0;
}


