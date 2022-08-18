#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum MajorType { CE, EE, ME, UD};
class Major {
private:
    MajorType majorType;
public:
    Major(MajorType _majorType) { majorType = _majorType; }
    MajorType getMajor() const;
    void setMajor(MajorType _majorType);
};

class Student {
private:
    string name;
    float gpa;
    Major major;
public:
    Student(string _name, float _gpa, MajorType _major) : name(_name), major(Major(_major))
    {
        gpa = _gpa;
    }

    void setGPA(float _gpa);
    void setMajor(MajorType _major);
    float getGPA() const;
    void print() const;
} ;

class School {
private:
    string schoolName ;
    vector<Student> students ;
public:
    School(string _schoolName) : schoolName(_schoolName) { }

    Student* addStudent(string name, MajorType major);
    Student* addStudent(string name, float gpa);
    void print() const;
    void sort();
    void swap(Student& stu1, Student& stu2);
};

int main() {
    School pnu("PNU") ;
    Student* kim = pnu.addStudent("Kim", EE) ;
    kim->setGPA(3.5F) ;
    Student* hong = pnu.addStudent("Hong", CE) ;
    hong->setGPA(4.3F) ;
    Student* lee = pnu.addStudent("Lee", 4.0F) ;
    lee->setMajor(CE) ;
    Student* joo = pnu.addStudent("Joo", 1.5F) ;
    joo->setMajor(ME) ;

    pnu.print() ;

    pnu.sort() ; // descending
    pnu.print() ;
}

MajorType Major::getMajor() const { return majorType; }

void Major::setMajor(MajorType _majorType) { majorType = _majorType; }

void Student::setGPA(float _gpa) { gpa = _gpa; }

void Student::setMajor(MajorType _major) { major.setMajor(_major); }

float Student::getGPA() const { return gpa; }

Student* School::addStudent(string name, MajorType major) 
{
    students.push_back(Student(name, 0.0F, major)); 
    return &students[students.size()-1];
}

Student* School::addStudent(string name, float gpa) 
{ 
    students.push_back(Student(name, gpa, UD)); 
    return &students[students.size()-1];
}

void Student::print() const
{
    string m;
    if (major.getMajor() == CE)
        m = "Computer Eng.";
    else if (major.getMajor() == EE)
        m = "Electrical Eng.";
    else if (major.getMajor() == ME)
        m = "Mechanical Eng.";
    else
        m = "UnDefined.";
    cout << "Name : " << name << " GPA : " << gpa << " Major : " << m << endl;
}

void School::print() const
{
    cout << "School Name : " << schoolName << ", Count : " << students.size() <<endl;
    for (vector<Student>::const_iterator it=students.begin(); it != students.end(); it++)
        (*it).print();
    cout << endl;
}

void School::sort()
{
    int N = students.size();
    for(int i=0; i<students.size(); i++)
    {
        for(int j=0; j < N-1-i; j++)
        {
            if (students[j].getGPA() < students[j+1].getGPA())
                swap(students[j], students[j+1]);
        }
    }
}

void School::swap(Student& stu1, Student& stu2)
{
    Student temp(stu1);
    stu1 = stu2;
    stu2 = temp;
}
