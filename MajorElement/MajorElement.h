#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int majorityElement(vector<int> &num) {
            //test(num);
            sort(num.begin(), num.end());
            //test(num);
            return num[num.size()/2];

        }
        void test(vector<int> &num) {
            for (vector<int>::iterator it = num.begin(); it != num.end(); ++it) {
                cout<<*it<<' ';
            }
            cout<<endl;
        }
};
