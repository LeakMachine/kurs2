#ifndef DSU_H_
#define DSU_H_

#include <iostream>
#include <vector>

class DSU {
protected:
	int size;
	int* p;
	int* rank;
	bool* bottom = new bool[size];
	bool* right = new bool[size];
public:
	DSU(int  _size) {
		size = _size;
		p = new int[size];
		rank = new int[size];
		bottom = new bool[size];
		right = new bool[size];
		for (int i = 0; i < size; i++) {
			MakeSet(i);
		}
	}
	void MakeSet(int x) {
		p[x] = x;
	}
	int Find(int x) {
		if (p[x] == x)
			return x;
		return p[x] = Find(p[x]);
	}
	void Unite(int a, int b) {
		a = Find(a);
		b = Find(b);
		if (rank[a] < rank[b])
			p[a] = b;
		else
		{
			p[b] = a;
			if (rank[a] == rank[b])
				++rank[a];
		}
	}

	bool getRight(int x) { return right[x]; }
	bool getBottom(int x) { return bottom[x]; }
	void setRightFalse(int x) { right[x] = false; }
	void setBottomFalse(int x) { bottom[x] = false; }
	void setRight(int x) { right[x] = true; }
	void setBottom(int x) { bottom[x] = true; }

	void print() {
		std::cout << size << std::endl;

		std::cout << "+";
		for (int i = 0; i < size - 1; i++) {
			std::cout << "--+";
		}
		std::cout << "   +";
		std::cout << std::endl;

		for (int i = 0; i < size; i++) {
			std::cout << "|";
			for (int j = 0; j < size; j++) {
				if (getRight(i * size + j)) {
					std::cout << "   ";
				}
				else {
					std::cout << "  |";
				}
				if (j + 1 == size) {
					std::cout << "|";
				}
			}
			std::cout << std::endl;
			std::cout << "+";
			for (int j = 0; j < size; j++) {
				if (getBottom(i * j)) {
					std::cout << "--+";
				}
				else {
					std::cout << "  +";
				}
			}
			std::cout << "|";
			std::cout << std::endl;
		}

	}
};


#endif