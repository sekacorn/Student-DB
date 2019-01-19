#include<iostream>
#include "StudentDB.h"
#include <string>
using namespace std;


template<typename T>
Student<T>* createStudent(string studentName, string studentBirth, string studentMajor) {
	Student<T> *X = new Student<T>();
	//Initializing variables
	X->name = studentName; X->DateOfBirth = studentBirth, X->major = studentMajor  ;
	return X;

}
template<typename T>
int  StudentDB<T>::insertStudent(Student<T> *&Pupil2, string studentName, string studentBirth, string studentMajor, int &a) {
	Student<T> *newStudent = createStudent<T>(studentName, studentBirth, studentMajor);
	
	
	
	
	
	if (Pupil2 == NULL ) {

		

	newStudent->next=Pupil2;
	Pupil2=newStudent;
	a++;
	}
	
	else {
		Student<T> *Current = Pupil2;
		
		//Cycle through the linkedlists
		while (Current->next != NULL &&Current->name < newStudent->name) {
			Current = Current->next;

		}
		newStudent->next=Current->next;
          	newStudent->prev=Current;
            	
            	Current->next=newStudent;
		a++;
		if(newStudent->next!=NULL){
		newStudent->next->prev=newStudent;

}
		
	}
	return a;
	
}
template<typename T>
Course* Student<T>::createCourse(string courseId, string realDepartment, string realSemester, string realGrade) {

Course *Class = new Course();// Creates a new Course
Class->courseName = courseId; Class->Department = realDepartment; Class->Semester = realSemester; Class->Grade=realGrade;



//Initializes Class
return Class;
}

template<typename T>
void Student<T>::InsertCourse(Course *Class, Student<T> *Pupil, string courseId, string realDepartment, string realSemester, string TargetName, string realGrade) {

Course *newClass = createCourse(courseId, realDepartment, realSemester, realGrade) ;
Course*Current = Class;








while(Pupil!=NULL&&Pupil->name!=TargetName){
	
	Pupil=Pupil->next;
}

			//Inserts the first one

			if(Pupil->courseNext==NULL) {
		
			
			newClass->next=Pupil->courseNext;
			Pupil->courseNext=newClass;
			
			cout<<" Course  added for: "<<Pupil->name<<endl;
			

			}
		
	

		// Inserts between
		else if(Pupil->courseNext!=NULL){
			
		
		
			Course *Current;
			
			newClass->next=Pupil->courseNext->next;
		  	newClass->prev=Pupil->courseNext;
		    	Pupil->courseNext->next=newClass;
			cout<<" Course  added for: "<<Pupil->name<<endl;
			if(newClass->next!=NULL){
			newClass->next->prev=newClass;
			

			}

		    
		}
	
	


}
template<typename T>
void Student<T>::updateCourse(Student<T>*Pupil, string TargetName, string TargetCourse, string CourseId, string realDepartment, string realSemester , string realGrade){

if(Pupil==NULL){
cout<<"Database is Empty"<<endl;
return;
}
bool item = false;
 	while(Pupil->name!=TargetName){
	cout<<"A1 "<<Pupil->name<<endl;
	Pupil=Pupil->next;}
	
	

	Course* Z=Pupil->courseNext;
	Course* P=Pupil->courseNext;
	Course *tmp=Pupil->courseNext;
	//deletes the first one
	if (Z->courseName == TargetCourse) {
			
			Z->courseName=CourseId;
				Z->Department=realDepartment;
				Z->Semester=realSemester;
				Z->Grade=realGrade;
			return;

		}

		while (P->next!= NULL) {
			//Deletes  linkedlist  in between
			if (P->courseName == TargetCourse) {
				P->courseName=CourseId;
				P->Department=realDepartment;
				P->Semester=realSemester;
				P->Grade=realGrade;
				
				return;


			}
			P = P->next;

		}
		//Deletes Last
		if (P->courseName == TargetCourse&&P->next==NULL) {
			P->courseName=CourseId;
				P->Department=realDepartment;
				P->Semester=realSemester;
				P->Grade=realGrade;
			
			return;

		}

	   
    cout<<"Course Not found"<<endl;
	
}

