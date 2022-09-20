#pragma once
#include <iostream>

template <class Type> class TPair;
template <class Type> std::ostream& operator<< (std::ostream& out, const TPair<Type>& pair);

template <class Type>
class TPair {
private:
  Type first;
  Type second;
public:
  TPair();
  TPair(Type _first, Type _second);
  TPair(const TPair& c);

  TPair operator+(const TPair& c);
  TPair operator=(const TPair& c);

  void print();

};