#include <iostream>

/*
	Access to file
	* 1 - read access 	(0bit)
	* 2 - write access 	(1bit)
	* 4 - move access 	(2bit)
	* 8 - remove access (3bit)
	* 
	* [0][0][1][1] = 3
 */
/*
 MANUAL
int main() {
	int acc = 3;
	acc = acc & 0b1101; // 0b1101 only read acc = 1 
	acc = acc | 0b0100; // 0b1101 read and move acc = 5 (0101)
	if(acc & 0100) {
		std::cout << "move set 1";
	} 
}*/

/*
 ENUM
*/
enum access {
	READ = 1,
	WRITE = 2, 1101
	MOVE = 4,
	DELETE = 8
};
int main() {
	int acc = READ | WRITE; // 3
	acc &= (~WRITE); // reset WRITE 
	acc |= MOVE; 	 // set MOVE
	if(acc & MOVE) {
		std::cout << "move set 1";
	} 
}
