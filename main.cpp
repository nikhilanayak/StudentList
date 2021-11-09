#include <iostream>
#include <cstring>
#include <limits>
#include <iomanip>
#include <vector>


typedef struct{
	char first_name[256];
	char last_name[256];
	int student_id;
	float GPA;
} student;

typedef std::vector<student*> student_list;

template<typename T>
T get_type(){
	T input;
	while(!(std::cin >> input)){
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear the whole buffer
		std::cout << "Invalid input, please try again: ";
	}
	return input;
}

void add(student_list* list){
	student* s = new student();

	std::cout << "Enter a first name: ";
	std::cin >> s->first_name;

	std::cout << "Enter a last name: ";
	std::cin >> s->last_name;

	std::cout << "Enter a student id: ";
	s->student_id = get_type<int>();

	std::cout << "Enter a GPA: ";
	s->GPA = get_type<float>();
	
	list->push_back(s);
}

void del(student_list* list){
	student_list l = *list;
	std::cout << "Enter a student id: ";
	int id = get_type<int>();
	
	for(int i = 0; i < list->size(); i++){
		if(l[i]->student_id == id){
			list->erase(list->begin() + i);
			return;
		}
		std::cout << l[0]->student_id << "\n";
	}
	std::cout << "Couldn't Find That Student\n";

}

void print_student(student* s){
	std::cout << "First Name: " << s->first_name << ", Last Name: " << s->last_name << ", Student ID: " << s->student_id << ", GPA: " << std::fixed << std::setprecision(2) << s->GPA << "\n";
}

void print(student_list* list){
	for(int i = 0; i < list->size(); i++){
		student* s = list->at(i);
		print_student(s);
	}
}

int main(){
	student_list students;

	char input[10];
	while(true){
		std::cout << "Enter A Command (ADD, DELETE, PRINT, STOP): ";
		std::cin >> input;

		if(strcmp(input, "ADD") == 0){
			add(&students);
		}
		else if(strcmp(input, "DELETE") == 0){
			del(&students);
			
		}
		else if(strcmp(input, "PRINT") == 0){
			print(&students);
		}
		else if(strcmp(input, "STOP") == 0){
			for(int i = 0; i < students.size(); i++){
				delete students[i];
			}
			return 0;
		}

	}

	add(&students);
	print(&students);

}
