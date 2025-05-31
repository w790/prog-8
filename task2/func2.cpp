#include <iostream>
#include <string>
#include <vector>
#include "func2.h"

    unsigned int HashTable::hash(std::string name){
        unsigned int hash = 0;
        for (int i = 0;i<name.size();i++){
            hash = hash*51+name[i];
        }
        return hash;
    }

    HashTable::HashTable(){    //дефолтный конструктор
        size = 10;
        elements.resize(size);
    }
    HashTable::HashTable(int size){    //недефолтный конструктор
        elements.resize(size);
    }
    HashTable::~HashTable(){   //деструктор
        elements.clear();
        numbers = 0;
    }
    
    void HashTable::insert(const std::string& name, int price){    // добавляет товар с ценой
        unsigned int hsh = hash(name);
        unsigned int index_in_hashtable = hsh%elements.size();
        for(Item &item : elements[index_in_hashtable]){     //Проверка элементов, сидящих по этому индексу
        if(item.name == name){      //Если нашли, то обновляем цену
            item.price = price;
            return;
        }
    }
        elements[index_in_hashtable].push_back({name,price});
        numbers++; //Добавляем к количеству
    }

    bool HashTable::remove(const std::string& name){       // удаляет товар по имени, возвращает успех ..Для удаления из вектора всегда используйте итераторы
        unsigned int hsh = hash(name);
        unsigned int index_in_hashtable = hsh%elements.size();
        auto& bucket = elements[index_in_hashtable];
        auto it = bucket.begin();
        bool removed=false;

        while (it != bucket.end()) {
            if (it->name == name) {
                it = bucket.erase(it);  // Получаем следующий валидный итератор
                numbers--;
                removed = true;
            } else {
                ++it;
            }
        }
        
        return removed;
    }

    int HashTable::find(const std::string& name){      // возвращает цену товара.
        unsigned int hsh = hash(name);
        unsigned int index_in_hashtable = hsh%elements.size();
        for(Item &item : elements[index_in_hashtable]){     //Проверка элементов, сидящих по этому индексу
            if(item.name == name){      //Если нашли, то обновляем цену
                return item.price;
            }
        }
        return -1;
    };

    void HashTable::print() { //Функция для вывода
    for(size_t i = 0; i < elements.size(); ++i) {
        std::cout << "Bucket " << i << ":\n";
        for(auto& item : elements[i]) {
            std::cout << "  " << item.name << " - " << item.price << " руб.\n";
        }
    }
}

    int HashTable::table_size(){ //Возврат размера
        return numbers;
    }

    bool HashTable::is_empty(){
        if(numbers == 0) return true;
        else return false;
    }