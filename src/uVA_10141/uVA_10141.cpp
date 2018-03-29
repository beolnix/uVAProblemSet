
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>
#include <unordered_map>
#include <vector>

namespace uVA_10141 
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

    std::string calculate(std::string& str) {
        std::vector<std::string> lines = split_string(str, "\n");
        std::string result_str = "";
        int rfpN = 0;

        for(std::vector<int>::size_type i = 0; i < lines.size() - 1; i++) {
            rfpN += 1;
            std::string line = lines[i];            
            int r, p;            
            sscanf(line.c_str(), "%d %d", &r, &p);
            // printf("DEBUG: starting new case with line: %s - req: %d, props: %d\n", line.c_str(), r, p);
            if (r == 0 && p == 0) {
                break;
            }
            
            i += r; //skip requirements        

            std::string bestProposalName = "";
            double bestPrice = 2000000000;
            int reqs = -1;            
            for (int pi = 0; pi < p; pi++) {    
                i += 1;            
                std::string propName = lines[i];
                // printf("DEBUG: parsing the proposal: %s\n", propName.c_str());

                double price = 0;
                int satisfiedReqNumber = 0;
                i += 1;

                std::vector<std::string> propDetails = split_string(lines[i], " ");
                sscanf(propDetails[0].c_str(), "%lf", &price);
                sscanf(propDetails[1].c_str(), "%d", &satisfiedReqNumber);

                // printf("DEBUG: parsed line %s - price %.2f req %d\n", lines[i].c_str(), price, satisfiedReqNumber);                
                if (satisfiedReqNumber > reqs) {
                    bestProposalName = propName;
                    reqs = satisfiedReqNumber;
                    bestPrice = price;
                } else if ((satisfiedReqNumber == reqs) && (price < bestPrice)) {
                    bestProposalName = propName;
                    reqs = satisfiedReqNumber;
                    bestPrice = price;
                }
                // skip satisfied reqs
                i += satisfiedReqNumber;
            }

            if (rfpN > 1) {
                result_str.append("\n");
            }
            char buffer[100];
            std::string prefix = "RFP #";
            sprintf(buffer, "%s%d\n", prefix.c_str(), rfpN);
            result_str.append(buffer);
            result_str.append(bestProposalName);
            result_str.append("\n");            
        }

        // printf("DEBUG: result str: \n%s\n\n", result_str.c_str());
        return result_str;
    }
}
