#ifndef STUDENTDB_H
#define STUDENTDB_H
#include<string>
using namespace std;



class Course
 {
public: 
	string courseName;
	string Department;
	string Semester;
	Course *next;
	Course *prev;
	string Grade;

	Course(){
	courseName = " "; Department = " "; Semester = " "; 

	 Grade = ' '; prev=NULL; next=NULL;
}
Course(string courseId, string realDepartment, string realSemester, char realGrade,Course *prevNode, Course *nextNode){

prev = prevNode; next = nextNode; courseName = courseId; Department = realDepartment; Grade = realGrade; Semester = realSemester;

}
};


template<typename T>
class Student {
	public:

		string name;
		string DateOfBirth;
		string major;
		Student<T> *next;
		Student<T> *prev;
		Course *courseNext;
		//Default Constructor
		Student() {
			name = "a"; DateOfBirth = "b"; major = "c"; next = NULL; prev = NULL; courseNext=NULL;
		}
		//
		//Initializing variables
		
		Student(string studentName, string studentBirth, string studentMajor, Student<T> *prevNode, Student<T> *nextNode) {
			prev = prevNode; next = nextNode, name = studentName; DateOfBirth = studentBirth;  major = studentMajor;
			courseNext=NULL; 
		}
	Course* createCourse(string, string, string, string );
void InsertCourse(Course*, Student<T>*, string, string , string , string, string);
void deleteCourse(Student<T>*, Course*&, string, string);
void updateCourse(Student<T>*, string,string, string , string,string, string);
		
	};



template <typename T>

class StudentDB {
public:


	Student <T> pupil;
	StudentDB() {
		
	}
	//template<typename T>
	//Creating a student record

	//template<typename T>
	//void Print(Student<T>) {}
	void PrintStudentandCourse(Student<T>*,Course*, string);
	void Print(Student<T> *Pupil,Course *Class);
	int deleteStudent(Student<T> *&, string,int&);
	void updateStudent(Student<T>*, string, string, string, string);
	int  insertStudent(Student<T> *&, string, string , string, int&);

};
















#endif   // StudentDB_CLASS
