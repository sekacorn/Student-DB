#include<iostream>
#include "StudentDB.h"
#include"StudentDB.cpp"
#include<string>
using namespace std;


int main() {
	int choice=0;
	string studentName=" ";
	string studentBirth=" ";
	string studentMajor=" ";
	Student<int> *nextNode = NULL;
	Student<int> *prevNode = NULL;
	Student<string> *Pupil3=NULL;
	string Targetname = " ";
	Course *Class=NULL;
	Course *next=NULL;
	Course *prev=NULL;
	Course *courseNext=NULL;
	char Terminate = ' ';
	int a = 0;
	string courseId=" ";
	string realDepartment=" ";
	string realSemester=" "; 
	string TargetCourse=" ";
	string realGrade=" ";
	StudentDB<string> *Mylist;
	Student<string> *MyList2;
	string choice1=" "; string choice2=" "; string choice3=" "; string choice4= " ";
	string choice5=" ";
	bool bob=false;
	int numOfstudent=0;

		
		//Pre-fills name  date of birth major and courses for the database
		studentName = "john";
		studentBirth = "05-12-1992";
		studentMajor = "Math";
		numOfstudent=Mylist->insertStudent( Pupil3, studentName,  studentBirth, studentMajor,numOfstudent);

		studentName = "Tom";
		studentBirth = "05-12-1992";
		studentMajor = "Math";
		numOfstudent=Mylist->insertStudent(Pupil3, studentName, studentBirth, studentMajor,numOfstudent);

		studentName = "Jillian";
		studentBirth = "05-12-1992";
		studentMajor = "Math";
		numOfstudent=Mylist->insertStudent(Pupil3, studentName, studentBirth, studentMajor,numOfstudent);

		studentName = "Adam";
		studentBirth = "05-12-1992";
		studentMajor = "Math";
		numOfstudent=Mylist->insertStudent(Pupil3, studentName, studentBirth, studentMajor,numOfstudent);

		courseId="COSC2";
		realDepartment="ComputerScience";
		realSemester="Fall"; 
		Targetname="Tom";
		
		MyList2->InsertCourse(Class,Pupil3, courseId, realDepartment,  realSemester, Targetname, realGrade);
		

		courseId="ENG";
		realDepartment="ComputerScience";
		realSemester="Fall"; 
		Targetname= "Adam";
	
		
		MyList2->InsertCourse(Class,Pupil3, courseId, realDepartment,  realSemester, Targetname, realGrade);
		
		courseId="BIO";
		realDepartment="ComputerScience";
		realSemester="Fall"; 
		Targetname= "Jillian";

		MyList2->InsertCourse(Class,Pupil3, courseId, realDepartment,  realSemester, Targetname, realGrade);
		
		courseId="MATH";
		realDepartment="ComputerScience";
		realSemester="Fall"; 
		Targetname= "Tom";
		MyList2->InsertCourse(Class,Pupil3, courseId, realDepartment,  realSemester, Targetname, realGrade);
		courseId="PSYC";
		realDepartment="ComputerScience";
		realSemester="Fall"; 
		Targetname= "Tom";
		MyList2->InsertCourse(Class,Pupil3, courseId, realDepartment,  realSemester, Targetname, realGrade);

while(bob!=true){
 		choice= PrintMenu(Pupil3);
	if (choice==1){//Prints the student

		Mylist->Print(Pupil3,Class);
	}
	else if(choice==2){//Searches for student
	 	cout<<"Please enter the student's name"<<endl;
		cin.ignore(256,'\n');
		getline(cin,Targetname);
		Mylist->PrintStudentandCourse(Pupil3,Class, Targetname);

	}

	else if(choice==3)//Updates Student courses
	{

		cout<<"Please Enter a course you would like to change"<<endl;
		cin.ignore(256,'\n');
		getline(cin,TargetCourse);
		cout<<"Please enter a student whose course you want to change"<<endl;
		getline(cin,Targetname);
		
	
		cout<<"Please enter the new name for the course"<<endl;
		getline(cin,courseId);	
	
		cout<<"Please enter the Department of the course"<<endl;
		getline(cin,realDepartment);
		cout<<"Please enter semester"<<endl;
		getline(cin,realSemester);
		
		
		cout<<"Please enter Grade for the course"<<endl;
		getline(cin,realGrade);

		cout<<"Are you sure you want to change the course typ 'y' for yes or 'n' for no"<<endl;
		getline(cin,choice4);
		if(choice4=="Y"||choice4=="y"){
		//Call update
		MyList2->updateCourse(Pupil3, Targetname,  TargetCourse,courseId, realDepartment, realSemester, realGrade);
		}

	}
	
	else if(choice==4){//Updates Student record
		
		
		cout<<"Please enter the student you would want to update"<<endl;
	 	cin.ignore(256,'\n');
		getline(cin,Targetname);
		cout<<"Please Enter new name of Student"<<endl;
		
		getline(cin,studentName);
		
		
	
		
		cout<<"StudentName "<<studentName<<endl;		
		cout<<"Please Enter student Date of Birth separated by  e.g MM-DD-YYYY"<<endl;
		
		getline(cin,studentBirth);
		cout<<"Please enter the student's Major"<<endl;
		
		getline(cin,studentMajor);
		cout<<"Are you sure you want changes? enter a 'y' for yes or 'n' for no"<<endl;
		getline(cin,choice2);
	   	 if(choice2=="Y"||choice2=="y"){
		//call update
		Mylist->updateStudent(Pupil3, Targetname,studentName,studentBirth,studentMajor);
		}
	}

	

	else if(choice==5){ //Adds a Student

		
		cout<<"Please Enter name of new Student"<<endl;
		cin.ignore(256,'\n');
		getline(cin,studentName);
		cout<<"Please Enter student Date of Birth separated by  e.g MM-DD-YYYY"<<endl;
		getline(cin,studentBirth);
		cout<<"Please enter the student's Major"<<endl;
		getline(cin,studentMajor);
		cout<<"Are you sure you want add this student? enter a 'y' for yes or 'n' for no"<<endl;
		getline(cin,choice5);
	   	 if(choice5=="Y"||choice5=="y"){
		//call insert student
		numOfstudent=Mylist->insertStudent(Pupil3,  studentName,  studentBirth, studentMajor, numOfstudent);
			}
	}

	
	else if(choice==6){//Adds a course to student
			choice1=' ';
			choice3=' ';
		

			cout<<"Please enter a student whose course you want to add"<<endl;
			//cin.ignore(256,'\n');
			getline(cin,Targetname);
		
			cout<<"Please enter the  name for the course"<<endl;
			getline(cin,courseId);	
		
			cout<<"Please enter the Department of the course"<<endl;
			getline(cin,realDepartment);
			cout<<"Please enter semester"<<endl;
			getline(cin,realSemester);
			cout<<"Please enter Grade for the course"<<endl;
			getline(cin,realGrade);

			cout<<"Are you sure you want to change the course"<<endl;
			getline(cin,choice1);
			if(choice1=="Y"||choice1=="y"){
			//Call Insert course
	MyList2->InsertCourse(Class, Pupil3, courseId, realDepartment,  realSemester,  Targetname,  
realGrade);
			}


	}
	
	else if (choice==7){//Deletes a student
	
		choice1=" ";
		cout<<"Please Enter Name of student you want o delete"<<endl;
		cin.ignore(256,'\n');
		getline(cin,Targetname);
		cout<<"Are you sure you want to change the course enter a 'y' for yes or 'n' for no"<<endl;
			getline(cin,choice1);
			if(choice1=="Y"||choice1=="y"){
			//Call Delete student
			numOfstudent=Mylist->deleteStudent(Pupil3, Targetname,numOfstudent);
			}
	}
	
	else if(choice ==8){//deletes a course for a student
		choice3= " ";
		
		cout<<"Please Enter the Name of student you want to delete a course from"<<endl;
		cin.ignore(256,'\n');
		getline(cin,Targetname);
		cout<<"please Enter a course you want to delete"<<endl;
		getline(cin,TargetCourse);
		cout<<"Are you sure you want to delete enter a 'y' and  'n' for no"<<endl;
		getline(cin,choice3);
		if(choice3=="Y"||choice3=="y"){
			//Call Delete Course
		MyList2->deleteCourse(Pupil3, Class,  Targetname,  TargetCourse);
			}
	}	
	

	else if(choice==9){
		bob=true;
	 cout<<"Bye!"<<endl;

	}
		cout<<"The number of students in this data base is "<<numOfstudent<<endl;	
}
		
	
	MyList2->deleteCourse(Pupil3, Class, Targetname, TargetCourse);
	Mylist->Print(Pupil3,Class);
	
	//PrintCourse(Class);
	








}
