#ifndef INCLUDE_BITFIELD_H_
#define INCLUDE_BITFIELD_H_

#include <iostream>


using namespace std;

using elem_type = unsigned char;

class TBitField {
private:
    size_t  bitLen;                      // длина битового поля (максимальное допустимое значение эл-та мн-ва, универс)
    size_t  memLen;                      // кол-во элементов, необходимое для хранения битового поля
    elem_type* pMem;                     // память для представления битового поля

    // служебные поля
    size_t bitsInElem = std::numeric_limits<elem_type>::digits;
    size_t shiftSize = std::bit_width(bitsInElem - 1);

    // служебные методы
    size_t GetMemIndex(size_t pos) const noexcept {        // индекс в pМем для бита pos
        return pos >> shiftSize;
    }

    elem_type GetMemMask(size_t pos) const noexcept {      // битовая маска для бита pos
        return 1 << (pos & (bitsInElem - 1));
    }

public:
    // обязательный классический функционал
    TBitField(size_t _BitLen) {
        bitLen = _BitLen;
        memLen = (bitLen + bitsInElem - 1) >> shiftSize;
        pMem = new elem_type[memLen];
        memset(pMem, 0, memLen * sizeof(elem_type));
    }                                                    // конструктор специального вида
    TBitField(const TBitField& bf) {
        bitLen = bf.bitLen;
        memLen = bf.memLen;
        pMem = new elem_type[memLen];
        memcpy(pMem, bf.pMem, memLen * sizeof(elem_type));
    }                                                    // конструктор копирования
    TBitField(TBitField&& bf) noexcept {
        pMem = nullptr;
        swap(*this, bf);
    }                                                    // move-конструктор (перемещение содержимого bf в this)
    ~TBitField() {
        delete[] pMem;
    }                                                   // деструктор
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

    size_t size() const noexcept { return bitLen; }      // получить длину (к-во битов)

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
    }                                                   // получить значение бита i
    void set(size_t i) {
        if (i >= bitLen)
            throw out_of_range("bit pos is out of range");
        pMem[GetMemIndex(i)] |= GetMemMask(i);
    }                                                   // установить бит i
    void reset(size_t i) {
        if(i >= bitLen)
            throw out_of_range("bit pos is out of range");


        pMem[GetMemIndex(i)] &= ~GetMemMask(i);
    }                                                    // очистить бит i

    TBitField  operator|(const TBitField& bf) {
        if (bitLen != bf.bitLen)
            throw length_error("TBitField objects have different size");

        TBitField tmp(*this);
        for (size_t i = 0; i < bf.memLen; i++)
            tmp.pMem[i] |= bf.pMem[i];
        return tmp;
    }                                                   // или
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
    }                                                   // и
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
    }                          // отрицание


    // ввод/вывод
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
