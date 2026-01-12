namespace School{ // в пространстве имен располагают только ОБЪЯВЛЕНАЯ (declaration)
void Sleep();
extern int num_class; // объявление без определения (ехtern - определение в другом месте будет)
} // ::School

// псевдонимы C++ ДЗ

void School::Sleep() {
	std::cout << "вызов к доске";
}

int School::num_class = 5; // определение


namespace Home{
void Sleep() {
	std::cout << "отдых";
}
}// ::Home

std::string address = "Ogorod";
/* // using - вводит имя в текущую область видимости
int main() {
	
	using School::Sleep;
	Sleep(); // School::Sleep()
	Home::Sleep();
}
*/

// using namespace - вводит все имена в текущую область видимости
using namespace School;
int a = 5; // [X] каждая программная сущность должна принадлежать пространству имен, кроме main()
int main() {
	std::cout << num_class;
	Sleep(); // School::Sleep()
	Home::address = "Prospect Stolipina";
}

































