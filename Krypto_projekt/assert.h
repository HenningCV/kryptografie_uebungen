#pragma once
#include<iostream>
#include<string>
#include <tuple>

struct POINT;

void assertOutput(std::string expected, std::string current, std::string function, bool check);

void assertEqual(int expected, int current, std::string function);
 
void assertEqual(double expected, double current, std::string function);

void assertEqual(std::string expected, std::string current, std::string function);

void assertEqual(bool expected, bool current, std::string function);

void assertEqual(POINT expected, POINT current, std::string function);

void assertEqual(std::tuple<int, int, int> expected, std::tuple<int, int, int> current, std::string function);

void assertEqual(std::tuple<int, int> expected, int current, std::string function);

void outputTestResult();