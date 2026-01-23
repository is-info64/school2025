#ifndef MARKER_H_
#define MARKER_H_

#include <iostream>

class MaxSizeEx {
public:
	int size;
	MaxSizeEx(int _size) : size(_size) {}
};

extern int N_MARKER;

class Marker {
public:
	enum Color {
		RED = 31, GREEN = 32, BLACK = 30, PINK = 35
	};
	static const int MAX_BUFF = 100;
	int capacity;
	int num_chars;
	char* buff;
	Color clr;
	int ID;
	// конструкторы
	Marker(); // по умолчанию
	Marker(Color clr, int capacity);
	Marker(const Marker& rhs); // копирующий конструктор
	// Marker(Marker&& rhs); перемещающий конструктор (узнаете, когда вырастите)
	
	~Marker();// деструктор
	// Marker(const Marker& rhs) = delete; // запрет копирования при создании
		
	//Assignment operator
	Marker& operator=(const Marker& rhs);
		
	void Write(const char* c, int size);
	void Write(char c);
	void Draw();
	void Erase();
};
#endif
