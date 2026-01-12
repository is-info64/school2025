/*
	Liznev Dmitriy
	Numerical Methods – lesson 02
	Numerical/lsm.cpp - траектория, ReadData и функция невязки.
	
*/
#include <iostream>
#include <cmath>
//задание trajectory
void TrajectoryModel(double a_0, double v_0, double Xpoints){
	double g = 10;
	double PI = 3.14;
	double konpolet, odin_x;
	double form_vivod = g / (2 * v_0 * v_0 * pow(cos(a_0), 2)); // вывод из y(x) = x·tg(α) – (g·x²)/(2·v₀²·cos²(α))  >> эта переменная это ->"  g / (2 * v_0 * v_0 * pow(cos(a_0), 2))   " 
	konpolet = v_0 * v_0 * sin(2 * a_0) / g;
	odin_x = konpolet / (Xpoints - 1);
	std::cout << Xpoints << std::endl;
	for (int i = 0; i < Xpoints; ++i){
		double x = i * odin_x;
		double y = x * tan(a_0) - form_vivod * x * x;
		std::cout << x << "\t" << y << std::endl;
	}
}


// рид дата lsm
int ReadData(double* x_exp, double* y_exp) {
	int N;
	std::cin >> N;
	x_exp = new double[N];
	y_exp = new double[N];

	for (int i = 0; i < N; i++) {
		std::cin >> x_exp[i] >> y_exp[i];
	}
	
	return N;
}

// не вязка 
double Neyazka(double ugol, double skorost, double* x_exp, double* y_exp, int n) {
	double summa = 0;
	for (int i = 0; i < n; i++) {
		double x = x_exp[i];
		double y_teoria = x * tan(ugol) - (g * x * x) / (2 * skorost * skorost * cos(ugol) * cos(ugol));
        double y_experiment = y_exp[i];
        
        // Разница как раз невязка между теорией и экспериментом
		double raznica = y_teoria - y_experiment;
		double kvadrat_raznicy = raznica * raznica;
		summa = summa + kvadrat_raznicy;
    }
    
    return summa;
}

// Билдсурфейс
void BuildSurface(double ugol_nach, double ugol_kon, int deleniy_ugla, double skorost_nach, double skorost_kon, int deleniy_skorosti, double* x_exp, double* y_exp, int n) {
	double shag_ugla = (ugol_kon - ugol_nach) / deleniy_ugla;
	double shag_skorosti = (skorost_kon - skorost_nach) / deleniy_skorosti;
	
	for (int i = 0; i <= deleniy_ugla; i++) {
		double ugol = ugol_nach + i * shag_ugla;
		for (int j = 0; j <= deleniy_skorosti; j++) {
			double skorost = skorost_nach + j * shag_skorosti;
			double neyazka_value = Neyazka(ugol, skorost, x_exp, y_exp, n);
			std::cout << skorost << " " << ugol << " " << neyazka_value << std::endl;
		}
		std::cout << std::endl;
	}
}
// solution

void Solution(double a_begin, double a_end, int a_N, double v_begin, double v_end, int v_N, double* x_exp, double* y_exp, int n, double* a_s, double* v_s) {
	double shag_ugla = (a_end - a_begin) / a_N;
	double shag_skorosti = (v_end - v_begin) / v_N;
	double min_neyazka = 1e100;
	double best_ugol = 0;
	double best_skorost = 0;
	for (int i = 0; i <= a_N; i++) {
		double ugol = a_begin + i * shag_ugla;
		for (int j = 0; j <= v_N; j++) {
			double skorost = v_begin + j * shag_skorosti;
            
	// невязка
			double neyazka_value = Neyazka(ugol, skorost, x_exp, y_exp, n);
			
			if (neyazka_value < min_neyazka) {
				min_neyazka = neyazka_value;
				best_ugol = ugol;
				best_skorost = skorost;
			}
		}
	}
	
	*a_s = best_ugol;
	*v_s = best_skorost;
	
	std::cout << best_ugol << std::endl;
	std::cout << best_skorost << std::endl;
	std::cout << min_neyazka << std::endl;
}
//код
int main() {

/*	
	// тут он читает с файла для ридата
	double* x_exp;
	double* y_exp;
	int num_points = ReadData(x_exp, y_exp);
	std::cout << num_points << " \t ";
	delete[] y_exp;
	delete[] x_exp;
*/
/*
// билдсюрфейс
	int MAX_TOCHEK = 1000;
	double x_exp[MAX_TOCHEK];
	double y_exp[MAX_TOCHEK];
    
	// тут он читает с файла для билдсюрфейс
	int n = ReadData(x_exp, y_exp, MAX_TOCHEK);
	double ugol_nach = 0.1;
	double ugol_kon = 1.4;
	int deleniy_ugla = 50;
	double skorost_nach = 5.0;
	double skorost_kon = 30.0;
	int deleniy_skorosti = 50;

	BuildSurface(ugol_nach, ugol_kon, deleniy_ugla, skorost_nach, skorost_kon, deleniy_skorosti, x_exp, y_exp, n);
*/
}
/*	
	double a;
	std::cout << "1(bruteforce) , 2(bisection), 3(Passing a function via an argument - parabola), 4((Passing a function via an argument - sinus), 5(fail  Model, LSM #2 Read Data) , 6 (Solution) \t";
	
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
		else if(a == 6){
		const int MAX_TOCHEK = 1000;
		double x_exp[MAX_TOCHEK];
		double y_exp[MAX_TOCHEK];
		int n = ReadData(x_exp, y_exp, MAX_TOCHEK);
		double a_s, v_s;
		Solution(0.1, 1.4, 100, 5.0, 30.0, 100, x_exp, y_exp, n, &a_s, &v_s);
		std::cout << a_s << v_s; 
	}
	else {
		std::cout << "NO TASK";
	}
*/
}