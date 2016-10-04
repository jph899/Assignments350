#include "String.h"
#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

// constructor: initializes String with copy of 0-terminated C-string  
String::String(const char *p) {
  //cout << "Constructor" << endl;
  shared = new SharedData;

  shared->data = new char[strlen(p)];
  shared->n = strlen(p);
  shared->count = 1;

  for (int i=0; i<int(strlen(p)); i++) {
    *(shared->data+i) = *(p+i);
  }

}

// destructor (when can shared data be released?)
String::~String() {
  //std::cout << "Destructor" << std::endl;
  delete shared;
}  

// copy constructor (how does this change reference counts?)
String::String(const String &x) {
  //std::cout << "Copy Constructor" << std::endl;
  shared = new SharedData;

  shared->data = new char[x.shared->n];
  shared->n = x.shared->n;
  shared->count = x.shared->count + 1;
  x.shared->count = x.shared->count + 1;

  for (int i=0; i<int(x.shared->n); i++) {
    *(shared->data+i) = *(x.shared->data+i);
  }

}

// assignment operator (how does this change reference counts?)
String& String::operator=(const String &x){
  //std::cout << "Assignment Operator" << std::endl;
  if (this != &x) {
    shared->data = x.shared->data;
    shared->n = x.shared->n;
    shared->count = x.shared->count +1 ;
    x.shared->count = x.shared->count + 1;
  }
  return *this;
}

// return number of non-0 characters in string
size_t String::size() const {
  return shared->n;
}

// return reference count
size_t String::ref_count() const {
  return shared->count;
}

// returns pointer to C-string
const char* String::cstr() const {
  return shared->data;
}
