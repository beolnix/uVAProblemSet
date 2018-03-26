#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits>
#include <unordered_map>
#include <vector>

namespace uVA_00119
{
    class Giver {
        int receivers_amount;
        int cache;
        public:
            Giver(int, int);
            Giver();
            int getReceiversAmount();
            int getCache();
    };

    Giver::Giver (int receivers_amount, int cache) {
        this->receivers_amount = receivers_amount;
        this->cache = cache;        
    }

    Giver::Giver() {
        this->receivers_amount = 0;
        this->cache = 0;
    }

    int Giver::getCache() {
        return this->cache;
    }

    int Giver::getReceiversAmount() {
        return this->receivers_amount;
    }

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
        this->amount = 0;
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
        std::string result_str = "";
        

        for(std::vector<int>::size_type i = 0; i < lines.size() - 1; i++) {
            /* std::cout << someVector[i]; ... */
            std::string line = lines[i];
            int number_of_participants;
            sscanf(line.c_str(), "%d", &number_of_participants);
            
            i += 1;
            std::vector<std::string> participant_names = split_string(lines[i], " ");
            
            std::vector<Participant> participants;
            std::unordered_map <std::string, Participant> resultMap;
            std::unordered_map <std::string, Giver> giverMap;

            // printf("DEBUG: %d number of participants\n", number_of_participants);
            for(std::vector<int>::size_type j = 0; j < number_of_participants; j++) {            
                i += 1;            
                std::vector<std::string> details = split_string(lines[i], " ");
                
                std::string name = details[0];
                int amount;
                sscanf(details[1].c_str(), "%d", &amount);
                int dest_number;
                sscanf(details[2].c_str(), "%d", &dest_number);                
                
                giverMap.insert(std::make_pair(name, Giver(dest_number, amount)));
                // printf("DEBUG: reading details<<<%s>>>\n", lines[i].c_str());

                if (dest_number < 1) {
                    continue;
                }

                for (int dest_index = 3; dest_index < dest_number + 3; dest_index++) {
                    std::string dest_name = details[dest_index];
                    int result_amount = amount;
                    if (result_amount != 0) {
                        result_amount = amount / dest_number;
                    }
                    
                    // printf("DEBUG: putting %d $ to %s\n", result_amount, dest_name.c_str());

                    std::pair<std::unordered_map<std::string,Participant>::iterator,bool> ret;
                    Participant p (dest_name, result_amount);
                    ret = resultMap.insert(std::make_pair(dest_name, p));
                    
                    if (ret.second == false) {
                        int prevAmount = (*ret.first).second.getAmount();
                        Participant pp (dest_name, prevAmount + (result_amount));
                        (*ret.first).second = pp;
                    }
                    
                }
            }
            
            for(std::vector<int>::size_type j = 0; j < number_of_participants; j++) {
                std::string name = participant_names[j];
                char buffer[100];

                int received = resultMap[name].getAmount();
                int left = 0;
                if (giverMap[name].getCache() != 0 && giverMap[name].getReceiversAmount() != 0) {
                    left = giverMap[name].getCache() % giverMap[name].getReceiversAmount();
                } else {
                    left = giverMap[name].getCache();
                }
                int result_amount = received + left - giverMap[name].getCache();
                
                // printf("%s\n", result_str.c_str());
                sprintf(buffer, "%s %d\n", name.c_str(), result_amount);                
                result_str.append(buffer);
            }            

            if (i < lines.size() - 2) {
                result_str.append("\n");
            }
                        
        }
        
        // printf("%s\n", result_str.c_str());
        return result_str;
    }
}

