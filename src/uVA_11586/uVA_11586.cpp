
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>
#include <unordered_map>
#include <vector>

namespace uVA_11586 
{

    std::vector<std::string> split_string(const std::string& str,
                                      const std::string& delimiter) {
        std::vector<std::string> strings;

        std::string::size_type pos = 0;
        std::string::size_type prev = 0;
        while ((pos = str.find(delimiter, prev)) != std::string::npos)
        {
            strings.push_back(str.substr(prev, pos - prev));
            prev = pos + 1;
        }

        // To get the last substring (or only, if delimiter is not found)
        strings.push_back(str.substr(prev));
        return strings;
    }

    std::string calculate(std::string& input) {
        std::vector<std::string> lines = split_string(input, "\n");
        std::string result = "";

        int n;
        sscanf(lines[0].c_str(), "%d", &n);
        if (n < 0) {
            result.append("\n");
            return result;
        }         

        for(std::vector<int>::size_type i = 1; i < lines.size() - 1; i++) {            
            std::vector<std::string> pieces = split_string(lines[i], " ");
            int m = 0;
            int f = 0;
            for(std::vector<int>::size_type j = 0; j < pieces.size(); j++) {
                if (pieces[j] == "MM") {
                    m += 2;
                } else if (pieces[j] == "FF") {
                    f += 2;
                } else if (pieces[j] == "FM") {
                    f += 1;
                    m += 1;
                } else if (pieces[j] == "MF") {
                    f += 1;
                    m += 1;
                }
            }

            if (f == m) {
                result.append("LOOP\n");
            } else {
                result.append("NO LOOP\n");
            }

        }

        return result;
    }
}
