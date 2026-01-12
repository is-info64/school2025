// nm.cpp  "Numerical/nm.cpp - должные быть производная, интеграл, брутфорс и бисекция, передача аргументов через константные ссылки"


#include <iostream>
#include <cmath>
//производная?? !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//интеграл
//задание kapi
double kapi(double t) {
    return -t * t + 100;
}
//интеграл
double Integral(double PR1, double PR2, int N) {
	double dt = (PR2 - PR1) / N;
	double sum = 0;
	for(int i = 0; i < N; i = i + 1) {
		double t_vremya = PR1 + (i + 0.5) * dt;
		sum = sum + kapi(t_vremya) * dt;
	}
	
	return sum;
}
// ________________________________________________


// ЗАДАНИЕ Task 4. Passing a function via an argument

//новый интеграл для последнего задания
double IntegralNoviy(double PR1, double PR2, int N, double (*func)(double)) {
	double dt = (PR2 - PR1) / N;
	double sum = 0;
	for(int i = 0; i < N; i = i + 1) {
		double t_vremya = PR1 + (i + 0.5) * dt;
		sum = sum + func(t_vremya) * dt;
	}
	
	return sum;
}
//новый синус функция для посл.зад
double sinus(double x) {
	return sin(x);
}

//функция новая для последнего задания
double parabola(double x) {
	return x * x;
}

//задание kapi
double kapi(double t) {
    return -t * t + 100;
}
//интеграл
double Integral(double PR1, double PR2, int N) {
	double dt = (PR2 - PR1) / N;
	double sum = 0;
	for(int i = 0; i < N; i = i + 1) {
		double t_vremya = PR1 + (i + 0.5) * dt;
		sum = sum + kapi(t_vremya) * dt;
	}
	
	return sum;
}
// ________________________________________________


// ЗАДАНИЕ Task 4. Passing a function via an argument

//новый интеграл для последнего задания
double IntegralNoviy(double PR1, double PR2, int N, double (*func)(double)) {
	double dt = (PR2 - PR1) / N;
	double sum = 0;
	for(int i = 0; i < N; i = i + 1) {
		double t_vremya = PR1 + (i + 0.5) * dt;
		sum = sum + func(t_vremya) * dt;
	}
	
	return sum;
}
//новый синус функция для посл.зад
double sinus(double x) {
	return sin(x);
}

//функция новая для последнего задания
double parabola(double x) {
	return x * x;
}


// ________________________________________________
// подсчёт для брутфорс и бисекшн, ищет корень заданного x2

double f(double x) {
	return x * x - 2;
}
// задание брутфорс
double BruteForce(double x1, double x2, int N) {
	double h = (x2 - x1) / N;
	double x_min = x1;
	double y_min = std::abs(f(x1)); //заменил fabs на abs

	for(int i = 0; i <= N; i++) {
		double x = x1 + i * h;
		double y = std::abs(f(x)); //заменил fabs на abs

		if(y < y_min) {
			y_min = y;
			x_min = x;
		}
	}


	return x_min;
}
// задание бисекшоун
double Bisection(double x1, double x2, int N) {

	double eps = 0.001;
	while ((x2-x1) > eps){
		double center = (x1+ x2)/2;
		if (f(x1) * f(center) < 0){
			x2 = center;
		} else {
			x1 = center;
		}
 }
		
 return (x1 + x2) / 2;
 }
 
 
 //код
int main() {

	double a;
	std::cout << "1(bruteforce) , 2(bisection), 3(Passing a function via an argument - parabola), 4((Passing a function via an argument - sinus) \t";
	
	std::cin >> a;
	if (a == 1){
		double itog = BruteForce(1, 2, 100);
		std::cout << itog;
	}
	else if(a == 2){
		double itog = Bisection(1, 2, 100);
		std::cout << itog;
	}
	else if(a == 3){
		int a3=0, a4=0, a5=0;
		
		std::cout << "Vved nizhn predel \t";
		std::cin >> a3;
		std::cout << "Vved verh	predel \t";
		std::cin >> a4;
		std::cout << "Vved kolvo N razbieniy";
		std::cin >> a5;
		double a6 = IntegralNoviy(a3, a4, a5, parabola);
		std::cout << a6;
	}
	else if(a == 4){
		int a3=0, a4=0, a5=0;
		std::cout << "Vved nizhn predel \t";
		std::cin >> a3;
		std::cout << "Vved verh	predel \t";
		std::cin >> a4;
		std::cout << "Vved kolvo N razbieniy";
		std::cin >> a5;
		double a6 = IntegralNoviy(a3, a4, a5, sinus);
		std::cout << a6;
	}
	else {
		std::cout << "NO TASK";
	}
*/
}