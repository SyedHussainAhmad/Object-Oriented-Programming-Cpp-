#include"OfferedCourses.h"
#include"Student.h"
int main()
{
    OfferedCourses semesterCourses;
    Course course1("OOP", 112);
    Course course2("DSA", 313);
    Course course3("AOA", 411);
    semesterCourses.addCourse(course1);
    semesterCourses.addCourse(course2);
    semesterCourses.addCourse(course3);
    semesterCourses.displayOfferedCourses();
    Student std("jerry", 1001);
    std.enrollCourse(semesterCourses.getCourse(0));
    std.enrollCourse(semesterCourses.getCourse(2));
    std.displayCourses();
    cout << '\n';
    return 0;
}
