#include <iostream>

/*
	How much variables will be pushed in the STACK.
	Only one - int a;
 */

void inc(int& x) {
	++x;
}

int main() {
	int a = 5;
	int& b = a;
	inc(a);
	inc(b);
	std::cout << a << b; // 7 7 
}
