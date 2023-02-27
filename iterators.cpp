#include <vector>
#include <iostream>
#include <set>
#include "iterators.h"

//--------------------------------------------------------------------------------

namespace it {

void print_left_than (const std::vector<int>& data, const int num) {
    if (std::find(data.begin(), data.end(), num) == data.end())
        return;
    
    using cit_t = std::vector<int>::const_iterator;
    
    cit_t initial_to_print = data.cbegin();
    for (auto cit = data.cbegin(); cit != data.cend(); ++cit) {
        if (*cit > num) {
            initial_to_print = cit;
            break;
        }
    }

    for (auto cit = initial_to_print; cit != data.cbegin() - 1; --cit)
    {
        std::cout << *cit << "\n";
    }
}

//--------------------------------------------------------------------------------

std::vector<std::string> split_str (std::string str, const char delimeter) {

    std::string cur_token;
    std::vector<std::string> result_tokens;

    for (auto it : str) {
        if (it == delimeter) {
            result_tokens.push_back(cur_token);
            cur_token.clear();        
            continue;
        }
        cur_token.push_back(it);
    }

    if (!cur_token.empty() and cur_token[0] != delimeter)
        result_tokens.push_back(cur_token);
    
    return result_tokens;
}

} // namespace it