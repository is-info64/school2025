#ifndef MARKER_H_
#define MARKER_H_

#include <iostream>

struct OverflowExc {
	int max_size;
	OverflowExc(int size) : max_size(size) { }
};

struct MaxCapacityEx {
	int max_size;
	MaxCapacityEx(int size) : max_size(size) { }
};

struct Exception {
	const char* mess;
	Exception(const char* m) : mess(m) { }
};

extern int N_MARKER;

class Marker {
public:
	enum Color {
		RED = 31, GREEN = 32, BLACK = 30, PINK = 35
	};
	
	static const int MAX_BUFF = 100;
	// конструкторы
	Marker(); // по умолчанию
	Marker(Color clr_, int capacity_);
	Marker(const Marker& rhs); // копирующий конструктор
	// Marker(Marker&& rhs); перемещающий конструктор (узнаете, когда вырастите)
	
	~Marker();// деструктор
	// Marker(const Marker& rhs) = delete; // запрет копирования при создании
		
	//Assignment operator
	Marker& operator=(const Marker& rhs);
		
	Marker& Write(const char* c, int size);
	Marker& Write(char c);
	void Draw();
	void Erase();
	
private:
	int capacity_;
	char* buff_;
	Color clr_;
	int ID_;
	int num_chars_;
};
#endif
