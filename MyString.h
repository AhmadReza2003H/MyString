/* File: MyString.h
   Author: Matthew Small
   Modified by Xin Yuan
   Description: Header file for the MyString class, a custom class for storing
   and manipulating strings.  Students should NOT alter this file.
*/

#include <iostream>

class MyString
{
  /* Stream overloads */
  friend std::ostream& operator<<(std::ostream&, const MyString&);
  friend std::istream& operator>>(std::istream&, MyString&); 

  /* Arithmatic overloads */
  friend MyString operator+ (const MyString&, const MyString&);
  friend MyString& operator+=(MyString&, const MyString&); 
  friend MyString& operator++(MyString&);
  friend MyString& operator--(MyString&);

  /* Comparison overloads */
  friend bool operator<  (const MyString&, const MyString&);
  friend bool operator>  (const MyString&, const MyString&);
  friend bool operator<= (const MyString&, const MyString&);
  friend bool operator>= (const MyString&, const MyString&);
  friend bool operator== (const MyString&, const MyString&);
  friend bool operator!= (const MyString&, const MyString&);

 public:
 
  MyString(const char* s="");      
  MyString(const MyString&);
  ~MyString();

  /* Member overloads */
  MyString& operator=(const MyString&);
  char operator[] (int) const;      
  char& operator[](int);                 

  /* Member Utility Functions */
  void StrCpy(char *, int) const;
  void ReversedStrCpy(char *, int) const;


  /* Accessors */
  const char* cstring() const;
  int GetLength() const;

 private:
  void Resize(int); 

  /* internal string data */
  char* str_ptr;                   
  int str_length;   

};
