#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>

namespace uVA_0272
{
    std::string replace(std::string& str) {
        char previousChar = ' ';
        bool opened = false;
        std::string result = "";
        for (char& c : str) {
            if (c == '"' && opened) {
                result += "''";
                opened = false;
            } else if (c == '"' && !opened) {
                result += "``";
                opened = true;
            } else {
                result += c;
            }
        }

        return result;
    }

}