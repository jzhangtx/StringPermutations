// StringPermutations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

void Permutations(std::string& str, size_t index, std::vector<std::string>& permutations)
{
    if (index == str.size())
    {
        permutations.push_back(str);
        return;
    }

    for (size_t i = index; i < str.size(); ++i)
    {
        std::swap(str[index], str[i]);
        Permutations(str, index + 1, permutations);
        std::swap(str[index], str[i]);
    }
}

std::vector<std::string> GetAllPermutations(std::string& s)
{
    std::vector<std::string> permutations;
    Permutations(s, 0, permutations);

    return permutations;
}

int main()
{
    while (true)
    {
        std::cout << "Enter your string (\"q\" to exit): ";
        std::string s;
        std::cin >> s;

        if (s == "q" || s == "Q")
            break;

        std::vector<std::string> permutations = GetAllPermutations(s);
        std::cout << permutations[0];
        for (size_t i = 1; i < permutations.size(); ++i)
        {
            std::cout << ", " << permutations[i];
        }
        std::cout << std::endl;
    }
}
