#include <string>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    string t;
    int count[5] = {0, };

    while (true)
    {
        cin >> t;
        if (t == "int")
        {
            cout << numeric_limits<int>::min() << " " << numeric_limits<int>::max() << endl;
            count[0]++;
        }
        else if (t == "long")
        {
            cout << numeric_limits<long>::min() << " " << numeric_limits<long>::max() << endl;
            count[1]++;
        }
        else if (t == "float")
        {
            cout << numeric_limits<float>::min() << " " << numeric_limits<float>::max() << endl;
            count[2]++;
        }
        else if (t == "double")
        {
            cout << numeric_limits<double>::min() << " " << numeric_limits<double>::max() << endl;
            count[3]++;
        }
        else if (t == "char")
        {
            cout << numeric_limits<char>::min() << " " << numeric_limits<char>::max() << endl;
            count[4]++;
        }
        else
        {
            cout << "int : " << count[0] << endl;
            cout << "long : " << count[1] << endl;
            cout << "float : " << count[2] << endl;
            cout << "double : " << count[3] << endl;
            cout << "char : " << count[4] << endl;
            break;
        }
    }
    return 0;
}