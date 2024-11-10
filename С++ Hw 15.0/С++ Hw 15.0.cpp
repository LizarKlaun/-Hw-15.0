#include <iostream>

using namespace std;

class Student {
	char* name;
	char* surname;
public:
	Student() {
		name = new char[8] {'B', 'o', 'r', 'y', 's', 'l', 'a', 'v'};
		surname = new char[10] {'G', 'e', 'o', 'r', 'g', 'i', 'v', 'i', 'c', 'h'};
	}

	Student(const Student& other) {
		delete[] name;
		name = nullptr;
		this->name = new char[strlen(other.name) + 1];
		for (int i = 0; i < strlen(other.name) + 1; i++)
		{
			this->name[i] = (char)other.name[i];
		}
		delete[] surname;
		surname = nullptr;
		this->surname = new char[strlen(other.surname) + 1];
		for (int i = 0; i < strlen(other.surname) + 1; i++)
		{
			this->surname[i] = (char)other.surname[i];
		}
	}

	void PrintAllInfo() {
		cout << "Name: " << name << endl;
		cout << "Surname: " << surname << endl;
	}

	const char* GetName() {
		return name;
	}

	void SetName(char* other) {
		delete[] name;
		name = nullptr;
		this->name = new char[strlen(name) + 1];
		for (int i = 0; i < strlen(name) + 1; i++)
		{
			this->name[i] = (char)name[i];
		}
	}

	void SetSurname(char* other) {
		delete[] surname;
		surname = nullptr;
		this->surname = new char[strlen(surname) + 1];
		for (int i = 0; i < strlen(surname) + 1; i++)
		{
			this->surname[i] = (char)surname[i];
		}
	}

	const char* getName() {                                                  
		return this->name;                                                   
	}                                                                        
																			 
	const char* getSurname() {                                               
		return this->surname;                                                
	}

	~Student() {
	}
};

class Group {
	Student* arrayOfStudent;
	char* groupName;
	int amountOfStudent;
public:
	Group() {
		groupName = new char[4] {'P', '3', '8', '\0'};
		amountOfStudent = 3;
		arrayOfStudent = new Student[amountOfStudent];
	}

	Group(const Group& other) {
		this->amountOfStudent = other.amountOfStudent;

		delete[] arrayOfStudent;
		arrayOfStudent = nullptr;

		this->arrayOfStudent = new Student[amountOfStudent];

		for (int i = 0; i < amountOfStudent; i++)
		{
			this->arrayOfStudent[i] = other.arrayOfStudent[i];
		}
		delete[] groupName;
		groupName = nullptr;
		this->groupName = new char[strlen(other.groupName) + 1];
		for (int i = 0; i < strlen(other.groupName) + 1; i++)
		{
			this->groupName[i] = (char)other.groupName[i];
		}
	}

	void PrintGroupInfo() {
		cout << "Group name: " << this->groupName << endl;
		for (int i = 0; i < amountOfStudent; i++) {
			cout << "Student: " << i + 1 << endl;
			cout << "Name: " << this->arrayOfStudent[i].getName() << endl;
			cout << "Surname: " << this->arrayOfStudent[i].getSurname() << endl;
		}
	}

	~Group() {
		delete[] arrayOfStudent;
		arrayOfStudent = nullptr;
		delete[] groupName;
		groupName = nullptr;
	}
};

void main() {
	Student obj;

	Student obj2 = obj;

	obj2.PrintAllInfo();

	Group obj3;

	Group obj4 = obj3;

	obj4.PrintGroupInfo();
}