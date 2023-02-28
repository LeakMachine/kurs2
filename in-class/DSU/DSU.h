#ifndef DSU_H_
#define DSU_H_
#define SIZE 6

#include <iostream>
#include <vector>

class DSU {
protected:
	int p[SIZE];
	int rank[SIZE];
public:
	DSU() {
		for (int i = 1; i < SIZE; i++) {
			p[i] = 0;
		}
		for (int i = 1; i < SIZE; i++) {
			rank[i] = 0;
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
};


#endif