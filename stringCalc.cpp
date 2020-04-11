#include <iostream>
#include <vector>
#include <string>
#include "operations.h"

int main(int, char **)
{
std::cout<<"Enter equation in form like number-operation-number i.e. 10+20 or -10*-20 or 50.33-54.6842.\nNumbers can be positive or negative and are treated as fixed point numbers with two significant numbers.\n\n";

    std::string input;
    std::string result = "";
    std::getline(std::cin, input);
    std::vector<std::string> words(3);
    int signs = 0;
    words = numsAndSign(input, signs);
    try
    {
        words = adjustPoint(words);
    }
    catch (std::exception &e)
    {
        return -1;
    }
    try
    {
        result = conductCalc(words, signs);
    }
    catch (std::exception &e)
    {
        return -1;
    }
    std::cout << "Result: " << result << std::endl;
    return 0;
}


