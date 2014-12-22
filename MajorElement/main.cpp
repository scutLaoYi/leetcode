#include <string>
#include <iostream>
#include <vector>

#include "MajorElement.h"

using namespace std;

int main()
{
    vector<int> num;
    int currentNum;
    Solution solution;
    while(cin>>currentNum)
    {
        num.push_back(currentNum);
    }
    cout<<solution.majorityElement(num);
}

