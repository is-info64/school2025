#include <iostream>

class IndexOutOfRangeExc {};

template <typename T>
class Dynar {
public:
	Dynar() : Dynar(8) {
		
	}
	Dynar(const size_t& size) : size_(size), capacity_(size){
		arr_ = new T[capacity_];
	}
	//  Копирующий конструктор
	void push_back(const T& el) {
		if (size_ < capacity_) {
			arr_[size_++] = el;
			return;
		}
		T* arr_new = new T[capacity_ * 2]; 
		for(size_t i = 0; i < size_; ++i) {
			arr_new[i] = arr_[i];
		}
		
		delete[] arr_;
		arr_ = arr_new;
		arr_[size_++] = el;
		capacity_ *= 2;
	}
	
	T get(size_t index) {
		return arr_[index];
	}
	
	void set(size_t index, const T& el) {
		if(index >= size_) {
			throw new IndexOutOfRangeExc();
		}
		
		arr_[index] = el;
	}
	
	size_t size() {
		return size_;
	}
	
	T* begin(){
		return arr_;	
	}

	T* end(){
		return arr_ + size_;	
	}

private:
	T* arr_;
	size_t size_; // current
	size_t capacity_; // total count (MAX)
};

int main() {
	Dynar<int> arr(5);
	arr.set(4, 777);
	arr.push_back(888);
	for(int* it = arr.begin(); it != arr.end(); ++it) {
		std::cout << *it << "\n";
	}
	
	//Dynar<int> arr1(5);
	//Dynar<int> arr2 = arr1; // копирующий конструктор
}
