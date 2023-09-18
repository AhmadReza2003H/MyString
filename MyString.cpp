/* File: MyString.cpp
   Author: ???
   Description: Implementation for custom class that is used for storing and
   manipulating strings. Students should provide their solution to the MyString
   class implementation here.                                                  */


#include "MyString.h" /* MyString class declaration                            */
#include <string.h>   /* strcpy, strlen, etc.                                  */
#include <iostream>

/* Initializes calling MyString object to represent c-string 'init_str'.
   Reference:
    (http://www.cplusplus.com/reference/clibrary/cstring/strcpy/)
    (http://www.cplusplus.com/reference/clibrary/cstring/strlen/)              */
MyString::MyString(const char *init_str) {

    this->str_length = 0;
    for (int i = 0; init_str[i] != 0; i++) {
        this->str_length++;
    }
    // Allocate memory for str_ptr and copy init_str.
    this->str_ptr = new char[this->str_length + 1];
    for (int i = 0; i <= str_length; i++) {
        this->str_ptr[i] = init_str[i];
    }
}

/* Deallocates memory resources associated with calling object.                */
MyString::~MyString() {
    delete[] this->str_ptr;
}

/* Resize the calling object's internal string representation to allow a string
   of length 'new_length', meaning an allocation of 'new_length' + 1. Previous
   string content should be preserved as much as possible (shrinking may
   truncate content).
*/
void MyString::Resize(int new_length) {
    this->str_ptr = (char *) realloc(this->str_ptr, new_length + 1);
    this->str_length = new_length;
}

/* Returns reference of calling object's char in c-string representation at
   'pos'. If 'pos' is invalid, an error message should be printed to std::cerr
   (including file name, function, error case) and the program should
    immediately exit with status 1.

   Reference:
    (http://www.cplusplus.com/reference/clibrary/cstdlib/exit/)                */
char &MyString::operator[](int pos) {
    if (pos > this->str_length - 1) {
        throw "index out of bounds";
    }
    return this->str_ptr[pos];
}

/* Same as overload above (This version allows []'s to be used for const
   objects).                                                                   */
char MyString::operator[](int pos) const {
    if (pos > this->str_length - 1) {
        throw "index out of bounds";
    }
    return this->str_ptr[pos];
}

/* Returns Mystring object that represents the concatination of
   MyString objects
   'my_str1' and 'my_str2'.
*/
MyString operator+(const MyString &my_str1, const MyString &my_str2) {
    MyString ret;
    ret.Resize(my_str1.str_length + my_str2.str_length);
    int retIndex = 0;
    for (int i = 0; i < my_str1.str_length; i++) {
        ret.str_ptr[retIndex] = my_str1.str_ptr[i];
        retIndex++;
    }
    for (int i = 0; i <= my_str2.str_length; i++) {
        ret.str_ptr[retIndex] = my_str2.str_ptr[i];
        retIndex++;
    }
    return ret;
}

/* Changes calling object to a copy of 'ms_src'.  Returns calling object
   reference to allow casecading, should do deep copy                                              */
MyString &MyString::operator=(const MyString &ms_src) {
    this->Resize(ms_src.str_length);
    for (int i = 0; i <= ms_src.str_length; i++) {
        this->str_ptr[i] = ms_src.str_ptr[i];
    }
    return *this;
}

/* Changes 'ms_str1' to a concatination of itself with 'ms_str2'. Returns
   MyString& to allow casecading.                               */
MyString &operator+=(MyString &ms_str1, const MyString &ms_str2) {
    int startIndex = ms_str1.str_length;
    ms_str1.Resize(ms_str1.str_length + ms_str2.str_length);
    for (int i = 0; i <= ms_str2.str_length; i++) {
        ms_str1.str_ptr[startIndex + i] = ms_str2.str_ptr[i];
    }
    return ms_str1;
}

/* Initializes calling MyString object to be a copy of 'ms_str' with deep copy
                            */
MyString::MyString(const MyString &ms_str) {
    this->str_ptr = new char[ms_str.str_length + 1];
    for (int i = 0; i <= ms_str.str_length; i++) {
        this->str_ptr[i] = ms_str.str_ptr[i];
    }
}

/* Outputs characters stored by MyString object 'my_str' to output stream 'os' */
std::ostream &operator<<(std::ostream &os, const MyString &my_str) {
    os << my_str.str_ptr;
    return os;
}

/* Changes MyString object my_str's data to hold characters input from stream
   'is'. Input ends when a newline or EOF is encountered (the newline should
   be extracted and discarded).  There is no maximum number of characters that
   can be input and the function must not overflow any buffers
   or use a temporary
   buffer greater than 101 char's.  Hint: Use MyString '+=' overload for
   concatination.

   Reference:
     (http://www.cplusplus.com/reference/iostream/istream/get/)
     (http://www.cplusplus.com/reference/clibrary/cstring/strlen/)
     (http://www.cplusplus.com/reference/iostream/istream/peek/)
     (http://www.cplusplus.com/reference/iostream/istream/ignore/)
                                                                               */
