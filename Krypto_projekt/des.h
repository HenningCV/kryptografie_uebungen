#pragma once
#include "desboxes.h"


std::string getKey(std::string keyPerm56, int round);
std::string Xor(std::string a, std::string b);
std::string sBoxSubstitution(std::string xored);
std::string permutation(const int matrix[], size_t arrayLength, std::string input);
std::string desFunction(std::string right, std::string key48);
std::string des(std::string input, std::string key);