#include <iostream>
#include "DSU.h"

int main() {

    srand(time(0));

    int n = 2;
    DSU z(n * n);

    std::vector<int> wall;
    for (int i = 1; i <= n * n * 2 - 2; ++i) {
        if (i % (2 * n) == 0) continue;
        if (i > n * (n - 1) * 2) continue;
        wall.push_back(i);
    }

    while (wall.size() > 0) {
        int size = wall.size();

        int j = rand() % size;

        int x = (wall[j] - 1) / 2;
        if (wall[j] % 2 == 0) {
            if (z.Find(x) != z.Find(x + 1)) {
                z.Unite(z.Find(x), z.Find(x + 1));
                z.setRightFalse(x);
            }
        }
        else {
            if (z.Find(x) != z.Find(x + n)) {
                z.Unite(z.Find(x), z.Find(x + n));
                z.setBottomFalse(x);
            }
        }
        wall.erase(wall.begin() + j);
    }
    z.print();

	return 0;
}