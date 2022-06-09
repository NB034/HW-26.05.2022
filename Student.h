#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Student {
	char* name = nullptr;
	char sex;
	int course;
	int* marks = nullptr;
	int amountOfMarks = 0;
public:
	Student(const char* name = "Missing", char sex = 'm', int course = '1') {
		this->setName(name);
		this->setSex(sex);
		this->setCourse(course);
	}
	Student(const Student& student) {
		this->sex = student.sex;
		this->course = student.course;
		this->amountOfMarks = student.amountOfMarks;
		this->setName(student.name);
		this->marks = new int[this->amountOfMarks];
		for (size_t i = 0; i < this->amountOfMarks; i++) {
			this->marks[i] = student.marks[i];
		}
	}
	~Student() {
		delete[] this->name;
		delete[] this->marks;
	}

	void setName(const char* name) {
		if (this->name != nullptr) {
			delete[] this->name;
		}
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	void setCourse(int course) {
		if (course >= 1 && course <= 5) {
			this->course = course;
		}
		else {
			this->course = 1;
		}
	}
	void setSex(char sex) {
		if (sex != 'm' && sex != 'f') {
			this->sex = 'm';
			return;
		}
		this->sex = sex;
	}

	char* getName() {
		return this->name;
	}
	char getSex() {
		return this->sex;
	}
	int getCourse() {
		return this->course;
	}
	int getCountMarks() {
		return this->amountOfMarks;
	}

	void getInfo() {
		cout << "Name: " << this->name << endl;
		cout << "Sex: " << this->sex << endl;
		cout << "Course: " << this->course << endl;
		cout << "Marks:";
		for (int i = 0; i < amountOfMarks; i++) {
			cout << " " << marks[i];
		}
		cout << endl << endl;
	}

	void addMark(int mark) {
		if (this->marks == nullptr) {
			this->marks = new int[++this->amountOfMarks]{ mark };
			return;
		}
		int* marks = new int[this->amountOfMarks + 1];
		for (int i = 0; i < this->amountOfMarks; i++) {
			marks[i] = this->marks[i];
		}
		marks[this->amountOfMarks++] = mark;
		delete[] this->marks;
		this->marks = marks;
	}
	float averageMark() {
		float sum = 0;
		for (size_t i = 0; i < this->amountOfMarks; i++) {
			sum += this->marks[i];
		}
		return round(sum / this->amountOfMarks * 10) / 10;
	}
	void changeMark(int index, int mark) {
		if (index < 0 || this->amountOfMarks < index) {
			cout << "Incorrect index!" << endl << endl;
			return;
		}
		if (mark < 0) {
			mark = 0;
		}
		else if (mark > 12) {
			mark = 12;
		}
		this->marks[index] = mark;
	}
};