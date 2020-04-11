#include "stringProcessing.h"

const int BOTH_POSITIVE = 0;
const int FIRST_NEGATIVE = 1;
const int SECOND_NEGATIVE = 2;
const int BOTH_NEGATIVE = 3;
const int FIRST_BIGGER = 0;
const int SECOND_BIGGER = 1;
const int BOTH_BIGGER = 2;

void cutExcessZeroes(std::string &word)
{
    for (; (word[0] == '0');)
    {
        word.erase(0, 1);
    }
    if ((word[0] == '.') || (word[0] == ','))
        word = '0' + word;
    return;
}

int biggerNumber(std::vector<std::string> &words, int signs)
{
    if (signs == FIRST_NEGATIVE)
        words[0].erase(0, 1);
    else if (signs == SECOND_NEGATIVE)
        words[1].erase(0, 1);
    else if (signs == BOTH_NEGATIVE)
    {
        words[0].erase(0, 1);
        words[1].erase(0, 1);
    }

    if (words[0].length() > words[1].length())
    {
        return FIRST_BIGGER;
    }
    else if (words[0].length() < words[1].length())
    {
        return SECOND_BIGGER;
    }
    else
    {
        for (int i = 0; i < words[0].length(); ++i)
        {
            if (words[0][i] > words[1][i])
            {
                return FIRST_BIGGER;
            }
            else if (words[0][i] < words[1][i])
            {
                return SECOND_BIGGER;
            }
        }

        return BOTH_BIGGER;
    }
}

std::vector<std::string> numsAndSign(std::string input, int &signs)
{
    std::vector<std::string> words(3);
    bool token = true;
    bool beforeFirstNumber = true;

    for (int i = 0; i < input.length(); ++i)
    {
        if ((beforeFirstNumber == true) && (input[i] == '-'))
        {
            words[0].push_back('-');
            signs += FIRST_NEGATIVE;
        }
        else if ((!token) && (input[i] == '-'))
        {
            words[1].push_back('-');
            signs += SECOND_NEGATIVE;
        }
        else if (((input[i] > 47) && (input[i] < 58)) || (input[i] == 44) || (input[i] == 46))
        {
            if (token)
            {
                beforeFirstNumber = false;
                words[0].push_back(input[i]);
            }
            else
            {
                words[1].push_back(input[i]);
            }
        }
        else
        {
            switch (input[i])
            {
            case '+':
                words[2] = "+";
                token = false;
                break;
            case '-':
                words[2] = "-";
                token = false;
                break;
            case '*':
                words[2] = "*";
                token = false;
                break;
            case '/':
                words[2] = "/";
                token = false;
                break;
            }
        }
    }
    return words;
}
std::vector<std::string> adjustPoint(std::vector<std::string> words)
{
    std::vector<int> pointIndex(words.size());
    for (int i = 0; i < words.size() - 1; ++i)
    {
        pointIndex[i] = -1;
        int counter = 0;
        for (int j = 0; j < words[i].length(); ++j)
        {
            if (words[i][j] == '.' || words[i][j] == ',')
            {
                pointIndex[i] = j;
                ++counter;
            }
        }
        if (counter > 1)
        {
            std::cout << "Co najmniej jedna liczba jest bledna" << std::endl;
            throw std::runtime_error("error");
            return words;
        }
        if (pointIndex[i] != (-1))
        {
            int leng = words[i].length();
            for (int k = 2; k < (leng - 1 - pointIndex[i]); ++k)
            {
                words[i].pop_back();
            }
            if ((leng - 1 - pointIndex[i]) < 2)
            {

                if ((leng - 1 - pointIndex[i]) == 0)
                    words[i] += "00";
                else
                {
                    words[i] += "0";
                }
            }
        }
        else
        {
            if (words[i].empty())
                words[i] = "0.00";
            else
                words[i] += ".00";
        }
        if (words[i][0] == '.')
        {
            words[i] = "0" + words[i];
        }
    }

    std::cout << "First numnber: " << words[0] << std::endl;
    std::cout << "Second number: " << words[1] << std::endl;
    std::cout << "Operation: " << words[2] << std::endl;
    return words;
}