#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    cout << "Enter the score count: " ;
    int maxSize ;
    cin >> maxSize ;
    int* const scores = new int[maxSize] ;
    int sum = 0;
    int count = 0;
    while (true)
    {
        cout << "Enter command : (add, sum, average, quit) ";
        string cmd;
        cin >> cmd;
        for (int i=0; i < cmd.size(); i++)
        cmd[i] = toupper(cmd[i]);
        if (cmd == "ADD")
        {
            if (count >= maxSize)
            {
                cout << "Too many scores." << endl;
            }
            else
            {
                cout << "Enter score : ";
                int n;
                cin >> n;
                if (n >= 0 && n <= 100)
                {
                    scores[count] = n;
                    sum += scores[count];
                    cout << scores[count] << " added." << endl;
                    count++;
                }
                else
                {
                    cout << "점수는 0부터 100사이의 정수이다." << endl;
                }
            }
        }
        else if (cmd == "SUM")
        {
            cout << "Sum : " << sum << endl;
        }
        else if (cmd == "AVERAGE")
        {
            if (count == 0)
            {
                cout << "1개 이상의 점수가 입력되어야 한다." << endl;
            }
            else
            {
                cout << "Average : " << float(sum)/count << endl;
            }
        }
        else if (cmd == "QUIT")
        {
            cout << "Bye." << endl;
            break;
        }
    }
    
    delete [] scores ;
    return 0;
}