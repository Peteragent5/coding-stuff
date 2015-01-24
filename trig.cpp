
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <limits>
#define PI 3.14159265
using namespace std;

double Sin(double angle) {
	return sin( angle * PI / 180.0 );
}
double Sin1(double param) {
	return asin(param) * 180.0 / PI;
}
double Cos(double angle) {
	return cos( angle * PI / 180.0 );
}
double Cos1(double param) {
	return acos(param) * 180.0 / PI;
}
double Tan(double angle) {
	return tan( angle * PI / 180.0 );
}
double Tan1(double param) {
	return atan(param) * 180.0 / PI;
}

int main() {
	double i;
	cout << "Enter a number: ";
	while (1) {
  if (cin >> i) {
      // valid number
      break;
  } else {
      // not a valid number
      cout << "Enter a number: ";
      cin.clear();
	 while (cin.get() != '\n') ; // empty loop
  }
}
	cout << "\nsin-1(" << i << ") = " << Sin1(i);
	return 0;
}

