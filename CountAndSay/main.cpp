#include <iostream>
#include "CountAndSay.h"

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        Solution solution;
        cout<<solution.countAndSay(n)<<endl;
    }
    return 0;
}