template<typename T>
void StudentDB<T>::updateStudent(Student<T>*Pupil, string TargetName,string studentName,string StudentBirth, string StudentMajor){
	if(Pupil==NULL){
cout<<"Database is Empty"<<endl;
return;
}		//Deletes first one
	if (Pupil->name == TargetName) {
				
				Pupil->name=studentName;
			Pupil->DateOfBirth=StudentBirth;
			Pupil->major=StudentMajor;
				return;

			}


	while(Pupil->next!=NULL){
	
			//Changes Linked list in between
			if(Pupil->name==TargetName){
			
			Pupil->name=studentName;
			Pupil->DateOfBirth=StudentBirth;
			Pupil->major=StudentMajor;
			return;
			}
	Pupil=Pupil->next;
	}
	//Changes last linkedlist
	if (Pupil->name == TargetName&&Pupil->next==NULL) {
				Pupil->name=studentName;
			Pupil->DateOfBirth=StudentBirth;
			Pupil->major=StudentMajor;
		
				cout<<"D"<<endl;
				return;

			}
	cout<<"Student was not found"<<endl;
	



}
template<typename T>
void StudentDB<T>::Print(Student<T> *Pupil,Course *Class) {
if(Pupil==NULL){
	cout<<"Database Empty"<<endl;
	return;
	}	
	Course *tmp;
	
	while (Pupil!= NULL) {
		
	cout<<"==========================================="<<endl;
		cout<<"###########################################"<<endl;
		cout<<"==========================================="<<endl;
		cout << "Name: " << Pupil->name << endl;
		cout << "Date Of Birth: " << Pupil->DateOfBirth << endl;
		cout << "Major:" << Pupil->major << endl;
		cout << Pupil->prev << endl;
		cout << Pupil->next << endl;
		cout<<Pupil->courseNext<<endl;
		
	tmp = Pupil->courseNext;
cout<<endl;
			while(tmp !=NULL){
		cout<<"----------------------------------------------"<<endl;
				cout<<"Course Name: "<<tmp->courseName<<endl;
				cout<<"Department: "<<tmp->Department<<endl;
				cout<<"Semester: "<<tmp->Semester<<endl;
				cout<<"Prev "<<tmp->prev<<endl;
				cout<<"next "<<tmp->next<<endl;
		cout<<"-----------------------------------------------"<<endl;
				tmp = tmp->next;
			}
				
				cout<<endl;
			cout<<endl;
		
		Pupil = Pupil->next;
			cout<<endl;
			cout<<endl;
	}
}
template<typename T>
void StudentDB<T>::PrintStudentandCourse(Student<T> *Pupil,Course *Class, string Targetname) {
if(Pupil==NULL){
	cout<<"Database Empty"<<endl;
	return;
	}
	Course *tmp;

	while (Pupil  != NULL) {
		if(Pupil->name==Targetname){
			cout << "Name: " << Pupil->name << endl;
			cout << "Date Of Birth: " << Pupil->DateOfBirth << endl;
			cout << "Major:" << Pupil->major << endl;
			cout << Pupil->prev << endl;
			cout << Pupil->next << endl;
			cout<<endl;
		
			tmp = Pupil->courseNext;
			while(tmp !=NULL){
				cout<<"Course Name: "<<tmp->courseName<<endl;
				cout<<"Department: "<<tmp->Department<<endl;
				cout<<"Semester: "<<tmp->Semester<<endl;
				tmp = tmp->next;
			}
		
				cout<<endl;
				cout<<endl;
		return;
		}
		Pupil = Pupil->next;

	}cout<<"Student Not Found"<<endl;
}

template<typename T>
int StudentDB<T>::deleteStudent(Student<T> *&Pupil, string Targetname, int& a) {
	if(Pupil==NULL){
	cout<<"Database Empty"<<endl;
	return 0;
	}	
	Student<T> *temp_next = Pupil;// current will be point to the current node while prev point to null
	Student<T> *temp_prev = Pupil;
	Student<T> *P = Pupil;

	bool item = false;
	

	

	
	if (Pupil->name == Targetname) {
		//Deletes if its first element
		Pupil = Pupil->next;
		Pupil->prev = NULL;
		a--;
		delete P;
		if(Pupil==NULL){
	cout<<"Database Empty"<<endl;
	return 0;
	}
		cout<<"Student Deleted"<<endl;
		item = true;
		
		return a;

	}

	while (P->next!= NULL && !item) {
		//Deletes if the linklist is in between
		if (P->name == Targetname) {
			//if (temp->prev == NULL) {
			cout << "Found" << endl;
			temp_next = P->next;
			temp_prev = P->prev;
			temp_next->prev = temp_prev;
			temp_prev->next = temp_next;
			a--;
				delete P;
			if(Pupil==NULL){
		cout<<"Database Empty"<<endl;
		return 0;
	}
			cout<<"Student Deleted"<<endl;
			
			return a;
			

		}
		P = P->next;

	}
	//Deletes Last
	if (P->name == Targetname&&P->next==NULL) {
		temp_prev = P->prev;
		temp_prev->next = NULL;
		//temp_prev->prev
		a--;
		delete P;
		if(Pupil==NULL){
	cout<<"Database Empty"<<endl;
	return 0;
	}
		item = true;
			cout<<"Student Deleted"<<endl;
		return a;

	}

		cout << "The student was not found" << endl;
	
}




