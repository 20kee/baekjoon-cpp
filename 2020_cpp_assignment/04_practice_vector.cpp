#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int SUBJECT_NO = 3 ;
struct StudentInfo {
    string name ;
    int scores[SUBJECT_NO] ;
    int sum ;
    float average ;
};

void print_StudentInfo(const StudentInfo& stu_info, int num, vector<int>& total);
void print_StudentVector(const vector<StudentInfo>& stu_vector);

int main()
{
    int N;
    cin >> N;
    vector<StudentInfo> students(N);

    for (int i=0; i<N; i++)
    {
        cin >> students[i].name >> students[i].scores[0] >> students[i].scores[1] >> students[i].scores[2];
        students[i].sum = students[i].scores[0] + students[i].scores[1] + students[i].scores[2];
    }

    print_StudentVector(students);

    return 0;
}


void print_StudentInfo(const StudentInfo& stu_info, int num, vector<int>& total)
{
    cout << num << " " << stu_info.name << " " << stu_info.scores[0] << " " << stu_info.scores[1] << " " << stu_info.scores[2] << " " << stu_info.sum << " " << (stu_info.sum)/3.0 << endl;
    for (int i=0; i<3; i++)
        total[i] += stu_info.scores[i];
}   


void print_StudentVector(const vector<StudentInfo>& stu_vector)
{
    vector<int> total(3);
    int sum=0;
    for (vector<StudentInfo>::const_iterator it=stu_vector.begin(); it != stu_vector.end(); ++it)
    {
        print_StudentInfo(*it, int(it-stu_vector.begin())+1, total);
    }
    for (int i=0; i<3; i++)
        sum += total[i];
    cout << "TOTAL " << total[0] << " " << total[1] << " " << total[2] << " " << sum << endl;
}