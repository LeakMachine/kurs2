#include "class.h"

template <class Type>
TPair<Type>::TPair() : first(0), second(0) {}

template <class Type>
TPair<Type>::TPair(Type _first, Type _second) : first(_first), second(_second) {}

template <class Type>
TPair<Type>::TPair(const TPair& c) : first(c.first), second(c.second) {}


template <class Type>
TPair<Type> TPair<Type>::operator+(const TPair& c) {
	return TPair(first + c.first, second + c.second);
}

template <class Type>
TPair<Type> TPair<Type>::operator=(const TPair& c) {
	return TPair(first = c.first, second = c.second);
}

template <class Type>
void TPair<Type>::print()
{
	std::cout << "(" << first << ", " << second << "(" << std::endl;
}

template <class Type>
std::ostream& operator<< (std::ostream& out, const TPair<Type>& pair) {
	out << "(" << pair.first << ", " << pair.second << "(" << std::endl;
	return out;
}
