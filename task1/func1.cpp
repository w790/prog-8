#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include "func1.h"

std::string hash(std::string surname){
    std::string result;
    unsigned int hash = 0;
    for (int i = 0;i<surname.size();i++){
        hash = hash*51+surname[i];
    }
    std::string alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");
    while (hash){
        result.push_back(alphabet[hash%alphabet.size()]);
        hash = hash/alphabet.size();
    }
    return result;
}

void enrolled(std::string path){
    std::ifstream surnames(path);
    std::string line;
    while(std::getline(surnames,line)){
        if (Mymap.find(hash(line)) == Mymap.end()){
            Mymap[hash(line)] = line;
        }
        else{
            duplicates+=1;
        } 
    }

}

void unenrolled(const std::string &surname){
    if (Mymap.find(hash(surname)) == Mymap.end()){
        Mymap[hash(surname)] = surname;
    }
    else{
        duplicates+=1;
    }
}
void print(const std::unordered_map<std::string, std::string> &Mymap, int duplicates){
    std::cout << "Duplicates: " << duplicates << std::endl; 
    std::cout << "Voters: " << Mymap.size() << std::endl;
    for(const auto &element : Mymap){
        std::cout << element.second << std::endl;
        }
}