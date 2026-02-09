// HAPPY RABBIT game NO abstract
#include <iostream>
#include <iostream>

class Animal {
public:
	virtual void walk() = 0;
	virtual void say() = 0;
};

class Rabbit : public Animal {
public:	
	void walk() {
		std::cout << "jump\n";
	}
	void say() {
		std::cout << "frfrfr\n";
	}
};

class Bird : public Animal { // тоже abstract, т.к. virtual say() = 0
public:
	void walk() override {
		std::cout << "fly\n";
	}
};

class Sparrow : public Bird {
public:	
	void say() {
		std::cout << "chirp\n";
	}
};

class Pigeon : public Bird {
public:	
	void say() {
		std::cout << "kurlyk\n";
	}
};
enum Anims{
	RABBIT, SPARROW, PIGEON
};
int main() {
	std::cout << "Choose character:\n\t1. Rabbit\n\t2. Sparrow\n\t3. Pigeon\nChooice: ";
	int choice;
	std::cin >> choice;
	Animal* anim;
	switch (choice) {
		case Anims::RABBIT:
			anim = new Rabbit();
		break;
		case Anims::SPARROW:
			anim = new Sparrow();
		break;
		case Anims::PIGEON:
			anim = new Pigeon();
		break;
		default:
			std::cout << "Stupid user\n";
			return 1;
		break;
	}
	
	while(1) {
		(*anim).walk();
		anim->say();
		anim->walk();
	}
} 

// HAPPY ANIMAL game NO abstract
/*
#include <iostream>
class Rabbit {
public:	
	void walk() {
		std::cout << "jump\n";
	}
	void say() {
		std::cout << "frfrfr\n";
	}
};

class Bird {
public:
	void walk() {
		std::cout << "fly\n";
	}
	
	// virtual void say() = 0;
};

class Sparrow : public Bird {
public:	
	void say() {
		std::cout << "chirp\n";
	}
};

class Pigeon : public Bird {
public:	
	void say() {
		std::cout << "kurlyk\n";
	}
};

int main() {
	std::cout << "Choose character:\n\t1. Rabbit\n\t2. Sparrow\n\t3. Pigeon\nChooice: ";
	int choice;
	std::cin >> choice;
	
	if(choice == 1) {
		while(1) {
			Rabbit rb;
			rb.walk();
			rb.say();
		}
	}
	else if(choice == 2) {
		while(1) {
			Sparrow sp;
			sp.walk();
			sp.say();
		}
	} 
	else if(choice == 3) {
		while(1) {
			Pigeon pig;
			pig.walk();
			pig.say();
		}
	}
	else {
		std::cout << "Stupid user\n";
	}
} 
*/
