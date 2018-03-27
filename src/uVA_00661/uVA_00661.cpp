#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>
#include <vector>

namespace uVA_00661
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

    std::string calculate(std::string input) {
        std::vector<std::string> lines = split_string(input, "\n");
        std::string result = "";
        int seqNum = 0;        

        for(std::vector<int>::size_type i = 0; i < lines.size() - 1; i++) {            
            seqNum += 1;
            int n, m, c;
            sscanf(lines[i].c_str(), "%d %d %d", &n, &m, &c);
            // printf("DEBUG: n: %d; m: %d; c: %d\n", n, m, c);

            if (n == 0 && m == 0 && c == 0) {
                break;
            }                     
            // result.append(join.c_str());
            
            int fuseCorrupted = 0;
            int devicePower[n];      
            int deviceState[n];      
            for (int j = 0; j < n; j++) {
                i += 1;
                int power;
                sscanf(lines[i].c_str(), "%d", &power);
                devicePower[j] = power;
                deviceState[j] = 0;
                // printf("DEBUG: device %d initialized with %d power\n", j, devicePower[j]);
            }

            int currentPowerConsumption = 0;
            int maxPowerConsumption = 0;
            for (int j = 0; j < m; j++) {
                i += 1;
                int deviceIndex;
                sscanf(lines[i].c_str(), "%d", &deviceIndex);
                int increasedPower = devicePower[deviceIndex-1];

                if (deviceState[deviceIndex-1] == 0) {                    
                    deviceState[deviceIndex-1] = 1;
                    currentPowerConsumption += increasedPower;
                    // printf("DEBUG: device %d  with power %d turned on. total consumption %d.\n", deviceIndex-1, increasedPower, currentPowerConsumption);
                    if (currentPowerConsumption > c) {
                        fuseCorrupted = 1;                    
                    }
                    if (currentPowerConsumption > maxPowerConsumption) {
                        maxPowerConsumption = currentPowerConsumption;
                    }
                } else {
                    deviceState[deviceIndex-1] = 0;
                    currentPowerConsumption -= increasedPower;
                    // printf("DEBUG: device %d  with power %d turned off. total consumption %d.\n", deviceIndex-1, increasedPower, currentPowerConsumption);
                }
            }

            if (fuseCorrupted == 1) {
                char buffer[100];
                sprintf(buffer, "Sequence %d\n", seqNum);
                result.append(buffer);
                result.append("Fuse was blown.\n");                
            } else {
                char buffer[100];
                sprintf(buffer, "Sequence %d\n", seqNum);
                result.append(buffer);
                result.append("Fuse was not blown.\n");  
                char buffer2[100];
                sprintf(buffer2, "Maximal power consumption was %d amperes.\n", maxPowerConsumption);
                result.append(buffer2);
            }

            result.append("\n");            
        }

        // printf("DEBUG RESULT: %s\n", result.c_str());
        return result;
    }
}