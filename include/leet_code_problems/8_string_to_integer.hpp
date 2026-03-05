// https://leetcode.com/problems/string-to-integer-atoi/

#ifndef CPP_TG_LEET_8_HPP
#define CPP_TG_LEET_8_HPP

#include <iostream>
#include <string>

using namespace std;

namespace leetcode
{
    namespace problem_8
    {
        int myAtoi(string s)
        {
            int i = 0;
            int len = s.length();
            size_t number = 0;
            bool negative = false;

            if(len == 0) return number;

            // whitespace
            for(; i < len && s.at(i) == ' '; ++i);
            if(i >= len) return number;

            // sign
            if(s.at(i) == '-')
            {
                negative = true;
                ++i;
            }
            else if(s.at(i) == '+')
            {
                ++i;
            }
            if(i >= len) return number;

            // zeros
            for(; i < len && s.at(i) == '0'; ++i);
            if(i >= len) return number;

            // value
            int _charCount = 0;
            for(; i < len && s.at(i) >= '0' && s.at(i) <= '9'; ++i)
            {
                number = number * 10 + s.at(i) - 48;

                ++_charCount;
                if(_charCount > 10) return negative ? -__INT32_MAX__ - 1 : __INT32_MAX__;
            }

            if(number > __INT32_MAX__) return negative ? -__INT32_MAX__ - 1 : __INT32_MAX__;

            return number * (negative ? -1 : 1);
        }
    
        bool test(string s, int number)
        {
            int _parsed = myAtoi(s);
            bool valid = _parsed == number;

            std::cout << "string: " << s.c_str()
                << "\nExpected: " << number
                << " | Obtained: " << _parsed
                << (valid ? " ✓" : " ✗")
                << std::endl;

            return _parsed == number;
        }
    }
}

#endif //CPP_TG_LEET_8_HPP