#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>
#include <unordered_map>
#include <vector>

namespace uVA_00119
{
    class Participant {
        std::string name;
        int amount;

        public:
            Participant(std::string, int);
            Participant();
            int getAmount();
            std::string getName();            
    };

    Participant::Participant (std::string name, int amount) {
        this->name = name;
        this->amount = amount;
    }

    Participant::Participant () {
        this->name = "test";
        this->amount = -1;
    }

    int Participant::getAmount() {
        return this->amount;
    }

    std::string Participant::getName() {
        return this->name;
    }

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
        std::string result_str;
        

        for(std::vector<int>::size_type i = 0; i < lines.size(); i++) {
            /* std::cout << someVector[i]; ... */
            std::string line = lines[i];
            int number_of_participants;
            sscanf(line.c_str(), "%d", &number_of_participants);
            
            i += 1;
            std::vector<std::string> participant_names = split_string(lines[i], " ");
            
            std::vector<Participant> participants;
            std::unordered_map <std::string, Participant> resultMap;

            // printf("DEBUG: %d number of participants\n", number_of_participants);
            for(std::vector<int>::size_type j = 0; j < number_of_participants; j++) {
                i += 1;            
                std::vector<std::string> details = split_string(lines[i], " ");
                // printf("DEBUG: reading details<<<%s>>>\n", lines[i].c_str());
                std::string name = details[0];
                int amount;
                sscanf(details[1].c_str(), "%d", &amount);
                int dest_number;
                sscanf(details[2].c_str(), "%d", &dest_number);                
                for (int dest_index = 3; dest_index < dest_number + 3; dest_index++) {
                    std::string dest_name = details[dest_index];
                    int result_amount = amount;
                    if (result_amount != 0) {
                        result_amount = amount / dest_number;
                    }
                    
                    // printf("DEBUG: putting %d $ to %s\n", result_amount, dest_name.c_str());

                    std::pair<std::unordered_map<std::string,Participant>::iterator,bool> ret;
                    Participant p (dest_name, result_amount);
                    ret = resultMap.insert(std::make_pair(dest_name, p)); //doesnt get added
                    
                    if (ret.second == false) {
                        int prevAmount = (*ret.first).second.getAmount();
                        Participant pp (dest_name, prevAmount + (result_amount));
                        (*ret.first).second = pp;
                    }
                    
                }
            }
            //before result is printed calculate the diff right betwenn how much person gave and received.
            std::string result_str = "";
            for(std::vector<int>::size_type j = 0; j < number_of_participants; j++) {
                std::string name = participant_names[j];
                char buffer[100];
                
                sprintf(buffer, "%s %d\n", name.c_str(), resultMap[name].getAmount());
                // printf("DEBUG RESULT: %s %d\n", name.c_str(), resultMap[name].getAmount());
                result_str.append(buffer);
            }
            
            if (i+1 < lines.size()) {
                // printf("DEBUG NEXT: next line is<<<%s>>>\n", lines[i+1].c_str());
            }
        }

        return result_str;
    }


}