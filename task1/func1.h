#ifndef FUNC1_H
#define FUNC1_H

#include <unordered_map>
#include <string>

extern std::unordered_map<std::string, std::string> Mymap;
extern int duplicates;

std::string hash(std::string surname);
void enrolled(std::string path);
void unenrolled(const std::string &surname);
void print(const std::unordered_map<std::string, std::string> &Mymap, int duplicates);
#endif