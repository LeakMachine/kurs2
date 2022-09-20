#include <iostream>
#include <vector>
#include <time.h>
#include<algorithm>

#define RAND_SEED 0

int main() {
	srand(time(RAND_SEED));
	std::vector<std::pair<std::string, float>> vec(10);
	for (std::vector<std::pair<std::string, float>>::iterator it = begin(vec); it != end(vec); ++it) {
		int index = rand() % 3;
		switch (index) {
			case 0: {	*it = { "public", rand() % 100 }; break;  }
			case 1: {	*it = { "private", rand() % 100 }; break;  }
			case 2: {	*it = { "protected", rand() % 100 }; break;  }
		}
	}
	for (const auto& elem : vec) {
		std::cout << elem.first << ' ' << elem.second << std::endl;
	}

	std::cout << "----" << std::endl;

	auto isPublic = [](std::pair<std::string, float>& n) { if (n.first == "public") { n.second = 0; }; };
	auto isProtected = [](std::pair<std::string, float>& n) { if (n.first == "protected") { n.first = "private"; }; };
    std::for_each(std::begin(vec), std::end(vec), isPublic);
	std::for_each(std::begin(vec), std::end(vec), isProtected);
	for (const auto& elem : vec) {
		std::cout << elem.first << ' ' << elem.second << std::endl;
	}

	return 0;
}