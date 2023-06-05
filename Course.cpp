//Authour: Sekacorn

#include "Course.h"

// Constructors
Course::Course()
{
}

Course::Course(const std::string& name, const std::string& id, const std::string& summary,
    const std::string& instructorName, const std::string& instructorId,
    double finalGradePercentage, const std::string& finalGradeLetter)
    : courseName(name), courseId(id), courseSummary(summary), instructorName(instructorName),
    instructorId(instructorId), finalGradePercentage(finalGradePercentage), finalGradeLetter(finalGradeLetter)
{
}

// Getters
std::string Course::getCourseName() const
{
    return courseName;
}

std::string Course::getCourseId() const
{
    return courseId;
}

std::string Course::getCourseSummary() const
{
    return courseSummary;
}

std::string Course::getInstructorName() const
{
    return instructorName;
}

std::string Course::getInstructorId() const
{
    return instructorId;
}

double Course::getFinalGradePercentage() const
{
    return finalGradePercentage;
}

std::string Course::getFinalGradeLetter() const
{
    return finalGradeLetter;
}

// Setters
void Course::setCourseName(const std::string& name)
{
    courseName = name;
}

void Course::setCourseId(const std::string& id)
{
    courseId = id;
}

void Course::setCourseSummary(const std::string& summary)
{
    courseSummary = summary;
}

void Course::setInstructorName(const std::string& name)
{
    instructorName = name;
}

void Course::setInstructorId(const std::string& id)
{
    instructorId = id;
}

void Course::setFinalGradePercentage(double percentage)
{
    finalGradePercentage = percentage;
}

void Course::setFinalGradeLetter(const std::string& grade)
{
    finalGradeLetter = grade;
}
