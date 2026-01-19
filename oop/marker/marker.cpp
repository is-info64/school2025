#include "marker.h"
	
Marker::Marker(Color clr, int capacity) {
	this->capacity = capacity;
	this->num_chars = 0;
	std::cout << this->capacity;
	this->buff = new char[this->capacity];
	this->clr = clr;
}

Marker::Marker() {
	this->capacity = MAX_BUFF;
	this->num_chars = 0;
	std::cout << this->capacity;
	this->buff = new char[this->capacity];
	this->clr = Color::GREEN;
}

//копирующий конструктор
Marker::Marker(const Marker& rhs) {
	this->capacity = rhs.capacity;
	this->clr = rhs.clr;
	this->num_chars = 0;
	this->buff = new char[this->capacity];
}

//Assignment operator
Marker& Marker::operator=(const Marker& rhs) {
	this->num_chars = rhs.num_chars;
	this->capacity = rhs.capacity;
	this->clr = rhs.clr;
	delete[] this->buff;
	this->buff = new char[this->capacity];
	for(int i = 0; i < this->capacity; ++i) {
		this->buff[i] = rhs.buff[i];
	}
	
	return *this;
}

bool Marker::Write(const char* c, int size) {
	for(int i = 0; i < size; ++i) {
		if(!this->Write(c[i])) {
			return false;
		}
	}
	return true;
}

bool Marker::Write(char c) {
	if(this->num_chars >= this->capacity) {
		return false;
	}
	
	this->buff[this->num_chars++] = c;
	return true;
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













