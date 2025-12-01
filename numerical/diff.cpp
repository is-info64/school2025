#include <iostream>

double f(double x);
double df_dx(double x, double eps = 0.0001);

int main() {
	double x;
	std::cin >> x;
	double d = df_dx(x);
	std::cout << d;
}

double df_dx(double x, double eps) {
	return (f(x + eps) - f(x)) / eps; 
}

double f(double x) {
	return x * x;
}

