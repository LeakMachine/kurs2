#include "tree.h"
#include <iostream>

int main() {
	CTreeF<int> tree;

	tree.insert(0);
	tree.insert(2);
	tree.insert(-1);

	if (tree.find(-1) == true) {
		std::cout << "TOTAL C++ DEATH" << std::endl;
	}
	if (tree.find(4) == false) {
		std::cout << "TOTAL PYTHON DEATH" << std::endl;
	}

	return 0;
}