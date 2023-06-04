#include<iostream>
#include<string>
using namespace std;

template<typename T>
struct Course {
    string courseName;
    string Department;
    string Semester;
    string Grade;
    Course<T> *prev;
    Course<T> *next;
};

template<typename T>
struct Student {
    string name;
    string DateOfBirth;
    string major;
    Course<T> *courseNext;
    Student<T> *prev;
    Student<T> *next;
};

template<typename T>
class StudentDB {
public:
    Student<T> *Pupil;
    
    StudentDB() {
        Pupil = nullptr;
    }
    
    Student<T>* createStudent(string studentName, string studentBirth, string studentMajor) {
        Student<T> *X = new Student<T>();
        X->name = studentName;
        X->DateOfBirth = studentBirth;
        X->major = studentMajor;
        X->prev = nullptr;
        X->next = nullptr;
        X->courseNext = nullptr;
        return X;
    }
    
    int insertStudent(Student<T> *&Pupil2, string studentName, string studentBirth, string studentMajor, int &a) {
        Student<T> *newStudent = createStudent(studentName, studentBirth, studentMajor);
        
        if (Pupil2 == nullptr) {
            newStudent->next = Pupil2;
            Pupil2 = newStudent;
            a++;
        } else {
            Student<T> *Current = Pupil2;
            
            // Cycle through the linked list
            while (Current->next != nullptr && Current->name < newStudent->name) {
                Current = Current->next;
            }
            
            newStudent->next = Current->next;
            newStudent->prev = Current;
            
            if (newStudent->next != nullptr) {
                newStudent->next->prev = newStudent;
            }
            
            Current->next = newStudent;
            a++;
        }
        
        return a;
    }
    
    void updateStudent(Student<T> *Pupil, string TargetName, string studentName, string studentBirth, string studentMajor) {
        if (Pupil == nullptr) {
            cout << "Database is Empty" << endl;
            return;
        }
        
        while (Pupil != nullptr) {
            if (Pupil->name == TargetName) {
                Pupil->name = studentName;
                Pupil->DateOfBirth = studentBirth;
                Pupil->major = studentMajor;
                return;
            }
            Pupil = Pupil->next;
        }
        
        cout << "Student was not found" << endl;
    }
    
