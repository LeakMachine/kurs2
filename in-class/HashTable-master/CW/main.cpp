#include "hashtable.h"
#include <vector>


int main() {

    HashTable hash1;
    HashTable hash2;
    HashTable hash3;
    HashTable hash4;


    std::vector<std::pair<std::string, int>> table1;
    std::vector<std::pair<std::string, int>> table2;

    table1.push_back({ "abazhur", 1 });
    table1.push_back({ "kinoteatr", 2 });
    table1.push_back({ "samolet", 3 });
    table1.push_back({ "chelovek", 4 });

    table2.push_back({ "kinoteatr", 15 });
    table2.push_back({ "muzyka", 16 });
    table2.push_back({ "samolet", 17 });

    for (int i = 0; i < table1.size(); i++) {
        hash1.insert(table1[i]);
    }

    for (int i = 0; i < table2.size(); i++) {
        if (hash1.find(table2[i]) != true)
            hash1.insert(table2[i]);
    }

    hash1.print();

    std::cout << "----------------" << std::endl;

    for (int i = 0; i < table2.size(); i++) {
        hash4.insert(table2[i]);
    }


    for (int i = 0; i < table1.size(); i++) {
        if (hash4.find(table1[i]) != true)
            hash4.insert(table1[i]);
    }

    hash4.print();

    return 0;
}