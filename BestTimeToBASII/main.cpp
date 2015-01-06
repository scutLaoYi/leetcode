#include <iostream>
#include <vector>
#include "MaxProfit.h"
using namespace std;

int main()
{
    vector<int> prices;
    int buffer;
    while(cin>>buffer) {
        prices.push_back(buffer);
    }
    Solution solution;
    cout<<solution.maxProfit(prices)<<endl;
}
