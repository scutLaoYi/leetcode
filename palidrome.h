#include <string>
#include <cstdio>
#include <cctype>
using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            string::iterator left = s.begin();
            string::iterator right = s.end()-1;

            while(left < right) 
            {
                while(left != right) {
                    if (isalpha(*left) || isdigit(*left)){
                        break;
                    }
                    ++left;
                }
                while(right != left) {
                    if (isalpha(*right) || isdigit(*right)) {
                        break;
                    }
                    --right;
                }
                if (left == right) {
                    return true;
                }

                if (tolower(*left) != tolower(*right)) {
                    return false;
                }
                ++left;
                --right;
            }
            return true;
        }
};
