#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <random>
#include <list>
#include <stack>
#include <set>

using namespace std;

void printList(std::list<int> _list) {
	for (int n : _list)
		std::cout << n << " ";
	std::cout << std::endl;
}

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
	std::cout << "VECTOR" << std::endl;
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

	// ----------------------list-----------------------------
	std::cout << "LIST" << std::endl;

	std::list<int> numbers;
	for (int i = 0; i < 5; i++) {
		numbers.push_back(rand() % 10);
	}

	printList(numbers);

	std::cout << numbers.front() << std::endl;

	for (int i = 0; i < 2; i++) {
		numbers.push_front(rand() % 10);
	}

	printList(numbers);
	int i = 0;
	for (auto iter = numbers.begin(); iter != numbers.end(); iter++) {
		if (i == 3) {
			iter = numbers.erase(iter);
		}
		i++;
	}

	printList(numbers);	

	for (int j = 1; j <= 3; ++j) {
		numbers.insert(std::next(numbers.begin(), rand() % numbers.size()), 333);
	}

	printList(numbers);

	numbers.pop_back();
	numbers.pop_front();

	printList(numbers);

	numbers.sort();
	auto last = std::unique(std::begin(numbers), std::end(numbers));
	numbers.erase(last, std::end(numbers));

	printList(numbers);

	numbers.clear();

	if (numbers.empty() == true) {
		std::cout << "List is empty!" << std::endl;
	}
	else {
		std::cout << "List contains something!" << std::endl;
		vec.clear();
	}

	// ----------------------STACK-----------------------------
	std::cout << "STACK" << std::endl;

	stack <int> intStack;

	int iMenu = 0;

	while (iMenu != 0) {
		std::cout << "1 - insert element, 2 - remove element, 3 - print stack, 4 - clear stack, 0 - exit" << std::endl;
		std::cout << "Enter your command: ";
		std::cin >> iMenu;
		switch (iMenu) {
			case 0: {break; };
			case 1: {int a; std::cin >> a; intStack.push(a); break; };
			case 2: {intStack.pop(); break; };
			case 3: {while (!intStack.empty()) { std::cout << "| " << intStack.top() << " |" << std::endl; intStack.pop(); } std::cout << "------" << std::endl; break; };
			case 4: {while (!intStack.empty()) { intStack.pop(); } break; };
		}
	}

	// ----------------------SET-----------------------------
	std::cout << "SET" << std::endl;

	set <int> intSet1, intSet2, intSet3;
	set <int> universe = { 0,1,2,3,4,5,6,7,8,9 };

	int iMenu2 = -1;

	while (iMenu2 != 0) {
		std::cout << "1 - insert element in set A, 2 - insert element in set B, 3 - find intersection, 4 - find union, 5 - find A - B, 6 - find addition for set, 7 - clean, 0 - exit" << std::endl;
		std::cout << "Enter your command: ";
		std::cin >> iMenu2;
		switch (iMenu2) {
		case 0: {break; };
		case 1: {int a; std::cin >> a; intSet1.insert(a); break; };
		case 2: {int a; std::cin >> a; intSet2.insert(a); break; };
		case 3: {
			for (auto iter1 = intSet1.begin(); iter1 != intSet1.end(); iter1++) {
				for (auto iter2 = intSet2.begin(); iter2 != intSet2.end(); iter2++) {
					if (*iter1 == *iter2) {
						intSet3.insert(*iter1);
					}
				}
			}
			std::cout << "intersection: " << std::endl;
			copy(intSet3.begin(), intSet3.end(), ostream_iterator<int>(cout, " "));
			std::cout << std::endl;
			intSet3.clear();

			break;
		};
		case 4: {
			for (auto iter1 = intSet1.begin(); iter1 != intSet1.end(); iter1++) {
				for (auto iter2 = intSet2.begin(); iter2 != intSet2.end(); iter2++) {
					intSet3.insert(*iter1);
					intSet3.insert(*iter2);
				}
			}
			std::cout << "union: " << std::endl;
			copy(intSet3.begin(), intSet3.end(), ostream_iterator<int>(cout, " "));
			std::cout << std::endl;
			intSet3.clear();
			break;
		};
		case 5: {
			bool fl = false;
			for (auto& elem : intSet1) {
				for (auto& _elem : intSet2) {
					if (elem == _elem) {
						fl = true;
					}
				}
				if (!fl) intSet3.insert(elem);
				fl = false;
			}
			for (auto& elem : intSet2) {
				for (auto& _elem : intSet1) {
					if (elem == _elem) {
						fl = true;
					}
				}
				if (!fl) intSet3.insert(elem);
				fl = false;
			}
			std::cout << "a - b: " << std::endl;
			copy(intSet3.begin(), intSet3.end(), ostream_iterator<int>(cout, " "));
			std::cout << std::endl;
			intSet3.clear();
			break; 
		};
		case 6: {
			std::cout << "select set: 0 - a, 1 - b" << std::endl;
			int a; 
			std::cin >> a;
			if (a == 0) {
				bool fl = false;
				for (auto& elem : universe) {
					for (auto& _elem : intSet1) {
						if (elem == _elem) {
							fl = true;
						}
					}
					if (!fl) intSet3.insert(elem);
					fl = false;
				}
			}
			if (a == 1) {
				bool fl = false;
				for (auto& elem : universe) {
					for (auto& _elem : intSet2) {
						if (elem == _elem) {
							fl = true;
						}
					}
					if (!fl) intSet3.insert(elem);
					fl = false;
				}
			}
			std::cout << "addition: " << std::endl;
			copy(intSet3.begin(), intSet3.end(), ostream_iterator<int>(cout, " "));
			std::cout << std::endl;
			intSet3.clear();

			break; 
		};
		case 7: {
			intSet1.clear();
			intSet2.clear();
			intSet3.clear();
			break;
		};
		}
	}
  return 0;
}