#include <iostream>
#include "DSU.h"

int main() {
	DSU set;

	set.MakeSet(1);
	set.MakeSet(2);
	set.MakeSet(3);
	set.MakeSet(4);
	set.MakeSet(5);

	std::cout << set.Find(4) << std::endl;

	set.Unite(1, 4);
	set.Unite(2, 5);

	std::cout << set.Find(4) << std::endl;
	std::cout << set.Find(1) << std::endl;
	std::cout << set.Find(2) << std::endl;
	
	set.Unite(3, 5);

	std::cout << set.Find(5) << std::endl;
	std::cout << set.Find(3) << std::endl;
	std::cout << set.Find(2) << std::endl;

	return 0;
}