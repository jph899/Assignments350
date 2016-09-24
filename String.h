#ifndef String_H
#define String_H

// for size_t (can represent size of main memory)
#include <cstdlib>
#include <iostream>

class String
{
public:

  // constructor: initializes String with copy of 0-terminated C-string  
  String(const char *p) {
    std::cout << "Constructor" << std::endl;
    SharedData *shared = new SharedData();

    std::cout << "p is " << *p << std::endl;
    *shared->data = *p; 
  };
  
  // destructor (when can shared data be released?)
  ~String() {
    std::cout << "Destructor" << std::endl;
    delete shared;
  };  

  // copy constructor (how does this change reference counts?)
  String(const String &x) {
    std::cout << "Copy Constructor" << std::endl;
    SharedData *shared = new SharedData();

    std::cout << "shared is " << *shared->data << std::endl;
    std::cout << "x is " << x.shared->data << std::endl;
    
    *shared->data = *x.shared->data;
  };

  // assignment operator (how does this change reference counts?)
  String &operator=(const String &x){
    std::cout << "Assignment Operator" << std::endl;
    if (this != &x) {
      shared->data = x.shared->data;
    }
    return *this;
  }; 
  
  // return number of non-0 characters in string
  size_t size() const {
    return shared->n;
  };

  // return reference count
  size_t ref_count() const {
    return shared->count;
  };
  
  // returns pointer to C-string
  const char *cstr() const {
    return shared->data;
  };
  
private:

  // data containing character strings
  // shared by Strings when copying/assigning
  struct SharedData
  {
    SharedData() {
      data = new char[1000000];
    };
    char *data;    // 0-terminated char array
    size_t n;      // number of non-0 characters in string
    size_t count;  // reference count, how many Strings share this object?
  };
  
  SharedData *shared;
};


#endif