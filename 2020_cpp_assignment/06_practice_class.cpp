#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
    string name ;
    float gpa ;
public:
    Student(string _name, float _gpa=0.0F)
    {
        name = _name;
        gpa = _gpa;
    }

    void setGPA(float _gpa)
    {
        gpa = _gpa;
    }

    void setName(string _name)
    {
        name = _name;
    }

    void print() const
    {
        cout << "Name : " << name << " GPA : " << gpa << endl;
    }

    float getGPA() const
    {
        return gpa;
    }

    string& getName()
    {
        return name;
    }
};

class School {
private:
    string schoolName ;
    vector<Student> students ;
public:
    School(string _schoolName):schoolName(_schoolName) { }

    void addStudent(string stu_name, float stu_gpa=0.0F)
    {
        students.push_back(Student(stu_name, stu_gpa));
    }

    void print() const
    {
        cout << "Schoole Name : " << schoolName << ", Count : " << students.size() << endl;
        for (vector<Student>::const_iterator it=students.begin(); it!=students.end(); it++)
        {
            (*it).print();
        }
    }

    void sort()
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

    void swap(Student& stu1, Student& stu2)
    {
        Student temp(stu1);
        stu1 = stu2;
        stu2 = temp;
    }

    Student& findStudentWithName(string _name)
    {
        for (vector<Student>::iterator it=students.begin(); it!=students.end(); it++)
            if ( !(*it).getName().compare(_name) )
                return *it;
    }


};

int main() {
    School pnu("PNU") ;
    pnu.addStudent("Kim", 2.7F) ;
    pnu.addStudent("Hong", 3.5F) ;
    pnu.addStudent("Lee") ;
    pnu.addStudent("Joo", 1.5F) ;
    pnu.print() ;
    pnu.sort() ; // descending
    pnu.print();

    School knu("KNU") ;
    knu.addStudent("Seo", 2.5F) ;
    knu.addStudent("Lee", 3.8F) ;
    knu.print() ;

    Student& lee = pnu.findStudentWithName("Lee") ;
    lee.setGPA(3.3F) ;
    lee.setName("Yoon") ;
    pnu.print() ;
    knu.addStudent("Hong", 4.3F) ;

    Student& hong = knu.findStudentWithName("Hong") ;
    hong.setGPA(3.3F) ;
    hong.setName("Joon") ;
    knu.print() ;

    return 0;
}
