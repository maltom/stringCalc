#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <iostream>
#include <vector>
#include <string>
#include "stringProcessing.h"

std::string conductCalc(std::vector<std::string> &words, int signs);
std::string addTwoNmbrs(std::vector<std::string> words);
std::string subTwoNmbrs(std::vector<std::string> words);
std::string mlpTwoNmbrs(std::vector<std::string> words);
std::string divTwoNmbrs(std::vector<std::string> words);

#endif