    Here's the fixed version of the C++ code with corrected errors:

```cpp
template<typename T>
int StudentDB<T>::deleteStudent(Student<T> *&Pupil, string Targetname, int& a) {
    if(Pupil == nullptr) {
        cout << "Database Empty" << endl;
        return 0;
    }

    Student<T> *temp_next = Pupil;
    Student<T> *temp_prev = Pupil;
    Student<T> *P = Pupil;
    bool item = false;

    if(Pupil->name == Targetname) {
        // Deletes if it's the first element
        Pupil = Pupil->next;
        Pupil->prev = nullptr;
        a--;
        delete P;
        if(Pupil == nullptr) {
            cout << "Database Empty" << endl;
            return 0;
        }
        cout << "Student Deleted" << endl;
        item = true;
        return a;
    }

    while(P->next != nullptr && !item) {
        // Deletes if the linked list is in between
        if(P->name == Targetname) {
            cout << "Found" << endl;
            temp_next = P->next;
            temp_prev = P->prev;
            temp_next->prev = temp_prev;
            temp_prev->next = temp_next;
            a--;
            delete P;
            if(Pupil == nullptr) {
                cout << "Database Empty" << endl;
                return 0;
            }
            cout << "Student Deleted" << endl;
            return a;
        }
        P = P->next;
    }

    // Deletes Last
    if(P->name == Targetname && P->next == nullptr) {
        temp_prev = P->prev;
        temp_prev->next = nullptr;
        a--;
        delete P;
        if(Pupil == nullptr) {
            cout << "Database Empty" << endl;
            return 0;
        }
        item = true;
        cout << "Student Deleted" << endl;
        return a;
    }

    cout << "The student was not found" << endl;
    return a;
}

template<typename T>
void Student<T>::deleteCourse(Student<T> *Pupil, Course *&Class, string Targetname, string TargetCourse) {
    if(Pupil == nullptr) {
        cout << "Database Empty" << endl;
        return;
    }
    bool item = false;

    while(Pupil->name != Targetname) {
        Pupil = Pupil->next;
    }

    Course *temp_next = Pupil->courseNext;
    Course *temp_prev = Pupil->courseNext;
    Course *P = Pupil->courseNext;
    Course *Z = Pupil->courseNext;

    if(Z->courseName == TargetCourse) {
        // Deletes if it's the first element
        cout << "Course Found" << endl;
        Z = Z->next;
        Z->prev = nullptr;
        delete P;
        item = true;
        cout << "Course deleted First" << endl;
        return;
    }

    while(P->next != nullptr && !item) {
        // Deletes if the linked list is in between
        if(P->courseName == TargetCourse) {
            cout << "Course Found" << endl;
            temp_next = P->next;
            temp_prev = P->prev;
            temp_next->prev = temp_prev;
            temp_prev->next = temp_next;
            delete P;
            cout << "Course Deleted" << endl;
            return;
        }
        P = P->next;
    }

    // Deletes Last
    if(P->courseName == TargetCourse && P->next == nullptr) {
        temp_prev

 = P->prev;
        temp_prev->next = nullptr;
        delete P;
        cout << "Course Deleted" << endl;
        item = true;
        cout << "Course Deleted Last" << endl;
        return;
    }

    if(!item) {
        cout << "The course was not found" << endl;
    }
}

template<typename T>
void PrintCourse(Course *Class) {
    while(Class != nullptr) {
        cout << "Course: " << Class->courseName << endl;
        cout << "Department: " << Class->Department << endl;
        cout << "Semester: " << Class->Semester << endl;
        cout << Class->prev << endl;
        cout << Class->next << endl;
        Class = Class->next;
    }
}

template<typename T>
int PrintMenu(Student<T> *Pupil) {
    int answer = 0;
    cout << endl;
    if(Pupil == nullptr) {
        cout << "Database Empty" << endl;
        return 0;
    }
    cout << "+++++++++++++++++++++++++++++++++++++" << endl;
    cout << endl;
    cout << "Please Enter one of the following Choices" << endl;
    cout << "Enter '1' to Print all the student records" << endl;
    cout << "Enter '2' to search student by name" << endl;
    cout << "Enter '3' to update a student's course" << endl;
    cout << "Enter '4' to update a student record" << endl;
    cout << "Enter '5' to Add a student" << endl;
    cout << "Enter '6' to Add a course for Student" << endl;
    cout << "Enter '7' to delete a Student" << endl;
    cout << "Enter '8' to delete a course for a student" << endl;
    cout << "Enter '9' to Quit" << endl;
    cout << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << endl;
    cin >> answer;

    while(answer < 1 || answer > 9) {
        cout << endl;
        cout << "+++++++++++++++++++++++++++++++++++++" << endl;
        cout << endl;
        cout << "Error" << endl;
        cout << "Please Re-enter one of the following Choices" << endl;
        cout << "Enter '1' to Print all the student records" << endl;
        cout << "Enter '2' to search student by name" << endl;
        cout << "Enter '3' to update a student's course" << endl;
        cout << "Enter '4' to update a student record" << endl;
        cout << "Enter '5' to Add a student" << endl;
        cout << "Enter '6' to Add a course for Student" << endl;
        cout << "Enter '7' to delete a Student" << endl;
        cout << "Enter '8' to delete a course for a student" << endl;
        cout << "Enter '9' to Quit" << endl;
        cout << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << endl;
        cin >> answer;
        cin.clear();
        cin.ignore(256, '\n');
    }
    return answer;
}
