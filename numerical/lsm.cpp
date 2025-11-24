/*
	(c) Ivanov, 24/11/2025
	Осуществите математическое моделирование физической задачи:
	"Камень брошен под углом к горизонту"
*/

#include <iostream>
#include <cmath>

double _g = 9.8;

void TrajectoryModel(double a_0, double v_0, int x_N); // declaration

int main() {
	TrajectoryModel(30, 10, 20);
}

// declaration & definition
void TrajectoryModel(double a_0, double v_0, int x_N) {
	double alpha = 3.14 * a_0 / 180.0;
	double x_end = 3, x_start = 0;
	double dx = (x_end - x_start) / x_N;
	
	for (int i = 0; i < x_N; ++i) {
		double x = 0 + dx * i;
		double y = x * std::tan(alpha) - (_g * x * x) / (2 * v_0 * v_0 * std::pow(alpha, 2));
		std::cout << x << "\t" << y << std::endl;
	}
}
