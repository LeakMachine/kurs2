#ifndef INCLUDE_BITFIELD_H_
#define INCLUDE_BITFIELD_H_

#include <iostream>


using namespace std;

using elem_type = unsigned char;

class TBitField {
private:
    size_t  bitLen;                      // ����� �������� ���� (������������ ���������� �������� ��-�� ��-��, �������)
    size_t  memLen;                      // ���-�� ���������, ����������� ��� �������� �������� ����
    elem_type* pMem;                     // ������ ��� ������������� �������� ����

    // ��������� ����
    size_t bitsInElem = std::numeric_limits<elem_type>::digits;
    size_t shiftSize = std::bit_width(bitsInElem - 1);

    // ��������� ������
    size_t GetMemIndex(size_t pos) const noexcept {        // ������ � p��� ��� ���� pos
        return pos >> shiftSize;
    }

    elem_type GetMemMask(size_t pos) const noexcept {      // ������� ����� ��� ���� pos
        return 1 << (pos & (bitsInElem - 1));
    }

public:
    // ������������ ������������ ����������
    TBitField(size_t _BitLen) {
        bitLen = _BitLen;
        memLen = (bitLen + bitsInElem - 1) >> shiftSize;
        pMem = new elem_type[memLen];
        memset(pMem, 0, memLen * sizeof(elem_type));
    }                                                    // ����������� ������������ ����
    TBitField(const TBitField& bf) {
        bitLen = bf.bitLen;
        memLen = bf.memLen;
        pMem = new elem_type[memLen];
        memcpy(pMem, bf.pMem, memLen * sizeof(elem_type));
    }                                                    // ����������� �����������
    TBitField(TBitField&& bf) noexcept {
        pMem = nullptr;
        swap(*this, bf);
    }                                                    // move-����������� (����������� ����������� bf � this)
    ~TBitField() {
        delete[] pMem;
    }                                                   // ����������
    TBitField& operator=(const TBitField& bf) {
        if (this == &bf)
            return *this;

        TBitField tmp(bf);
        swap(*this, tmp);
        return *this;
    }
    TBitField& operator=(TBitField&& bf) noexcept {
        if (this != &bf) {
            delete[] pMem;
            swap(*this, bf);
            delete[] bf.pMem;
        }
        return *this;
    }

    size_t size() const noexcept { return bitLen; }      // �������� ����� (�-�� �����)

    bool operator==(const TBitField& bf) const noexcept {
        if (bitLen != bf.bitLen)
            return false;

        for (size_t i = 0; i < memLen; i++) {
            if (pMem[i] != bf.pMem[i])
                return false;
        }
        return true;
    }
    bool operator!=(const TBitField& bf) const noexcept {
        return !(*this == bf);
    }

    bool test(size_t i) const {
        if (i >= bitLen)
            throw out_of_range("bit pos is out of range");
        return pMem[GetMemIndex(i)] & GetMemMask(i);
    }                                                   // �������� �������� ���� i
    void set(size_t i) {
        if (i >= bitLen)
            throw out_of_range("bit pos is out of range");
        pMem[GetMemIndex(i)] |= GetMemMask(i);
    }                                                   // ���������� ��� i
    void reset(size_t i) {
        if(i >= bitLen)
            throw out_of_range("bit pos is out of range");


        pMem[GetMemIndex(i)] &= ~GetMemMask(i);
    }                                                    // �������� ��� i

    TBitField  operator|(const TBitField& bf) {
        if (bitLen != bf.bitLen)
            throw length_error("TBitField objects have different size");

        TBitField tmp(*this);
        for (size_t i = 0; i < bf.memLen; i++)
            tmp.pMem[i] |= bf.pMem[i];
        return tmp;
    }                                                   // ���
    TBitField  operator&(const TBitField& bf) {
        int i, len = bitLen;
        if (bf.bitLen > len)
            len = bf.bitLen;
        TBitField temp(len);
        for (i = 0; i < memLen; i++)
            temp.pMem[i] = pMem[i];
        for (i = 0; i < bf.memLen; i++)
            temp.pMem[i] &= bf.pMem[i];
        return temp;
    }                                                   // �
    TBitField  operator~(void) {
        TBitField tmp(bitLen);
        for (int i = 0; i < bitLen; i++) {
            if (test(i) == 0) {
                tmp.set(i);
            }
            else {
                tmp.reset(i);
            }
        }
        return tmp;
    }                          // ���������


    // ����/�����
    friend void swap(TBitField& lhs, TBitField& rhs) noexcept {
        std::swap(lhs.bitLen, rhs.bitLen);
        std::swap(lhs.memLen, rhs.memLen);
        std::swap(lhs.pMem, rhs.pMem);
    }
    friend std::ostream& operator<<(std::ostream& ostr, const TBitField& bf) {
        size_t len = bf.size();
        for (size_t i = 0; i < len; i++) {
            if (bf.test(i))
                ostr << '1';
            else
                ostr << '0';
        }
        return ostr;
    }
};

#endif  // INCLUDE_BITFIELD_H_
