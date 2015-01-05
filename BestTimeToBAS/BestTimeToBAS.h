#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        const int NEGATIVE_INFINITE;
        Solution():NEGATIVE_INFINITE(-99999999)
        {}
        int max(int a, int b, int c) {
            if (a > b) {
                if (a > c) {
                    return a;
                }
                return c;
            } else {
                if (b > c) {
                    return b;
                }
                return c;
            }
        }
            
        int maxProfit1(vector<int> &prices) {
            int days = prices.size();
            if (!days) {
                return 0;
            }
            int stocks = days;

            vector<int> dayProfit[2];
            dayProfit[0].push_back(0);
            dayProfit[0].push_back(-1 * prices[0]);
            for(int stock = 2; stock != stocks; ++stock) {
                dayProfit[0].push_back(NEGATIVE_INFINITE);
            }

            int curIndex = 0;
            for (int day = 1; day != days; ++day) {
                curIndex = 1-curIndex;
                vector<int> &currentDay = dayProfit[curIndex];
                vector<int> &passDay = dayProfit[1-curIndex];

                currentDay.clear();
                for (int stock = 0; stock != stocks; ++stock) {
                    int sell, buy;
                    sell = buy = NEGATIVE_INFINITE;
                    int nothing = passDay[stock];
                    if (stock != 0) {
                        buy = passDay[stock-1] - prices[day];
                    }
                    if (stock != stocks-1) {
                        sell = passDay[stock+1] + prices[day];
                    }

                    currentDay.push_back(max(sell, buy, nothing));
                }
            }
            return dayProfit[curIndex].front();
        }
        int maxProfit(vector<int> &prices) {
            if (!prices.size()) {
                return 0;
            }
            int min, max, profit;
            min = max = prices[0];
            profit = 0;
            for(vector<int>::iterator it = prices.begin(); it != prices.end(); ++it) {
                if (min > *it) {
                    min = *it;
                    max = min;
                } else if (max < *it) {
                    max = *it;
                }
                profit = (max-min) > profit ? (max-min) : profit;
            }
            return profit;
        }
};
