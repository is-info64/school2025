#include "marker.h"

int N_MARKER = 0;

Marker::Marker() {
	this->capacity = MAX_BUFF;
	this->num_chars = 0;
	this->buff = new char[this->capacity];
	this->clr = Color::GREEN;
	ID = ++N_MARKER;
	std::cout << "default ctor: create ID = " << ID << std::endl;
}

Marker::Marker(Color clr, int capacity) {
	if (capacity > MAX_BUFF) {
		throw MaxSizeEx(MAX_BUFF);
	}
	
	this->capacity = capacity;
	this->num_chars = 0;
	this->buff = new char[this->capacity];
	this->clr = clr;
	ID = ++N_MARKER;
	std::cout << "Not default ctor: create ID = " << ID << std::endl;
}

Marker::~Marker() {
	std::cout << "~dctor: ID = " << ID << std::endl;
	delete[] this->buff;
}

//копирующий конструктор
Marker::Marker(const Marker& rhs) {
	this->capacity = rhs.capacity;
	this->clr = rhs.clr;
	this->num_chars = rhs.num_chars;
	this->buff = new char[rhs.capacity];
	for(int i = 0; i < rhs.num_chars; ++i) {
		this->buff[i] = rhs.buff[i];		
	}
	ID = ++N_MARKER;
	std::cout << "Copy ctor: create ID = " << ID << std::endl;
}

//Assignment operator
Marker& Marker::operator=(const Marker& rhs) {
	this->~Marker();
	this->num_chars = rhs.num_chars;
	this->capacity = rhs.capacity;
	this->clr = rhs.clr;
	this->buff = new char[this->capacity];
	for(int i = 0; i < this->capacity; ++i) {
		this->buff[i] = rhs.buff[i];
	}
	ID = ++N_MARKER;
	std::cout << "copy assign: create ID = " << ID << std::endl;
	return *this;
}

void Marker::Write(const char* c, int size) {
	for(int i = 0; i < size; ++i) {
		this->Write(c[i]);	
	}
}

void Marker::Write(char c) {
	if(this->num_chars >= this->capacity) {
		throw MaxSizeEx(capacity);
	}
	
	this->buff[this->num_chars++] = c;
}

void Marker::Draw() {
	std::cout << "\033[1;" << clr << "m";
	for(int i = 0; i < this->num_chars; ++i) {
		std::cout << this->buff[i];
	}
	std::cout << std::endl; 
}

void Marker::Erase() {
	this->num_chars = 0;
}
