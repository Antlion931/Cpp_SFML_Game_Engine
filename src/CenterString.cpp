#include "Standard/CenterString.hpp"

std::string center(std::string input, int width)
{ 
    return std::string((width - input.length()) / 2, ' ') + input;
}