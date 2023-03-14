#include <iostream>
#include "DSU.h"

#include <random>

int main() {

    srand(time(0));

    int n = 4;
    DSU z(n * n);

    std::vector<int> wall;
    for (int i = 0; i <= n * n * 2 - 2; i++) {
        if ((i % (2 * n) == 0) || (i > n * (n - 1) * 2)) continue;
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
    std::cout << "   ";
    for (int i = 1; i < n; i++) {
        std::cout << "___";
    }
    std::cout << std::endl;

    for (int i = 0; i < n; i++) {
        std::cout << "|";
        for (int j = n * i; j < n + n * i; j++) {
            if (j == n * n - 1) {
                std::cout << "  |";
            }
            else if (z.getRight(j) && z.getBottom(j)) {
                std::cout << "__|";
            }
            else if (z.getRight(j)) {
                std::cout << "  |";
            }
            else if (z.getBottom(j)) {
                std::cout << "__ ";
            }
            else {
                std::cout << "   ";
            }
        }
        std::cout << std::endl;
    }

	return 0;
}