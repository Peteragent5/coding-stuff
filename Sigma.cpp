#include <iostream>
#include <cmath>
using namespace std;
//current function is ( double(k)/double(2*k+1) )

void simplify_fraction_work(int num, int denom) {
	for (int i = denom; i>=2; i--) {
		if (num % i == 0 && denom % i == 0) {
		num = num/i;
		denom = denom/i;
		}
	}
	if (denom == 1) cout << num << " ";
	else cout << num << "/" << denom << " ";
}

void simplify_fraction(double number) {
	double fractional_part = number - floor(number);

	for (double i = 0.1, j = 10;  ; i/=10, j*=10) {
		if ( fractional_part >= i ) {
			simplify_fraction_work(number * j, j);
			break;
		}
	}
}

//Simplify fraction functions needs work..

double sigma(int k, int stop) {
	double sum = 0;
	for( ; k <= stop ; k++) {
	sum += ( double(k)/double(2*k+1) ) ; // sum = sum + k;
	}
	return sum;
}

int numberOfTerms(int k, int stop) {
        int count = 0;
        for ( ; k <= stop; k++) count++;
        return count;
}

void valueOfEachTermInSigma(int k, int stop) {
	double sum = 0.0;
	for( ; k <= stop ; k++) {
	sum = (double(sum) + ( double(k)/double(2*k+1) )) - double(sum);
	/*if (sum == floor(sum) ) cout << sum << " ";
	else simplify_fraction(sum);*/
	cout << sum << " ";
	}
}

void sumOfEachTermInSigma(int k, int stop) {
	double sum = 0;
	for( ; k <= stop ; k++) {
	//cout << k << endl;
	cout << ( sum += ( double(k)/double(2*k+1) ) ) << " "; // sum = sum + k;
	}
}

void allSigma(int k, int stop) {
	cout << "Sum of Total: " << sigma(k, stop) << endl;
	cout << "Number of Terms: " << numberOfTerms(k, stop) << endl;
	
	cout << "Each Term: ";
	valueOfEachTermInSigma(k, stop);
	cout << endl << "Sum of Each Term: ";
	sumOfEachTermInSigma(k, stop);
	cout << endl;
}

int main () {
	double stop = 4;
	double k = 0;
	allSigma(k, stop);
}