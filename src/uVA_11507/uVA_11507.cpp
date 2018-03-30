
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>
#include <unordered_map>
#include <vector>

namespace uVA_11507 
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

        for(std::vector<int>::size_type i = 0; i < lines.size() - 1; i++) {
            int n;
            sscanf(lines[i].c_str(), "%d", &n);
            if (n == 0) {
                break;
            }
            i += 1;

            int x, y, z;
            x = 1;
            y = 0;
            z = 0;

            // printf("DEBIG: executing actions %s\n", lines[i].c_str());

            std::vector<std::string> actions = split_string(lines[i], " ");            
            for(std::vector<int>::size_type j = 0; j < actions.size(); j++) {

                // printf("DEBUG: before command %s: %d,%d,%d\n", actions[j].c_str(), x,y,z);
                if ("No" == actions[j]) {
                    continue;
                } else if ("+y" == actions[j]) {
                    if (x == 1) {
                        x = 0;
                        y = 1;
                        z = 0;
                    } else if (x == -1) {
                        x = 0;
                        y = -1;
                        z = 0;
                    } else if (y == 1) {
                        x = -1;
                        y = 0;
                        z = 0;                    
                    } else if (y == -1) {
                        x = 1;
                        y = 0;
                        z = 0;
                    }                     
                } else if ("-y" == actions[j]) {
                    if (x == 1) {
                        x = 0;
                        y = -1;
                        z = 0;
                    } else if (x == -1) {
                        x = 0;
                        y = 1;
                        z = 0;
                    } else if (y == 1) {
                        x = 1;
                        y = 0;
                        z = 0;
                    } else if (y == -1) {
                        x = -1;
                        y = 0;
                        z = 0;
                    }
                } else if ("+z" == actions[j]) {
                    if (x == 1) {
                        x = 0;
                        y = 0;
                        z = 1;
                    } else if (x == -1) {
                        x = 0;
                        y = 0;
                        z = -1;
                    } else if (z == 1) {
                        x = -1;                        
                        y = 0;
                        z = 0;
                    } else if (z == -1) {
                        x = 1;                        
                        y = 0;
                        z = 0;
                    }
                } else if ("-z" == actions[j]) {
                    if (x == 1) {
                        x = 0;
                        y = 0;
                        z = -1;
                    } else if (x == -1) {
                        x = 0;
                        y = 0;
                        z = 1;
                    } else if (z == 1) {
                        x = 1;                        
                        y = 0;
                        z = 0;
                    } else if (z == -1) {
                        x = -1;                        
                        y = 0;
                        z = 0;
                    }
                }
                // printf("DEBUG: after command %s: %d,%d,%d\n", actions[j].c_str(), x,y,z);
            }

            if (x > 0) {
                result.append("+x\n");
            } else if (x < 0) {
                result.append("-x\n");
            } else if (y > 0) {
                result.append("+y\n");                
            } else if (y < 0) {
                result.append("-y\n");                
            } else if (z > 0) {
                result.append("+z\n");
            } else if (z < 0) {
                result.append("-z\n");
            }
        }

        return result;
    }
}
