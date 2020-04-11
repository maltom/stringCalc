#include "operations.h"

const int BOTH_POSITIVE = 0;
const int FIRST_NEGATIVE = 1;
const int SECOND_NEGATIVE = 2;
const int BOTH_NEGATIVE = 3;
const int FIRST_BIGGER = 0;
const int SECOND_BIGGER = 1;
const int BOTH_BIGGER = 2;

std::string conductCalc(std::vector<std::string> &words, int signs)
{
    for (auto &&in : words)
    {
        cutExcessZeroes(in);
    }

    std::string result = "";
    int widerNumber = biggerNumber(words, signs);
    if (words[2] == "+")
    {
        if (signs == BOTH_NEGATIVE)
        {
            result.push_back('-');
            result += addTwoNmbrs(words);
        }
        else if (signs == FIRST_NEGATIVE)
        {
            if (widerNumber == FIRST_BIGGER)
            {
                result.push_back('-');
                result += subTwoNmbrs(words);
            }
            else if (widerNumber == SECOND_BIGGER)
            {
                std::string temp = "";
                temp = words[0];
                words[0] = words[1];
                words[1] = temp;
                result += subTwoNmbrs(words);
            }
            else
            {
                result = "0.00";
            }
        }
        else if (signs == SECOND_NEGATIVE)
        {
            if (widerNumber == FIRST_BIGGER)
            {
                result += subTwoNmbrs(words);
            }
            else if (widerNumber == SECOND_BIGGER)
            {
                std::string temp = "";
                temp = words[0];
                words[0] = words[1];
                words[1] = temp;
                result.push_back('-');
                result += subTwoNmbrs(words);
            }
            else
            {
                result = "0.00";
            }
        }
        else if (signs == BOTH_POSITIVE)
        {
            result += addTwoNmbrs(words);
        }
    }

    else if (words[2] == "-")
    {
        if (signs == BOTH_NEGATIVE)
        {
            if (widerNumber == FIRST_BIGGER)
            {
                result.push_back('-');
                result += subTwoNmbrs(words);
            }
            else if (widerNumber == SECOND_BIGGER)
            {
                std::string temp = "";
                temp = words[0];
                words[0] = words[1];
                words[1] = temp;
                result += subTwoNmbrs(words);
            }
            else
            {
                result = "0.00";
            }
        }
        else if (signs == FIRST_NEGATIVE)
        {
            result.push_back('-');
            result += addTwoNmbrs(words);
        }

        else if (signs == SECOND_NEGATIVE)
        {
            result += addTwoNmbrs(words);
        }
        else if (signs == BOTH_POSITIVE)
        {
            if (widerNumber == FIRST_BIGGER)
            {
                result += subTwoNmbrs(words);
            }
            else if (widerNumber == SECOND_BIGGER)
            {
                std::string temp = "";
                temp = words[0];
                words[0] = words[1];
                words[1] = temp;
                result.push_back('-');
                result += subTwoNmbrs(words);
            }
            else
            {
                result = "0.00";
            }
        }
    }
    else if (words[2] == "*")
    {
        if ((signs == FIRST_NEGATIVE) || (signs == SECOND_NEGATIVE))
        {
            result.push_back('-');
        }
        result += mlpTwoNmbrs(words);
    }
    else if (words[2] == "/")
    {
        if ((signs == FIRST_NEGATIVE) || (signs == SECOND_NEGATIVE))
        {
            result.push_back('-');
        }
        if ((words[1] == "0.00") || (words[1] == "-0.00"))
        {
            std::cout << "Dzielenie przez 0!" << std::endl;
            throw std::runtime_error("error");
        }
        result += divTwoNmbrs(words);
    }
    cutExcessZeroes(result);
    return result;
}

