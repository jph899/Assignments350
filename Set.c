#include "Set.H"
#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;

Set::Set(size_t n) { // create empty subset of {0..n-1}
	assert (n > 0);
	bits = new int[n];
	for (int i = 0; i < (int)n; i++) {
		bits[i] = i;
	}
	this->n = n;
	this->a = n;

}   

Set::~Set() { // deconstructor
	delete [] bits;
}   

Set::Set(const Set &s) { // copy constructor
	bits = new int[s.n];
	for (int i = 0; i < (int)n; i++) {
		bits[i] = i;
	}
	this->n = s.n;
	this->a = s.a;
}   
       
Set& Set::operator=(const Set &s) { // assignment operator
	if (this != &s) {
		for (int i=0; i < (int)n; i++) {
			bits[i] = s.bits[i];
		}
	}
}

void Set::clear(){ // empty set
	for (int i = 0; i < (int)n; i++) {
		this->bits[i] = 0;
	}
}

void Set::complement() { // negate set (x was in set before <=> x is not in set after)

}

bool Set::has(size_t x) const { // return true iff x is element of set (0 <= x < n)
	return true;
}

void Set::add(size_t x) { // add element x to set (0 <= x < n)

}

void Set::remove(size_t x) { // remove element x from set (0 <= x < n)

}

// add all elements of s to set; pre-cond: s.n == n
void Set::add(const Set &s) {

}

// remove all elements of s from set; pre-cond: s.n == n
void Set::remove(const Set &s) {

}

// return maximum number of elements
size_t Set::get_n() const { 
	return n; 
}

// print elements to output stream os (default std::cout) like so: 
// [ 1 2 4 5 ]
// for set {1,2,4,5} (no extra spaces, no newline characters)
void Set::print(ostream &os = cout) const {
	cout << os << endl;
}
