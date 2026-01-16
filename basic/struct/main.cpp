#include <iostream>

struct Pupil {
	int age;
	double mark;
};

int main() {
	Pupil p {15, 3.5};
	//p.age = 15;
	//p.mark = 3.5;
	std::cout << p.age << "\t" << p.mark << "\n";
}

































