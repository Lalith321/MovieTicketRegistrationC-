#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstring>

typedef std::map<std::string, std::map<int, std::map<int, std::vector<int>>>> add_screen_type;
// Way to get string as an input and tokkenize them
// Can be used when number of inputs are unknown

std::vector<std::string> data_function(std::string const& instr, const char* delimit) {
	std::vector<std::string> data;
	char* next_token1 = NULL;
	char* token = strtok_s(const_cast<char*>(instr.c_str()), delimit, &next_token1);
	while (token != nullptr)
	{
		data.push_back(std::string(token));
		token = strtok_s(nullptr, delimit, &next_token1);
	}

	return data;
}

void add_screen_function(std::string const &instr, const char* delimit, add_screen_type& add_screen_map_local) {
	std::vector<std::string> data;
	data = data_function(instr, delimit);
	/*for (auto &item : data) {
		std::cout << item;
	}*/
	//std::cout << data.size();
	
	std::map<int, std::map<int, std::vector<int>>> row_data;
	std::map<int, std::vector<int>> seats_per_row;
	std::vector<int> aisle_seats;

	for (int l = 4; l < data.size(); l++) {
		aisle_seats.push_back(stoi(data[l]));
	}

	seats_per_row[stoi(data[3])] = aisle_seats;
	row_data[stoi(data[2])] = seats_per_row;
	add_screen_map_local[data[1]] = row_data;
	/*
	//add_screen_map_local.insert(make_pair(data[1], seats_per_row));
	for (auto item : add_screen_map_local) {
		std::cout << item.first << std::endl;
		for (auto row_data : item.second) {
			std::cout << row_data.first << "\n";
			for (auto seats_per_row : row_data.second) {
				std::cout << seats_per_row.first << "\n";
				for (auto &aisle_seats : seats_per_row.second) {
					std::cout << aisle_seats << "\n";
				}
			}
		}
	}*/
}

auto reserve_seat_function(std::string const& instr, const char* delimit) {
	//std::vector reserved_seats;
	std::vector<std::string> data;
	data = data_function(instr, delimit);
	//total_reserved_seats = stoi(data[2]);
	//return total_reserved_seats;
	return data;
}

void view_screens(add_screen_type screens) {
	for (const auto& item : screens) {
		std::cout << item.first << "\n";
	}
}

int main() {
	int no_of_instructions;
	std::cin >> no_of_instructions;

	std::string command;
	std::string instruction;
	const char* delimit = " ";

	std::map<std::string, int> base_map;
	base_map["add-screen"] = 1;
	base_map["reserve-seat"] = 2;
	base_map["view-screens"] = 3;

	add_screen_type add_screen_map;
	std::vector<std::string> reserved;
	
	for (int i = 0; i < no_of_instructions+1; i++) {
		getline(std::cin, instruction);
		command = instruction.substr(0, instruction.find(" "));
		
		switch (base_map[command]) {
		case 1:
			add_screen_function(instruction, delimit, add_screen_map);
			/*for (const auto& x : screens) {
				std::cout << x.first<<"\n";
			}*/
		break;
		case 2:
			reserved = reserve_seat_function(instruction, delimit);
			for (const auto& x : add_screen_map) {
				if (reserved[1] == x.first) {
					std::cout << "passed1" << "\n";
					for (const auto& y : x.second) {
						std::cout << "passed2" << y.first << "\n";
						for (const auto& z : y.second) {
							std::cout << "passed3" << z.first << "\n";
							if (stoi(reserved[2]) <= y.first * z.first) {
								std::cout << "Booked" << "\n";
							}
							else {
								std::cout << "Not enough seats" << "\n";
							}
							break;
						}
						break;
					}
					break;
				}
				else {
					std::cout << "No such screen" << "\n";
				}
				//std::cout << x.first << "\n";
			}
			break;
		case 3:
			view_screens(add_screen_map);
			break;
		}
	}
	system("pause");
}