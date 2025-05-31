#include <iostream>
#include "func2.h"

int main() {
    std::cout << "Создаем дефолтную таблицу из 10 корзин: " << std::endl;
    HashTable defaulttable;
    defaulttable.print();
    std::cout << "Размер таблицы: " << defaulttable.table_size() << std::endl;
    std::cout << "Создаем таблицу размером 3 и заполняем ее элементами: " << std::endl;
    HashTable table(3);
    std::cout << "Проверяем, пустая ли таблица: ";
    std::cout << "Размер таблицы: " << table.table_size() << std::endl;
    if(table.is_empty()) std::cout << "Таблица пустая" << std::endl;
    table.insert("Molotok", 500);
    table.insert("Gvozdi", 150);
    table.insert("Kraska", 700);
    std::cout << "Наполняем таблицу элементами: " << std::endl;
    table.print();
    std::cout << "Проверяем, пустая ли таблица: ";
    std::cout << "Размер таблицы: " << table.table_size() << std::endl;
    if(!table.is_empty()) std::cout << "Таблица наполнена" << std::endl;
    std::cout << "Пытаемся найти Gvozdi в таблице и вывести их цену, затем пытаемся найти abc в таблице: " << std::endl;
    std::cout << table.find("Gvozdi") << std::endl << table.find("abc");
    std::cout << std::endl << "Удаляем Molotok из таблицы: " << std::endl;
    table.remove("Molotok");
    std::cout << std::endl;
    table.print();
    return 0;
}