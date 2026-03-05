// https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string

#ifndef CPP_TG_LEET_1758_HPP
#define CPP_TG_LEET_1758_HPP

#include <string>
#include <iostream>

using namespace std;

namespace leetcode
{
    namespace problem_1758
    {
        int minOperations(string s)
        {
            int zeroOps = 0;
            int oneOps = 0;
            int len = s.length() / 2;

            for (int i = 0; i < len; ++i)
            {
                // ODD
                if (s.at(i * 2) == '0')
                {
                    ++oneOps;
                }
                else
                {
                    ++zeroOps;
                }

                // EVEN
                if (s.at(i * 2 + 1) == '0')
                {
                    ++zeroOps;
                }
                else
                {
                    ++oneOps;
                }
            }

            if (s.length() % 2)
            {
                if (s.back() == '0')
                {
                    ++oneOps;
                }
                else
                {
                    ++zeroOps;
                }
            }

            return zeroOps < oneOps ? zeroOps : oneOps;
        }

        void test(string s)
        {
            std::cout << s.c_str() << ": " << minOperations(s) << std::endl;
        }
    }
}

#endif // CPP_TG_LEET_1758_HPP