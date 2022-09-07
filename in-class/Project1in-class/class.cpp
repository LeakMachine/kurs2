#include "class.h"

template <class Type>
TPair<Type>::TPair()
{
  first = 0;
  second = 0;
}

template <class Type>
TPair<Type>::TPair(Type _first, Type _second)
{
  first = _first;
  second = _second;
}

template <class Type>
TPair<Type>::TPair(const TPair<Type>& c)
{
  first = c.first;
  second = c.second;
}

template <class Type>
TPair<Type> TPair<Type>::operator+(const TPair<Type>& c)
{
  TPair CTemp;
  CTemp.first = this->first + c.first;
  CTemp.second = this->second + c.second;
  return CTemp;
}

template <class Type>
TPair<Type>& TPair<Type>::operator=(const TPair<Type>& c)
{
  this->first = c.first;
  this->second = c.second;
  
  return *this;
}

template <class Type>
void TPair<Type>::print()
{
  std::cout << "First: " << first << " Second: " << second << std::endl;
}

template <class Type>
std::ostream& operator<<(std::ostream &out, const TPair<Type> &c)
{
  out << "First: " << c.first << " Second: " << c.second << std::endl;
  return out;
}
