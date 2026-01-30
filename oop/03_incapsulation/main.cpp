#include "marker.h"
#include <iostream>

void ExceptionExample(){
	std::cout << "\n\n-----ExceptionExample_start()-----\n" << std::endl;
	try {
		Marker m(Marker::Color::GREEN, 20);
		m.Write('h').Write(220).Write('!');
		m.Draw();
	}
	catch(MaxCapacityEx exc) {
		std::cout << "[Error]: capacity exception: " << exc.max_size << std::endl;
	}
	catch(OverflowExc exc) {
		std::cout << "[Error]: max num of chars: " << exc.max_size << std::endl;
	}
	catch(Exception ex)	{
		std::cout << "[Error]: " << ex.mess << std::endl;
	}
	/*catch {
		std::cout << "[Error]: undefined" << std::endl;
	}*/
	std::cout << "\n=====ExceptionExample_end=====" << std::endl;
}

void InheritanceExample() {
	Marker m;
	m.Write('A');
	/*
		m.num_chars_ = -5; // error: ‘int Marker::num_chars_’ is private within this context
	*/
}
int main() {
	ExceptionExample();
	// InheritanceExample();
}
