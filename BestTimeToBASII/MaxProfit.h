#include <vector>
using std::vector;

class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            int days = prices.size();
            if (!days) {
                return 0;
            }

            int dp[100][2];
            dp[0][0] = 0;
            dp[0][1] = -1 * prices[0];

            for (int day = 1; day != days; ++day)
            {
                dp[day][1] = dp[day-1][1];
                dp[day][0] = dp[day-1][0];
                for (int d = 0; d != day; ++d) {
                    dp[day][1] = max(dp[day][1], dp[d][0] - prices[day]);
                    dp[day][0] = max(dp[day][0], dp[d][1] + prices[day]);
                }
            }

            return dp[days-1][0];

        }
        int max(int a, int b) {
            return a > b ? a : b;
        }
};
