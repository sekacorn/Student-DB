//Authour: Sekacorn
#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course {
private:
    std::string courseName;
    std::string courseId;
    std::string courseSummary;
    std::string instructorName;
    std::string instructorId;
    double finalGradePercentage;
    std::string finalGradeLetter;

public:
    // Constructors
    Course();
    Course(const std::string& name, const std::string& id, const std::string& summary,
        const std::string& instructorName, const std::string& instructorId,
        double finalGradePercentage, const std::string& finalGradeLetter);

    // Getters
    std::string getCourseName() const;
    std::string getCourseId() const;
    std::string getCourseSummary() const;
    std::string getInstructorName() const;
    std::string getInstructorId() const;
    double getFinalGradePercentage() const;
    std::string getFinalGradeLetter() const;

    // Setters
    void setCourseName(const std::string& name);
    void setCourseId(const std::string& id);
    void setCourseSummary(const std::string& summary);
    void setInstructorName(const std::string& name);
    void setInstructorId(const std::string& id);
    void setFinalGradePercentage(double percentage);
    void setFinalGradeLetter(const std::string& grade);
};

#endif
