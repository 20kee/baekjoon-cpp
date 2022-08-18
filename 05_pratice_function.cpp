#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>
using namespace std;

struct Rectangle {
    int width ;
    int height ;
} ;
enum CommandKind { ADD, SORT, PRINT, CLEAR, EXIT, INVALID} ;

CommandKind getCommandKind(string& commandString);
Rectangle& getRectangle();
void print(const Rectangle& rectangle);
void print(const vector<Rectangle>& rectangles);
void swap(Rectangle& rec1, Rectangle& rec2);
void sort(vector<Rectangle>& rectangles);

int main() {
    vector<Rectangle> rectangles ;
    while ( true ) {
        string commandString;
        cin >> commandString;
        const CommandKind command = getCommandKind(commandString);
        switch ( command ) {
            case ADD : {
                const Rectangle& newRectangle = getRectangle() ;
                rectangles.push_back(newRectangle) ;
                break ;
                }
            case PRINT:
                print(rectangles) ;
                // use const_iterator in print()
                // define and call print(const Rectangle&)
                break ;
            case SORT: {
                sort(rectangles) ; // define and call swap in sort()
                print(rectangles) ;
                break ;
                }
            case CLEAR: rectangles.clear() ; break ;
            case EXIT: break ;
            default: assert (false) ; break ;
        }
        if ( command == EXIT ) break ;
    }
    return 0;
}

CommandKind getCommandKind(string& commandString)
{
    CommandKind command;
    if (!commandString.compare("ADD"))
        command = ADD;
    else if (!commandString.compare("SORT"))
        command = SORT;
    else if (!commandString.compare("PRINT"))
        command = PRINT;
    else if (!commandString.compare("CLEAR"))
        command = CLEAR;
    else if (!commandString.compare("EXIT"))
        command = EXIT;
    else
        command = INVALID;
    
    return command;
}

Rectangle& getRectangle()
{
    static Rectangle rectangle;
    cin >> rectangle.width >> rectangle.height;
    return rectangle;
}

void print(const Rectangle& rectangle)
{
    cout << rectangle.width << " " << rectangle.height << " " << rectangle.height*rectangle.width << endl;
}

void print(const vector<Rectangle>& rectangles)
{
    cout << "Rectangle Count : " << rectangles.size() << endl;
    for (vector<Rectangle>::const_iterator it=rectangles.begin(); it != rectangles.end(); it++)
        print(*it);

    return;
}

void swap(Rectangle& rec1, Rectangle& rec2)
{
    Rectangle temp = rec1;
    rec1.height = rec2.height;
    rec1.width = rec2.width;
    rec2 = temp;
}

void sort(vector<Rectangle>& rectangles)
{
    int N = rectangles.size();
    for(int i=0; i<rectangles.size(); i++)
    {
        for(int j=0; j < N-1-i; j++)
        {
            if (rectangles[j].height*rectangles[j].width > rectangles[j+1].height*rectangles[j+1].width)
                swap(rectangles[j], rectangles[j+1]);
        }
    }
}
