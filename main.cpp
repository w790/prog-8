
// #include <iostream>
// int main(){
//     std::cout<<"Hello lab8";
// }

#include <iostream>
#include <vector>
// Вашей семиколенной сестре Прасковье нужно помочь с развитием магазина строительных материалов. Она хочет создать такой справочник с ценами, чтобы она не листала его,
// а сразу находила цену на нужный товар. Реализуйте хэш-таблицу в виде класса HashTable,
// в котором реализованы методы добавления, удаления, поиска значения (цены) ключа (товара), проверки на пустую таблицу, получения размера таблицы. В конструкторе по умолчанию создаётся создаётся пустой объект на 10 позиций

struct Item{
    std::string name; //имя предмета
    int price; //цена предмета
};

class HashTable{
    std::vector<std::vector<Item>> elements;//вектор векторов, в котором хранится предмет
    int size;
    int numbers = 0; //Количество в таблице
    HashTable(){ //дефолтный конструктор
        size = 10;
        elements.resize(size);
    }
    HashTable(int size){ //недефолтный конструктор
        elements.resize(size);
    }
    void insert(const std::string& name, int price);   // добавляет товар с ценой

    bool remove(const std::string& name);    // удаляет товар по имени, возвращает успех

    int find(const std::string& name);       // возвращает цену товара.

};

// #include <iostream>
// #include <vector>
// #include <functional> // Для std::hash

// struct Item {
//     std::string name;
//     int price;
// };

// class HashTable {
//     std::vector<std::vector<Item>> elements; // Вектор векторов элементов
//     int size; // Количество корзин
//     int numbers = 0; // Количество элементов в таблице

//     // Хэш-функция для строк
//     size_t hash_function(const std::string& key) const {
//         return std::hash<std::string>{}(key);
//     }

// public:
//     // Конструктор по умолчанию (10 корзин)
//     HashTable() : size(10) {
//         elements.resize(size);
//     }

//     // Конструктор с заданным размером
//     explicit HashTable(int custom_size) : size(custom_size > 0 ? custom_size : 10) {
//         elements.resize(size);
//     }

//     // Добавление элемента
//     void insert(const std::string& name, int price) {
//         size_t index = hash_function(name) % size;
//         elements[index].push_back({name, price});
//         numbers++;
//     }

//     // Поиск элемента
//     int find(const std::string& name) const {
//         size_t index = hash_function(name) % size;
//         for (const auto& item : elements[index]) {
//             if (item.name == name) {
//                 return item.price;
//             }
//         }
//         return -1; // Возвращаем -1 если не найдено
//     }

//     // Удаление элемента
//     bool remove(const std::string& name) {
//         size_t index = hash_function(name) % size;
//         auto& bucket = elements[index];
        
//         for (auto it = bucket.begin(); it != bucket.end(); ++it) {
//             if (it->name == name) {
//                 bucket.erase(it);
//                 numbers--;
//                 return true;
//             }
//         }
//         return false;
//     }

//     // Проверка на пустоту
//     bool isEmpty() const {
//         return numbers == 0;
//     }

//     // Получение количества элементов
//     int getSize() const {
//         return numbers;
//     }

//     // Получение количества корзин (дополнительный метод)
//     int getBucketCount() const {
//         return size;
//     }
// };


























// #include <string>
// #include <vector>
// #include <fstream>
// #include <unordered_map>
// #include "task1.hpp"

// std::string hash(std::string value)
// { // функция хэширования
//     unsigned int hash = 0;
//     for (int i = 0; i < value.size(); ++i)
//     {
//         hash = hash * 19 + value[i]; // метод хэширования (имеющийся хэш умножается на 19, к нему добавляется номер i-го сивмола в ASCII)
//     }
//     std::string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
//     std::string result;
//     while (hash > 0)
//     {
//         result.push_back(alphabet[hash % 62]); // Добавление в строку символа, находящегося в ASCII по индексу, равному остатку от деления на 62 (Размер алфавита)
//         hash /= 62;
//     }
//     return result;
// }

// void enrolled(std::string filepath)
// {
//     std::ifstream file(filepath); // Открытие файла, создание потока ввода
//     std::string line;
//     while (std::getline(file, line))
//     { // перебор строк в файле
//         if (people.find(hash(line)) == people.end())
//         {                              // если найденной строки нет в словаре, people.find() вернет итератор на people.end()
//             people[hash(line)] = line; // Записываем в словарь
//         }
//         else
//             duples++; // записываем в дубликаты
//     }
// }

// void unenrolled(std::string surname)
// {
//     if (people.find(hash(surname)) == people.end())
//     {                                    // если найденной строки нет в словаре, people.find() вернет итератор на people.end()
//         people[hash(surname)] = surname; // Записываем в словарь
//     }
//     else
//         duples++; // записываем в дубликаты
// }

// void print(std::unordered_map<std::string, std::string> people, int duples)
// { // функция вывода
//     std::cout << "Duplicates: " << duples << std::endl;
//     std::cout << "voters: " << people.size() << std::endl;
//     for (auto element : people)
//     {
//         std::cout << element.second << std::endl;
//     }
// }