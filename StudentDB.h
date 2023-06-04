#ifndef STUDENTDB_H
#define STUDENTDB_H

#include <string>
using namespace std;

class Course {
public: 
	string courseName;
	string department;
	string semester;
	Course* next;
	Course* prev;
	string grade;

	Course() {
		courseName = " ";
		department = " ";
		semester = " ";
		grade = ' ';
		prev = NULL;
		next = NULL;
	}

	Course(string courseId, string realDepartment, string realSemester, char realGrade, Course* prevNode, Course* nextNode) {
		prev = prevNode;
		next = nextNode;
		courseName = courseId;
		department = realDepartment;
		grade = realGrade;
		semester = realSemester;
	}
};

template<typename T>
class Student {
public:
	string name;
	string dateOfBirth;
	string major;
	Student<T>* next;
	Student<T>* prev;
	Course* courseNext;

	Student() {
		name = "a";
		dateOfBirth = "b";
		major = "c";
		next = NULL;
		prev = NULL;
		courseNext = NULL;
	}

	Student(string studentName, string studentBirth, string studentMajor, Student<T>* prevNode, Student<T>* nextNode) {
		prev = prevNode;
		next = nextNode;
		name = studentName;
		dateOfBirth = studentBirth;
		major = studentMajor;
		courseNext = NULL; 
	}

	Course* createCourse(string, string, string, string);
	void InsertCourse(Course*, Student<T>*, string, string, string, string, string);
	void deleteCourse(Student<T>*, Course*&, string, string);
	void updateCourse(Student<T>*, string, string, string, string, string, string);
};

template<typename T>
class StudentDB {
public:
	Student<T> pupil;

	StudentDB() {}

	void PrintStudentandCourse(Student<T>*, Course*, string);
	void Print(Student<T>*, Course*);
	int deleteStudent(Student<T>*&, string, int&);
	void updateStudent(Student<T>*, string, string, string, string);
	int insertStudent(Student<T>*&, string, string, string, int&);
};

#endif // STUDENTDB_H
