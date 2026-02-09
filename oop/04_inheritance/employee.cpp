#include <iostream>
#include <string>

class Employee {
public:
	Employee() {}
	Employee(const std::string& name, const std::string& dept) : name_(name), dept_(dept) {	}
	
	void print(const std::string& var = "", const std::string& prefix = "") const{
		std::cout << prefix << "Employee[" << var << "]\n\tname: " << this->name_ << "\n\tdept: " << dept_ << "\n";
	}
	
	void change_dept(const std::string& dept) {
		this->dept_ = dept;
	}
	
protected:
	std::string name_;
	std::string dept_;
};


class Manager : public Employee {
	static const int MAX_GROUP = 100;
public:
	Manager(const std::string& name, const std::string& dept, int level) 
		: Employee(name, dept), level_(level), group_len_(0) { } 
		
	void print(const std::string& var = "") {
		Employee::print(var);
		std::cout << "\tManager\n\t\tlevel: " << level_ << "\n\t\t-----GROUP-----\n";
		for(int i = 0; i < group_len_; ++i) {
			group_[i].print(var + " group", "\t\t");
		}
		std::cout << "\n\t\t==============\n";
	}
	
	int get_level() {
		return this->level_;
	}
	
	void set_level(int level) {
		if(level < 0) {
			// error must be occure here
		}
		
		this->level_ = level;
	}
	
	Manager& add_employee(const Employee& e) {
		this->group_[this->group_len_++] = e;
		return (*this);
	}
private:
	Employee group_[MAX_GROUP];
	int level_;
	
	int group_len_;
};

int main() {
	Employee e1("Vasya", "kassy");
	Employee e2("Petya", "zal");
	Employee e3("Sidr", "zal");
	
	Manager m1("Jone", "zal", 3);
	m1.add_employee(e2).add_employee(e3);
	
	m1.change_dept("shop");
	//m1.name_ = "Ivan"; // error, protected:
	m1.print("m1");
}





















