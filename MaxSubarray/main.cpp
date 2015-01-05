#include <iostream>
#include "MaxSubarray.h"

using namespace std;

int main()
{
    int buffer[100];
    int size;
    cin>>size;
    for (int i = 0; i != size; ++i) {
        cin>>buffer[i];
        }
    Solution solution;
    cout<<"result:"<<solution.maxSubArray(buffer, size);
}