std::string addTwoNmbrs(std::vector<std::string> words)
{
    auto it1 = words[0].rbegin();
    auto it2 = words[1].rbegin();

    char subSum = '0';
    char moving = '0';
    std::string result = "";
    for (int i = 0; !((it1 == words[0].rend()) && (it2 == words[1].rend()) && (moving == '0')); i++)
    {
        if (i != 2)
        {
            if ((it1 == words[0].rend()) && (it2 == words[1].rend()) && (moving != 0))
            {
                subSum = moving;
            }
            else if (it1 == words[0].rend())
            {
                subSum = '0' + *it2 - '0' + moving - '0';

                ++it2;
            }
            else if (it2 == words[1].rend())
            {
                subSum = '0' + *it1 - '0' + moving - '0';

                ++it1;
            }
            else
            {
                subSum = '0' + *it1 - '0' + *it2 - '0' + moving - '0';
                it1++;
                it2++;
            }

            if (subSum > 57)
            {
                subSum -= 10;
                moving = '1';
            }
            else
            {
                moving = '0';
            }

            if (i == 1)
            {
                std::string holder = "";
                holder.push_back('.');
                holder.push_back(subSum);

                result = holder + result;
            }
            else
            {
                std::string holder = "";
                holder.push_back(subSum);
                result = holder + result;
            }
        }
        else
        {
            it1++;
            it2++;
        }
    }

    return result;
}
std::string subTwoNmbrs(std::vector<std::string> words)
{

    auto it1 = words[0].rbegin();
    auto it2 = words[1].rbegin();

    char subSum = '0';
    char moving = '0';
    std::string result = "";
    for (int i = 0; !((it1 == words[0].rend()) && (it2 == words[1].rend()) && (moving == '0')); ++i)
    {
        if (i != 2)
        {
            if ((it1 == words[0].rend()) && (it2 == words[1].rend()) && (moving != 0))
            {
                subSum = moving;
            }
            else if (it2 == words[1].rend())
            {
                subSum = '0' + *it1 - '0' - (moving - '0');
                ++it1;
            }
            else
            {
                subSum = '0' + *it1 - '0' - (*it2 - '0') - (moving - '0');
                it1++;
                it2++;
            }

            if (subSum < 48)
            {
                subSum += 10;
                moving = '1';
            }
            else
            {
                moving = '0';
            }

            if (i == 1)
            {
                std::string holder = "";
                holder.push_back('.');
                holder.push_back(subSum);

                result = holder + result;
            }
            else
            {
                std::string holder = "";
                holder.push_back(subSum);
                result = holder + result;
            }
        }
        else
        {
            it1++;
            it2++;
        }
    }
    cutExcessZeroes(result);
    return result;
}
std::string mlpTwoNmbrs(std::vector<std::string> words)
{
    std::string result = "0.00";
    int l1 = words[0].length();
    int l2 = words[1].length();

    words[0].erase(l1 - 3, 1);
    words[1].erase(l2 - 3, 1);
    --l1;
    --l2;

    std::vector<std::string> subProducts(l2);

    for (int i = 0; i < l2; ++i)
    {
        char memo = words[1][l2 - 1 - i];
        char moving = '0';
        char subSum = 0;
        for (int j = 0; j < i; ++j)
        {
            subProducts[i].push_back('0');
        }
        for (auto j = words[0].rbegin(); !((j == words[0].rend()) && (moving == '0'));)
        {
            if ((j == words[0].rend()))
            {
                subSum = moving;
                moving = '0';
            }
            else
            {
                subSum = (memo - '0') * (*j - '0') + (moving - '0');
                moving = subSum / 10 + '0';
                subSum = subSum % 10 + '0';
                ++j;
            }
            subProducts[i] = subSum + subProducts[i];
        }
    }
    for (int i = 0; i < l2; ++i)
    {
        std::vector<std::string> temp(2);
        temp[0] = result;
        temp[1] = subProducts[i];
        temp[1].insert(temp[1].length() - 2, ".");
        result = addTwoNmbrs(temp);
    }
    result.erase(result.length() - 3, 3);
    result.insert(result.length() - 2, ".");
    cutExcessZeroes(result);
    return result;
}
std::string divTwoNmbrs(std::vector<std::string> words)
{

    std::vector<std::string> tempor1{words[0], "100.00"};
    std::vector<std::string> tempor2{words[1], "100.00"};

    words[0] = mlpTwoNmbrs(tempor1);
    words[1] = mlpTwoNmbrs(tempor2);

    std::string result = "";
    int l1 = words[0].length();
    int l2 = words[1].length();

    words[0].erase(l1 - 3, 1);
    std::vector<std::string> forMlp;
    forMlp.push_back(words[1]);
    std::string temp = "";

    for (auto i = words[0].begin(); i != words[0].end(); ++i)
    {
        if (temp == "0")
        {
            temp = *i;
        }
        else
        {
            temp.push_back(*i);
        }

        for (int j = 9; j >= 0; --j)
        {
            std::string temp2 = std::to_string(j) + ".00";
            forMlp.push_back(temp2);
            temp += ".00";
            temp2 = mlpTwoNmbrs(forMlp);
            std::vector<std::string> forCheck{temp, temp2};

            if ((biggerNumber(forCheck, BOTH_POSITIVE) == FIRST_BIGGER) || (biggerNumber(forCheck, BOTH_POSITIVE) == BOTH_BIGGER))
            {
                result += std::to_string(j);
                temp = subTwoNmbrs(forCheck);

                cutExcessZeroes(temp);
                forMlp.pop_back();
                temp.erase(temp.length() - 3, 3);
                break;
            }
            forMlp.pop_back();
            temp.erase(temp.length() - 3, 3);
        }
    }
    result.insert(result.length() - 2, ".");
    cutExcessZeroes(result);
    return result;
}