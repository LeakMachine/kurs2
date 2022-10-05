#include <iostream>
#include <vector>

using namespace std;

void printVec(std::vector<std::vector<int>> _vec) {
	std::cout << "------------" << std::endl;
	for (int i = 0; i < _vec.size(); i++) {
		for (int j = 0; j < _vec[i].size(); j++) {
			std::cout << _vec[i][j] << " ";
		}

		std::cout << std::endl;
	}
}

void printVec2(std::vector<std::vector<int>> _vec) {
	std::cout << "------------" << std::endl;
	for (int i = 0; i < _vec.size(); i++) {
		std::cout << _vec[i][0] << " ";
	}
	std::cout << std::endl;
}

void inputVec(std::vector<std::vector<int>>& _vec) {
	for (int i = 0; i < _vec.size(); i++) {
		for (int j = i; j < _vec.size(); j++)
		{
			std::cin >> _vec[i][j];
		}
	}
}

void inputVec2(std::vector<std::vector<int>>& _vec) {
	for (int i = 0; i < _vec.size(); i++) {
		std::cin >> _vec[i][0];
	}
}

void initVec(std::vector<std::vector<int>>& _vec) {
	for (int i = 0; i < _vec.size(); i++) {
		for (int j = 0; j < _vec.size(); j++)
		{
			_vec[i][j] = 0;
		}
	}
}

std::vector<std::vector<int>> transpositionVec(std::vector<std::vector<int>> _vec) {
	std::vector<std::vector<int>> res(_vec.size(), vector<int>(_vec.size()));

	for (int i = 0; i < _vec.size(); i++) {
		for (int j = 0; j < _vec.size(); j++) {
			res[i][j] = _vec[j][i];
		}
	}

	return res;
}

std::vector<std::vector<int>> addVec(std::vector<std::vector<int>> _vec, std::vector<std::vector<int>> _vec2) {
	std::vector<std::vector<int>> res(_vec.size(), vector<int>(_vec.size()));

	if (_vec.size() == _vec2.size()) {
		for (int i = 0; i < _vec.size(); i++) {
			for (int j = 0; j < _vec.size(); j++) {
				res[i][j] = _vec[i][j] + _vec2[i][j];
			}
		}

		return res;
	}
}

std::vector<std::vector<int>> subVec(std::vector<std::vector<int>> _vec, std::vector<std::vector<int>> _vec2) {
	std::vector<std::vector<int>> res(_vec.size(), vector<int>(_vec.size()));

	if (_vec.size() == _vec2.size()) {
		for (int i = 0; i < _vec.size(); i++) {
			for (int j = 0; j < _vec.size(); j++) {
				res[i][j] = _vec[i][j] - _vec2[i][j];
			}
		}

		return res;
	}
}

std::vector<std::vector<int>> multVec(std::vector<std::vector<int>> _vec, std::vector<std::vector<int>> _vec2) {
	std::vector<std::vector<int>> res(_vec.size(), vector<int>(_vec.size()));

	if (_vec.size() == _vec2.size()) {
		for (int i = 0; i < _vec.size(); i++) {
			for (int j = 0; j < _vec.size(); j++) {
				for (int k = 0; k < _vec.size(); k++){
					res[i][j] += _vec[i][k] * _vec2[k][j];
				}
			}
		}

		return res;
	}
}

int main() {

	int iMenu = -1;

	int mSize;
	std::cout << "Enter matrix size" << std::endl;
	std::cin >> mSize;

	std::vector<std::vector<int>> matrix(mSize, vector<int>(mSize));
	std::vector<std::vector<int>> matrix2(mSize, vector<int>(mSize));
	std::vector<std::vector<int>> matrix3(mSize, vector<int>(mSize));
	std::vector<std::vector<int>> res(mSize, vector<int>(mSize));


	while (iMenu != 0) {
		std::cout << "1 - input matrix A, 2 - input matrix B, 3 - input vector C, 4 - Add matrixes" << std::endl;
		std::cout << "5 - substract matrixes, 6 - multiply matrixes, 7 - multiply matrix on vector, 8 - transpose matrix, 0 - quit" << std::endl;
		std::cout << "Enter your command: ";
		std::cin >> iMenu;
		switch (iMenu) {
		case 0: {break; };
		case 1: {
			initVec(matrix);
			inputVec(matrix);
			printVec(matrix);
			break;
		}
		case 2: {
			initVec(matrix2);
			inputVec(matrix2);
			printVec(matrix2);
			break;
		}
		case 3: {
			inputVec2(matrix3);
			printVec2(matrix3);
			break;
		}
		case 4: {
			res = addVec(matrix, matrix2);
			printVec(res);
			break;
		}
		case 5: {
			res = subVec(matrix, matrix2);
			printVec(res);
			break;
		}
		case 6: {
			res = multVec(matrix, matrix2);
			printVec(res);
			break;
		}
		case 7: {
			int utilInt;
			std::cout << "Which matrix to utilise? 1 - A, 2 - B: ";
			cin >> utilInt;
			switch (utilInt) {
				case 1: {
					res = multVec(matrix, matrix3);
					printVec2(res);
					break;
				}
				case 2: {
					res = multVec(matrix2, matrix3);
					printVec2(res);
					break;
				}
			}
			break;
		}
		case 8: {
			int utilInt;
			std::cout << "Which matrix to transpose? 1 - A, 2 - B: ";
			cin >> utilInt;
			switch (utilInt) {
			case 1: {
				res = transpositionVec(matrix);
				printVec(res);
				break;
			}
			case 2: {
				res = transpositionVec(matrix2);
				printVec(res);
				break;
			}
			}
			break;
		}
		}
	}

	return 0;
}