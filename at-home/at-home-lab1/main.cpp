#include <locale.h>

#define USE_SET 

#ifndef USE_SET 

import bitfield;
import std.core;

using std::cout;
using std::cin;
using std::setw;
using std::endl;

int main()
{
    int n, m, k, count;

    setlocale(LC_ALL, "Russian");
    cout << "������������ �������� ��������� ���������" << endl;
    cout << "              ������ ����������" << endl;
    cout << "������� ������� ������� ����� �������� - ";
    cin >> n;
    TSet s(n + 1);
    // ���������� ���������
    for (m = 2; m <= n; m++)
        s.InsElem(m);
    // �������� �� sqrt(n) � �������� �������
    for (m = 2; m * m <= n; m++)
        // ���� � � s, �������� �������
        if (s.IsMember(m))
            for (k = 2 * m; k <= n; k += m)
                if (s.IsMember(k))
                    s.DelElem(k);
    // ���������� � s �������� - ������� �����
    cout << endl << "������ ��������� ��������� �����" << endl << s << endl;
    cout << endl << "������ ������� �����" << endl;
    count = 0;
    k = 1;
    for (m = 2; m <= n; m++)
        if (s.IsMember(m))
        {
            count++;
            cout << setw(3) << m << " ";
            if (k++ % 10 == 0)
                cout << endl;
        }
    cout << endl;
    cout << "� ������ " << n << " ������ " << count << " �������" << endl;
}
#else

import set;
import std.core;

using std::cout;
using std::cin;
using std::setw;
using std::endl;

int main()
{
    int n, m, k, count;

    setlocale(LC_ALL, "Russian");
    cout << "������������ �������� ��������� �������� ����" << endl;
    cout << "             ������ ����������" << endl;
    cout << "������� ������� ������� ����� �������� - ";
    cin >> n;
    TBitField s(n + 1);
    // ���������� ���������
    for (m = 2; m <= n; m++)
        s.set(m);
    // �������� �� sqrt(n) � �������� �������
    for (m = 2; m * m <= n; m++)
        // ���� m � s, �������� �������
        if (s.test(m))
            for (k = 2 * m; k <= n; k += m)
                if (s.test(k))
                    s.reset(k);
    // ���������� � s �������� - ������� �����
    cout << endl << "������ ��������� ��������� �����" << endl << s << endl;
    cout << endl << "������ ������� �����" << endl;
    count = 0;
    k = 1;
    for (m = 2; m <= n; m++)
        if (s.test(m))
        {
            count++;
            cout << setw(3) << m << " ";
            if (k++ % 10 == 0)
                cout << endl;
        }
    cout << endl;
    cout << "� ������ " << n << " ������ " << count << " �������" << endl;
}

#endif