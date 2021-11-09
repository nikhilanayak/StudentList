/*
Written By: Nikhil Nayak
Date: 10/20/21
Description: A program written in c++ that serves as an interface and database for students designed to keep track of first name, last name, student id, and GPA.
Commands: ADD, QUIT, DELETE, PRINT
*/

#include <limits>
#include <cstring>
#include <iostream>
#include <cstring>
#include <limits>
#include <iomanip>
#include <vector>
#include <algorithm>


typedef struct{ // stores data for a single student
	char first_name[256];
	char last_name[256];
	int student_id;
	float GPA;
} student;

typedef std::vector<student*> student_list;

template<typename T>
T get_type(){ // gets input of a type, ignoring all other types
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

void del(student_list* list){ // remove a student from the list
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

void print(student_list* list){ // print all of the students
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

		// parse input
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


}
