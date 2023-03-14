#ifndef DSU_H_
#define DSU_H_

#include <iostream>
#include <vector>

class DSU {
protected:
	int size;
	int* p;
	int* rank;
	bool* right;
	bool* bottom;
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
		rank[x] = 0;
	}
	int Find(int x) {
		if (x != p[x])
			return Find(p[x]);
		return x;
	}
	void Unite(int x, int y) {
		int px = Find(x);
		int py = Find(y);
		if (rank[x] > rank[y])
			p[py] = px;
		else
		{
			p[px] = py;
			if (rank[x] == rank[y])
				++rank[py];
		}
	}

	bool getRight(int x) { return right[x]; }
	bool getBottom(int x) { return bottom[x]; }
	void setRightFalse(int x) { right[x] = false; }
	void setBottomFalse(int x) { bottom[x] = false; }
	void setRight(int x) { right[x] = true; }
	void setBottom(int x) { bottom[x] = true; }

};


#endif