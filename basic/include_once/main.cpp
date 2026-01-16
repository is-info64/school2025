/*
 [Source file] > [препроцессор] > [единица трансляции] > [компилятор] > [.obj]
 
 Компоновщик - из нескольких .obj формирует единый .exe
 
 Логическая структура - namespace
 Физическая структура - разбиение на файлы
 
 команда компиляции:  g++ main.cpp math.cpp 
	либо
 g++ math.cpp -c -o math.o
 g++ main.cpp -c -o main.o
 g++ math.o math.o -o main.exe	
 
 */
#include <iostream>
#include "math.h"
#include "quadro.h"

int main() {
	std::cin >> quadro::side;
	int res = quadro::calcSquare();
	std::cout << res;
}

































