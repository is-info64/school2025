#include <iostream>

#define INC plus_1

void plus_1(int* a) {
	(*a)++;
}

int main() {
	int a = 5;
	INC(&a);
	std::cout << a;
}

































