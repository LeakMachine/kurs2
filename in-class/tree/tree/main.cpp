#include "tree.h"
#include <iostream>

int main() {
	CTreeF<int> tree;
	CTreeExpr<char> treeExpr;

	tree.insert(0);
	tree.insert(2);
	tree.insert(-1);
	tree.insert(3);
	tree.remove(2);

	if (tree.find(3)) {
		std::cout << "it's working" << std::endl;
	}

	treeExpr.buildExpressionTree("*+42/53");
	std::cout << treeExpr.evaluateExpressionTree() << std::endl;

	return 0;
}