#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <random>

void printVec(std::vector<int> _vec) {
	for (std::vector<int>::iterator it = begin(_vec); it != end(_vec); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

void printVecR(std::vector<int> _vec) {
	for (std::vector<int>::reverse_iterator it = rbegin(_vec); it != rend(_vec); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

int main() {
	srand(time(0));
  std::vector<int> vec(20,0);

	printVec(vec);
  
	for (std::vector<int>::iterator it = begin(vec); it != end(vec); ++it) {
		*it = -100 + rand() % 201;
	}

	printVec(vec);

	std::sort(begin(vec), end(vec));

	printVec(vec);

	for (int i = 0; i < 4; i++) {
		vec.push_back(3);
	}

	printVec(vec);

	auto isLTTN = [](int &v) { if (v < 10) { v = 0; }; };
	auto isLTTW = [](int v) { if (v > 20) { std::cout << v << std::endl; }; };
	auto notOdd = [](int& v) { if (v % 2 == 0) { v = v * 3; }; };
	auto isLTF = [](int v) { return v > 50; };

	std::for_each(begin(vec), end(vec), isLTTN);

	printVec(vec);

	std::for_each(begin(vec), end(vec), isLTTW);

	std::for_each(begin(vec), end(vec), notOdd);

	printVec(vec);


	std::mt19937 g(rand());
	std::shuffle(begin(vec), end(vec), g);

	printVec(vec);

	vec.erase(std::remove_if(vec.begin(), vec.end(), isLTF), vec.end());

	printVec(vec);

	std::cout << vec.size() << std::endl;

	if (vec.size() % 2 == 0) {
		printVecR(vec);
	}
	else {
		vec.pop_back();
	}

	vec.clear();

	if (vec.empty() == true) {
		std::cout << "Vector is empty!" << std::endl;
	}
	else {
		std::cout << "Vector contains something!" << std::endl;
		vec.clear();
	}

  return 0;
}