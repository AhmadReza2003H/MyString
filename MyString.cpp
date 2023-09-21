/* File: MyString.cpp
   Author: ???
   Description: Implementation for custom class that is used for storing and 
   manipulating strings. Students should provide their solution to the MyString
   class implementation here.                                                  */


#include "MyString.h" /* MyString class declaration                            */
#include <string.h>   /* strcpy, strlen, etc.                                  */


/* Initializes calling MyString object to represent c-string 'init_str'. 
   Reference:
    (http://www.cplusplus.com/reference/clibrary/cstring/strcpy/)      
    (http://www.cplusplus.com/reference/clibrary/cstring/strlen/)              */
MyString::MyString(const char* init_str) {

}      

/* Deallocates memory resources associated with calling object.                */
MyString::~MyString() {

}

/* Resize the calling object's internal string representation to allow a string 
   of length 'new_length', meaning an allocation of 'new_length' + 1. Previous 
   string content should be preserved as much as possible (shrinking may 
   truncate content).  
*/
void MyString::Resize(int new_length) {

}

/* Returns reference of calling object's char in c-string representation at 
   'pos'. If 'pos' is invalid, an error message should be printed to std::cerr 
   (including file name, function, error case) and the program should 
    immediately exit with status 1.   

   Reference:
    (http://www.cplusplus.com/reference/clibrary/cstdlib/exit/)                */
char& MyString::operator[](int pos) {

  return this->str_ptr[0]; /* change me */
}  

/* Same as overload above (This version allows []'s to be used for const 
   objects).                                                                   */
char MyString::operator[] (int pos) const {
    
  return this->str_ptr[0]; /* change me */
}      

/* Returns Mystring object that represents the concatination of 
   MyString objects
   'my_str1' and 'my_str2'.  
*/
MyString operator+(const MyString& my_str1, const MyString& my_str2) {
  MyString ret;

  return ret; /* change me */
}

/* Changes calling object to a copy of 'ms_src'.  Returns calling object 
   reference to allow casecading, should do deep copy                                              */
MyString& MyString::operator=(const MyString& ms_src) {
  return *this; /* change me */
}

/* Changes 'ms_str1' to a concatination of itself with 'ms_str2'. Returns 
   MyString& to allow casecading.                               */
MyString& operator+=(MyString& ms_str1, const MyString& ms_str2) {
  return ms_str1; /* change me */
}

/* Initializes calling MyString object to be a copy of 'ms_str' with deep copy
                            */
MyString::MyString(const MyString& ms_str) {
  
}

/* Outputs characters stored by MyString object 'my_str' to output stream 'os' */
std::ostream& operator<<(std::ostream& os, const MyString& my_str) {
  return os; /* change me */
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
std::istream& operator>>(std::istream& is, MyString& my_str) {
  return is; /* change me */
} 


/* Rotates characters stored in 'ms_str' to the right by one and returns new 
   version of 'ms_str'. Tokenization and substring generation state wihtin 
   'ms_str' become invalid.      

   Example:
       "abcd" => "dabc"                                                        */
MyString& operator++(MyString& ms_str) {
  return ms_str; /* change me */
}


/* Rotates characters stored in 'ms_str' to the left by one and returns new 
   version of 'ms_str'. 
                                      
   Example:
       "hello\n" => "ello\nh"                                                  */
MyString& operator--(MyString& ms_str) {
  return ms_str; /* change me */
}


/* Accepts pointer to char buffer and it's size in bytes. Fills 'buffer' with 
   c-string from calling object.  Will stop short of overrunning buffer.       */
void MyString::StrCpy(char *buffer, int len) const {

}
    
/* Same as above except that buffer is filled by reversed version of calling 
   object's c-string.                                                          */
void MyString::ReversedStrCpy(char *buffer, int len) const {
      
}

/* Returns c-string representation of MyString object.                         */
const char* MyString::cstring() const {
  return ""; /* change me */
}
   
/* Return length of calling object.                                            */
int MyString::GetLength() const {
  return 1; /* change me */
}
   
/* Comparison Operators:

   Compares two MyString objects.  Comparison is case insensitive.  A comparison
   starts by comparing the first character of each string. If they are equal to 
   each other, it continues with the following pairs until the characters differ
   or until a terminating null-character is reached.  Non-alphabetical characters
   are compared using their ascii value (eg. '*' == 42 and is greater than '&' == 
   38).                                                                        */


bool operator<  (const MyString& ms_str1, const MyString& ms_str2) {
  return true; /* change me */
}

bool operator>  (const MyString& ms_str1, const MyString& ms_str2) {
  return true; /* change me */
}
bool operator<= (const MyString& ms_str1, const MyString& ms_str2) {
  return true; /* change me */
}

bool operator>= (const MyString& ms_str1, const MyString& ms_str2) {
  return true; /* change me */
}

bool operator== (const MyString& ms_str1, const MyString& ms_str2) {
  return true; /* change me */
}

bool operator!= (const MyString& ms_str1, const MyString& ms_str2) {
  return true; /* change me */
}

