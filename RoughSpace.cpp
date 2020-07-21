#include <iostream>
#include <map>
#include <string>

typedef std::map<std::string, int> maptype;

/*class database {
private:
	std::string name;
	int age;
public:

	//database():name(), age(){}

	/*void database_entry(std::string name, std::string age) {
		name = name;
		age = stoi(age);
	}*/
/*
	void set_name(std::string n) {
		name = n;
	}

	void set_age(std::string a) {
		age = stoi(a);
	}

	void Print() {
		std::cout << name << age;
	}
	
	std::map<std::string, int> get_name_age() {
		std::map<std::string, int> mapper;
		mapper[name] = age;
		return mapper;
	}
};

void get_output(std::map<std::string, int> data) {
	for (const auto& item : data) {
		std::cout << item.first << "\t" << item.second;
	}
}*/
/*
int main() {
	int no_of_inputs;
	std::cin >> no_of_inputs;
	std::map<std::string, int> data;
	//database d1;

	std::string name;
	int age;

	data = get_name_age();

	std::map<std::string, int> get_name_age(); 
	get_name_age() {
		std::map<std::string, int> mapper;
		mapper[name] = age;
		//mapper.second = age;
	}

	for (int i = 0; i <= no_of_inputs; i++) {
		std::cin >> name;
		std::cin >> age;
		//d1.database_entry(name, age);
		//d1.set_name(name);
		//d1.set_age(age);
		//d1.Print();
		//data = d1.get_name_age();
	}

	//get_output(data);
}
void map_function(std::string name, int age, maptype& the_mapper) {
	the_mapper[name] = age;
}

int main() {
	std::string name;
	int age;

	maptype mapper;

	for (int i = 0; i <= 2; i++) {
		std::cin >> name;
		std::cin >> age;
		map_function(name, age, mapper);
	}

	//maptype x = map_function();
}
*/