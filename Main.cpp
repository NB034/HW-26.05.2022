#include <iostream>
#include <ctime>
#include "Student.h"
using namespace std;

void main() {
	srand(time(NULL));
	Student s("Petya", 2, 'm');
	s.addMark(5);
	s.addMark(4);
	s.setName("Vasya");
	s.setCourse(5);
	s.getInfo();
	s.setSex('f');
	s.setCourse(7);
	for (int i = 0; i < 10; i++) {
		s.addMark(rand() % 5 + 8);
	}
	s.getInfo();

	Student s2 = s;
}