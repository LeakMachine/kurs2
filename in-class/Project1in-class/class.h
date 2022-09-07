#pragma once
#include <iostream>

template <class Type> class TPair;
template <class Type> std::ostream& operator <<(std::ostream& out, const TPair<Type>& c);

template <class Type>
class TPair {
private:
  Type first;
  Type second;
public:
  TPair();
  TPair(Type _first, Type _second);
  TPair(const TPair<Type>& c);

  TPair<Type> operator+(const TPair<Type>& c);
  TPair<Type>& operator=(const TPair<Type>& c);

  void print();
};