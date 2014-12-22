#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
    public:
        static vector<string> resultBox;
        string countAndSay(int n) {
            if (n < 1) {
                return "";
            }
            if (resultBox.size() == 0){
                resultBox.push_back("1");
            }
            for (vector<string>::size_type currentSize = resultBox.size(); currentSize < n; ++currentSize)
            {
                string lastOne = resultBox.back();
                string newOne;
                string::iterator it = lastOne.begin();
                char currentChar = *it;
                int counter = 1;
                for (++it; it != lastOne.end(); ++it) 
                {
                    if (currentChar != *it) {
                        stringstream ss;
                        ss<<counter;
                        ss<<currentChar;
                        newOne += ss.str();
                        counter = 1;
                        currentChar = *it;
                    } else {
                        ++counter;
                    }
                }
                stringstream ss;
                ss<<counter;
                ss<<currentChar;
                newOne += ss.str();
                resultBox.push_back(newOne);
            }
            return resultBox[n-1];
        }
};
vector<string> Solution::resultBox = vector<string>();
