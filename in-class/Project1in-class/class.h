#pragma once
#include <iostream>

template <class Type> class TPair;
template <class Type> std::ostream& operator <<(std::ostream& out, const TPair<Type>& pair);

template <class Type>
class TPair {
private:
  Type first;
  Type second;
public:
  TPair() {
	  first = 0;
	  second = 0;
  }
  TPair(Type _first, Type _second) {
	  first = _first;
	  second = _second;
  }
  TPair(const TPair& c) {
	  first = c.first;
	  second = c.second;
  }

  TPair operator+(const TPair& c) {
	  return TPair(first + c.first, second + c.second);
  }

  TPair operator=(const TPair& c) {
	  return TPair(first = c.first, second = c.second);
  }

  friend std::ostream& operator << <Type>(std::ostream& out, const TPair<Type>& pair);

  void print() {
	  std::cout << "(" << first << ", " << second << "(" << std::endl;
  }

};
template <class Type>
std::ostream& operator <<(std::ostream& out, const TPair<Type>& pair) {
	out << "(" << pair.first << ", " << pair.second << ")" << std::endl;
	return out;
}