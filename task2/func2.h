#ifndef TASK2_H
#define TASK2_H

#include <iostream>
#include <vector>
#include <string>

struct Item{
    std::string name; //имя предмета
    int price; //цена предмета
};
class HashTable{
private:    //можно не прописывать так как классы изначально имеют модификатор доступа приват
    std::vector<std::vector<Item>> elements;    //вектор векторов, в котором хранится предмет
    int size;
    int numbers = 0;    //Количество элементов в таблице

    unsigned int hash(std::string name);

public:
    HashTable();
    HashTable(int size);
    ~HashTable();
    
    void insert(const std::string& name, int price);

    bool remove(const std::string& name);

    int find(const std::string& name);

    void print();

    int table_size();

    bool is_empty();
};  

#endif