#include "marker.h"

int main() {
	Marker m1(Marker::Color::GREEN, 45);
	m1.Write("hello", 5);
	Marker m2 = m1; // копирование (m2.buff = m1.buff оба буффера указывают на одну область памяти)
	m1.Draw(); // hello 
	m2.Draw(); // hello
	
	m2.Erase();
	m2.Write('y');
	
	m1.Draw(); // yello 
	m2.Draw(); // y
	
}
