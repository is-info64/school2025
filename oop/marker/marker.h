#ifndef MARKER_H_
#define MARKER_H_

#include <iostream>

class Marker {
public:
	enum Color {
		RED = 31, GREEN = 32, BLACK = 30, PINK = 35
	};
	const int MAX_BUFF = 100;
	int capacity;
	int num_chars;
	char* buff;
	Color clr;
	
	// конструкторы
	Marker(); // по умолчанию
	Marker(Color clr, int capacity);
	Marker(const Marker& rhs); // копирующий конструктор
	// Marker(const Marker& rhs) = delete; // запрет копирования при создании
		
	//Assignment operator
	Marker& operator=(const Marker& rhs);
		
	bool Write(const char* c, int size);
	bool Write(char c);
	void Draw();
	void Erase();
};
#endif
