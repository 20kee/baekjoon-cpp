#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>

using namespace std;

class MyString {
	char* str ;
	int size ;
public:
    MyString() { size=0; str = new char[1]; }

	MyString(const char* str) 
    { 
        this->str = (char*)str; 
        this->size = strlen(str);
    }

    void set(const char* str);
    bool isEqual(const MyString& target) const;
    char* getChar() const;
    int getSize() const;
    void print() const;
    ~MyString() { delete [] str; }
};

int main() {
	MyString strs[] = 
    {
		MyString("C"),
		MyString(),
		MyString("Java")
	} ;
	strs[1].set("C++") ;

	const MyString target("Java") ;
	for ( int i = 0 ; i < 3 ; i ++ ) {
		const MyString str(strs[i]) ;
		if ( str.isEqual(target) ) {
			cout << "[" << i << "]: " ;
			str.print() ;
			break ;
		}
	}
	for ( int i = 0 ; i < 3 ; i ++ ) {
		const MyString& str = strs[i] ;
		str.print() ;
	}
}

void MyString::set(const char* str) { this->str = (char*)str; }

bool MyString::isEqual(const MyString& target) const
{
    if (strcmp(str, target.getChar())==0 && size==target.getSize())
        return true;
    return false;
}

char* MyString::getChar() const { return str; }

int MyString::getSize() const { return size; }

void MyString::print() const { cout << str << endl; }