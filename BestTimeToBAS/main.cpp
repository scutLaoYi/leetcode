#include <iostream>
#include <vector>
#include "BestTimeToBAS.h"
using namespace std;

int main()
{
    int buffer;
    vector<int> prices;
    while(cin>>buffer) {
        prices.push_back(buffer);
    }
    Solution solution;
    cout<<solution.maxProfit(prices)<<endl;
}
