#include "marker.h"
#include <iostream>

void ExceptionExample(){
	std::cout << "\n\n-----ExceptionExample_start()-----\n" << std::endl;
	try	{
		Marker m1(Marker::Color::GREEN, 101);
		m1.Write("hello", 5);
		m1.Write(" world", 6);
		m1.Draw();
	}
	catch (MaxSizeEx ex){
		std::cout << "some exc occur\nMax marker size less than " << ex.size << "\n";
	}
	std::cout << "\n=====ExceptionExample_end=====" << std::endl;
}

void MarkerTest(Marker marker) {
	std::cout << "\n--MarkerTest_start()--" << std::endl;
	marker.Draw();
	std::cout << "==tMarkerTest_end==\n" << std::endl;
}

void CopyCtorExample() {
	std::cout << "\n\n-----CopyCtorExample_start()-----\n" << std::endl;
	
	Marker m1;
	m1.Write('V');
	m1.Write('a');
	m1.Write('s');
	m1.Write('y');
	m1.Write('a');
	m1.Draw();
	MarkerTest(m1);
	/*Marker m2 = m1;
	m2.Write('P');
	m2.Write('e');
	m2.Write('t');
	m2.Write('y');
	m2.Write('a');
	m1.Draw();
	m2.Draw();
	m2.Erase();
	m1.Draw();
	m2.Draw();
	
	m2.Write('P');
	m2.Write('e');
	m2.Write('t');
	m2.Write('y');
	m2.Write('a');
	
	m1.Draw();*/
	
	std::cout << "\n=====CopyCtorExample_end=====" << std::endl;
}

void CopyAssignExample() {
	std::cout << "\n\n-----CopyAssignExample_start()-----\n" << std::endl;
	Marker m1, m2;
	m1.Write('V');	m1.Write('a');	m1.Write('s');	m1.Write('y');	m1.Write('a');
	m2.Write('P');	m2.Write('e');	m2.Write('t');	m2.Write('y');	m2.Write('a');
	m2 = m1;
	m2.Write('F');	m2.Write('e');	m2.Write('d');	m2.Write('o');	m2.Write('r');
	m1.Draw();
	m2.Draw();
	std::cout << "\n=====CopyAssignExample_end=====" << std::endl;
}

int main() {
	ExceptionExample();
	CopyCtorExample();
	CopyAssignExample();
}
