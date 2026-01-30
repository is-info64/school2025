#include "marker.h"

int N_MARKER = 0;

Marker::Marker() : Marker(Color::BLACK, MAX_BUFF) { }

Marker::Marker(Color clr, int capacity) : capacity_(capacity), clr_(clr), num_chars_(0) {
	if (capacity_ > MAX_BUFF) {
		throw MaxCapacityEx(MAX_BUFF);
	}
	
	this->buff_ = new char[this->capacity_];
}

Marker::~Marker() {
	delete[] this->buff_;
}

//копирующий конструктор
Marker::Marker(const Marker& rhs) : capacity_(rhs.capacity_), clr_(rhs.clr_), num_chars_(rhs.num_chars_){
	this->buff_ = new char[capacity_];
	for(int i = 0; i < num_chars_; ++i) {
		this->buff_[i] = rhs.buff_[i];		
	}
}

//Assignment operator
Marker& Marker::operator=(const Marker& rhs) {
	this->~Marker(); // ! otherwise memory leack occur
	this->num_chars_ = rhs.num_chars_;
	this->capacity_ = rhs.capacity_;
	this->clr_ = rhs.clr_;
	this->buff_ = new char[this->capacity_];
	for(int i = 0; i < this->capacity_; ++i) {
		this->buff_[i] = rhs.buff_[i];
	}
	return (*this);
}

Marker& Marker::Write(const char* c, int size) {
	
	for(int i = 0; i < size; ++i) {
		this->Write(c[i]);	
	}
	
	return (*this);
}

Marker& Marker::Write(char c) {
	if(num_chars_ == capacity_) {
		throw OverflowExc(capacity_);
	}
	
	if(c < 32 /*[space]*/ || c > 126 /*~*/) {
		throw Exception("bad char code");
	}
	
	this->buff_[this->num_chars_++] = c;
	
	return (*this);
}

void Marker::Draw() {
	std::cout << "\033[1;" << clr_ << "m";
	for(int i = 0; i < this->num_chars_; ++i) {
		std::cout << this->buff_[i];
	}
	std::cout << std::endl; 
}

void Marker::Erase() {
	this->num_chars_ = 0;
}
