#ifndef STRINGPROCESSING_H
#define STRINGPROCESSING_H

#include <iostream>
#include <vector>
#include <string>

void cutExcessZeroes(std::string &word);
int biggerNumber(std::vector<std::string> &words, int signs);
std::vector<std::string> numsAndSign(std::string input, int &signs);
std::vector<std::string> adjustPoint(std::vector<std::string> words);

#endif