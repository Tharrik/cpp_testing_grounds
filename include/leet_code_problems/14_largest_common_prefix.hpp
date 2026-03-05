// https://leetcode.com/problems/longest-common-prefix/

#ifndef CPP_TG_LEET_14_HPP
#define CPP_TG_LEET_14_HPP

#include <string>
#include <vector>
#include <iostream>

using namespace std;

namespace leetcode
{
    namespace problem_14
    {
        string longestCommonPrefix(vector<string>& strs)
        {
            if(strs.size() == 0) return "";
            if(strs.size() == 1) return strs.at(0);

            string _prefix = "";
            string _lead = strs.front();

            for(int i = 0; i < _lead.length(); ++i)
            {
                char c = _lead.at(i);
                for(int j = 1; j < strs.size(); ++j)
                {
                    if(strs.at(j).length() <= i || strs.at(j).at(i) != c)
                    {
                        return _prefix;
                    }
                }
                _prefix += c;
            }

            return _prefix;
        }

        bool test(vector<string>& strs, string expected)
        {
            bool valid = longestCommonPrefix(strs) == expected;
            
            std::cout << "strings: ";
            for(int i = 0; i < strs.size(); ++i)
            {
                std::cout << strs.at(i).c_str() << " ";
            }
            std::cout << std::endl;

            std::cout << "Expected: " << expected.c_str() << " | Obtained: " << longestCommonPrefix(strs);
            std::cout << (valid ? " ✓" : " ✗") << std::endl;

            return valid;
        }
    }
}

#endif //CPP_TG_LEET_14_HPP