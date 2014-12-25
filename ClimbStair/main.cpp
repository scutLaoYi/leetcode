#include <iostream>
using std::cout;
using std::endl;

class Solution {
    public:
        int climbStairs(int x) {
            int buffer[10000];
            buffer[0] = 0;
            buffer[1] = 1;
            buffer[2] = 2;
            for(int i = 3; i <= x; ++i)
            {
                buffer[i] = buffer[i-1] + buffer[i-2];
            }
            return buffer[x];
        }
};

int main()
{
    Solution sl;
    for(int i = 0; i < 30; ++i)
    {
        cout<<sl.climbStairs(i)<<endl;
    }
}
