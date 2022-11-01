#ifndef INCLUDE_SET_H_
#define INCLUDE_SET_H_

#include <iostream>
#include "bitfield.h"

class TSet {
private:
	size_t maxPower;                       // ������������ �������� ���������
	TBitField bitField;                    // ������� ���� ��� �������� ������������������� �������
public:
	TSet(int mp) : maxPower(mp), bitField(mp) {};
	TSet(const TSet& s) : maxPower(s.maxPower), bitField(s.bitField) {};                   // ����������� �����������
	TSet(const TBitField& bf) : maxPower(bf.size()), bitField(bf) {}; //  ������ �������������
	operator TBitField() {
		TBitField tmp(bitField);
		return tmp;
	}                  // �������������� ���� � �������� ����

	size_t GetMaxPower(void) const noexcept { return maxPower; }

	void InsElem(size_t Elem) {
		if (Elem >= maxPower)
			throw out_of_range("elem is out of universe");
		bitField.set(Elem);
	}            // �������� ������� � ���������
	void DelElem(size_t Elem) {
		if (Elem >= maxPower)
			throw out_of_range("elem is out of universe");
		bitField.reset(Elem);
	}            // ������� ������� �� ���������
	bool IsMember(size_t Elem) const {
		return bitField.test(Elem);
	}     // ��������� ������� �������� � ���������

	TSet operator+ (const int Elem) {
		TSet tmp(bitField);
		tmp.InsElem(Elem);
		return tmp;
	}       // ����������� � ���������
	TSet operator- (const int Elem) {
		TSet tmp(bitField);
		tmp.DelElem(Elem);
		return tmp;
	}       // �������� � ���������
	TSet operator+ (const TSet& s) {
		if(maxPower != s.maxPower)
			throw length_error("TSet objects have different size");
		TSet tmp(bitField | s.bitField);
		return tmp;
	};        // �����������
	TSet operator* (const TSet& s) {
		if (this->maxPower >= s.maxPower)
		{
			TSet tmp(this->maxPower);
			tmp.bitField = this->bitField & s.bitField;
			return tmp;
		}
		else
		{
			TSet tmp(s.maxPower);
			tmp.bitField = this->bitField & s.bitField;
			return tmp;
		}
	}        // �����������
	TSet operator~ (void) {
		TSet tmp(~bitField);
		return tmp;
	}                 // ����������

	int operator== (const TSet& s) const {
		return bitField == s.bitField;
	}
	int operator!= (const TSet& s) const {
		return !(*this == s);
	}
	TSet& operator=(const TSet& s) {
		if (this != &s) {
			this->maxPower = s.maxPower;
			this->bitField = s.bitField;
		}
		return *this;
	}

	friend std::istream& operator>>(std::istream& in, TSet& bf) {
		string inpt;
		int n = bf.GetMaxPower();
		for (int i = 0; i < n; i++)
		{
			cout << i << "The element is included in the set?" << endl;
			in >> inpt;
			if (inpt == "+") {
				bf.InsElem(i);
			}
			else if (inpt == "-") {
				bf.DelElem(i);
			}
			else {
				throw ("You can only answer: '+' or  '-'");
			}
			cout << endl;
		}
	}
	friend std::ostream& operator<<(std::ostream& out, const TSet& bf) {
		size_t i, n;
		char ch = '{';
		n = bf.GetMaxPower();
		for (i = 0; i < n; i++) {
			if (bf.IsMember(i)) {
				out << ch << ' ' << i;
				ch = ',';
			}
		}
		out << " }";
		return out;
	}
};

#endif  // INCLUDE_SET_H_