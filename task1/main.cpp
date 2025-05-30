#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include "func1.h"

std::unordered_map<std::string, std::string> Mymap;
int duplicates = 0;// Определяем глобальные переменные

int main(){
    std::string filepath = "groupmates.txt";
    enrolled(filepath);
    std::string surname;
    while(true){
        std::cin>>surname;
        if(surname != "end") unenrolled(surname);
        else break;
    }
    print(Mymap,duplicates);
}