std::istream &operator>>(std::istream &is, MyString &my_str) {
    my_str.Resize(0);
    char letter[2];
    letter[1] = 0;
    while (is.get(letter[0]) && letter[0] != '\n') {
        my_str += MyString(letter);
    }
    return is; /* change me */
}


/* Rotates characters stored in 'ms_str' to the right by one and returns new
   version of 'ms_str'. Tokenization and substring generation state wihtin
   'ms_str' become invalid.

   Example:
       "abcd" => "dabc"                                                        */
MyString &operator++(MyString &ms_str) {
    char lastChar = ms_str.str_ptr[ms_str.str_length - 1];
    for (int i = ms_str.str_length - 1; i > 0; i--) {
        ms_str.str_ptr[i] = ms_str.str_ptr[i - 1];
    }
    ms_str.str_ptr[0] = lastChar;
    return ms_str;
}


/* Rotates characters stored in 'ms_str' to the left by one and returns new
   version of 'ms_str'.

   Example:
       "hello\n" => "ello\nh"                                                  */
MyString &operator--(MyString &ms_str) {
    char firstChar = ms_str.str_ptr[0];
    for (int i = 0; i < ms_str.str_length - 1; i++) {
        ms_str.str_ptr[i] = ms_str.str_ptr[i + 1];
    }
    ms_str.str_ptr[ms_str.str_length - 1] = firstChar;
    return ms_str;
}


/* Accepts pointer to char buffer and it's size in bytes. Fills 'buffer' with
   c-string from calling object.  Will stop short of overrunning buffer.       */
void MyString::StrCpy(char *buffer, int len) const {
    if (len <= this->str_length) {
        for (int i = 0; i < len - 1; i++) {
            buffer[i] = this->str_ptr[i];
        }
        buffer[len - 1] = '\0';
    } else {
        for (int i = 0; i <= this->str_length; i++) {
            buffer[i] = this->str_ptr[i];
        }
    }
}

/* Same as above except that buffer is filled by reversed version of calling
   object's c-string.                                                          */
void MyString::ReversedStrCpy(char *buffer, int len) const {
    if (len <= this->str_length) {
        for (int i = 0; i < len - 1; i++) {
            buffer[i] = this->str_ptr[this->str_length - 1 - i];
        }
        buffer[len - 1] = '\0';
    } else {
        for (int i = 0; i < this->str_length; i++) {
            buffer[i] = this->str_ptr[this->str_length - 1 - i];
        }
        buffer[this->str_length] = '\0';
    }
}

/* Returns c-string representation of MyString object.                         */
const char *MyString::cstring() const {
    return this->str_ptr;
}

/* Return length of calling object.                                            */
int MyString::GetLength() const {
    return this->str_length;
}

/* Comparison Operators:

   Compares two MyString objects.  Comparison is case insensitive.  A comparison
   starts by comparing the first character of each string. If they are equal to
   each other, it continues with the following pairs until the characters differ
   or until a terminating null-character is reached.  Non-alphabetical characters
   are compared using their ascii value (eg. '*' == 42 and is greater than '&' ==
   38).                                                                        */


bool operator<(const MyString &ms_str1, const MyString &ms_str2) {
    for (int i = 0; i <= ms_str1.str_length; i++) {
        if (tolower(ms_str1.str_ptr[i]) > tolower(ms_str2.str_ptr[i])) {
            return true;
        }
    }
    return false;
}

bool operator>(const MyString &ms_str1, const MyString &ms_str2) {

    for (int i = 0; i <= ms_str1.str_length; i++) {
        if (tolower(ms_str1.str_ptr[i]) > tolower(ms_str2.str_ptr[i])) {
            return true;
        }
    }
    return false;
}

bool operator<=(const MyString &ms_str1, const MyString &ms_str2) {
    for (int i = 0; i <= ms_str1.str_length; i++) {
        if (tolower(ms_str1.str_ptr[i]) > tolower(ms_str2.str_ptr[i])) {
            return false;
        }
    }
    return true;
}

bool operator>=(const MyString &ms_str1, const MyString &ms_str2) {
    for (int i = 0; i <= ms_str1.str_length; i++) {
        if (tolower(ms_str1.str_ptr[i]) > tolower(ms_str2.str_ptr[i])) {
            return false;
        }
    }
    return true;
}

bool operator==(const MyString &ms_str1, const MyString &ms_str2) {
    if (ms_str1.str_length == ms_str2.str_length) {
        for (int i = 0; i < ms_str1.str_length; i++) {
            if (ms_str1.str_ptr[i] != ms_str2.str_ptr[i]) {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

bool operator!=(const MyString &ms_str1, const MyString &ms_str2) {
    if (ms_str1.str_length == ms_str2.str_length) {
        for (int i = 0; i < ms_str1.str_length; i++) {
            if (ms_str1.str_ptr[i] != ms_str2.str_ptr[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

