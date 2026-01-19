#include "marker.h"

int main() {
	Marker m1(Marker::Color::GREEN, 45);
	m1.Write("hello", 5);
	m1.Write(" world", 6);
	Marker m2 = m1; // копирование при конструировании m2
	m2.Write(" Vasya", 6);
	m1.Draw(); // hello world
	m2.Draw(); // vasya
	
	m2.Erase();
	m1.Draw(); // hello world
	m2.Draw(); // -
	
	m2 = m1;
	m2.Draw(); // hello world
}