template<typename T>
void Student<T>::deleteCourse(Student<T> *Pupil, Course *&Class, string Targetname, string TargetCourse) {
	if(Pupil==NULL){
	cout<<"Database Empty"<<endl;
	return;
	}
	bool item = false;
	



while(Pupil->name!=Targetname){
Pupil=Pupil->next;
}
	Course *temp_next = Pupil->courseNext;
	Course *temp_prev = Pupil->courseNext;
	Course *P = Pupil->courseNext;
	Course *Z = Pupil->courseNext;
	
	if (Z->courseName == TargetCourse) {
		//Deletes if its first element
		cout<<"Course Found"<<endl;
		Z =Z->next;
		Z->prev = NULL;
		delete P;
		item = true;
		cout << "Course deleted First" << endl;
		return;

	}

	while (P->next!= NULL && !item) {
		//Deletes if the linklist is in between
		if (P->courseName == TargetCourse) {
			
			cout << "Course Found" << endl;
			temp_next = P->next;
			temp_prev = P->prev;
			temp_next->prev = temp_prev;
			temp_prev->next = temp_next;
			delete P;
			cout<<"Course Deleted"<<endl;
			return;


		}
		P = P->next;

	}
	//Deletes Last
	if (P->courseName == TargetCourse&&P->next==NULL) {
		temp_prev = P->prev;
		temp_prev->next = NULL;
		delete P;
		cout<<"Course Deleted"<<endl;
		item = true;
			cout << "Course Deleted Last" << endl;
		return;

	}
	if (item = false) {
		cout << "The course was not found" << endl;
	}
}
template<typename T>
void PrintCourse(Course *Class) {

	while (Class  != NULL) {
		cout << "Course: " << Class->courseName << endl;
		cout << "Department: " << Class->Department << endl;
		cout << "Semester:" << Class->Semester << endl;
		cout << Class->prev << endl;
		cout << Class->next << endl;
		Class = Class->next;
	}
}
template<typename T>
int PrintMenu(Student<T> *Pupil){
int answer=0;
cout<<endl;
if(Pupil==NULL){
cout<<"Database Empty"<<endl;
return 0;
}
cout<<"+++++++++++++++++++++++++++++++++++++"<<endl;
cout<<endl;
cout<<"Please Enter one of the following Choices"<<endl;
cout<<"Enter '1'to Print all the student records"<<endl;\
cout<<"Enter '2' to search student by name"<<endl;
cout<<"Enter '3' to update a student's course"<<endl;
cout<<"Enter '4' to update a student record"<<endl;
cout<<"Enter '5' to Add a student"<<endl;
cout<<"Enter '6' to Add a course for Student"<<endl;
cout<<"Enter '7' to delete a Student"<<endl;
cout<<"Enter '8' to delete a course for a student"<<endl;
cout<<"Enter '9' to Quit"<<endl;
cout<<endl;
cout<<"++++++++++++++++++++++++++++++++++++++++"<<endl;
cout<<endl;
cin>>answer;

while(answer<1||answer>9){
cout<<endl;
cout<<"+++++++++++++++++++++++++++++++++++++"<<endl;
cout<<endl;
cout<<"Error "<<endl;
cout<<"Please Re- enter one of the following Choices"<<endl;
cout<<"Enter '1'to Print all the student records"<<endl;\
cout<<"Enter '2' to search student by name"<<endl;
cout<<"Enter '3' to update a student's course"<<endl;
cout<<"Enter '4' to update a student record"<<endl;
cout<<"Enter '5' to Add a student"<<endl;
cout<<"Enter '6' to Add a course for Student"<<endl;
cout<<"Enter '7' to delete a Student"<<endl;
cout<<"Enter '8' to delete a course for a student"<<endl;

cout<<"Enter '9' to Quit"<<endl;
cout<<endl;
cout<<"++++++++++++++++++++++++++++++++++++++++"<<endl;
cout<<endl;
cin>>answer;
cin.clear();
cin.ignore(256,'\n');
}
return answer;


}
