#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>

std::vector<int> readFile(const std::string& archivo);
void printVector(const std::vector<int>& vec);
void startTimer();
void stopTimer();
bool isSorted(const std::vector<int>& vec);
void saveVectorToFile(const std::vector<int>& vec, const std::string& filename);

#endif