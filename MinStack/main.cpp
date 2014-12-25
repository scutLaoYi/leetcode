#include <iostream>
#include <assert.h>
#include "MinStack.h"

using namespace std;

void unitTest()
{
    MinStack testStack;
    for(int i = 1; i < 10; ++i)
    {
        testStack.push(i);
        cout<<"push"<<i<<" trace: ";
        testStack.trace();
    }
    for(int i = 1; i < 10; ++i) 
    {
        testStack.pop();
        cout<<"pop, trace: ";
        testStack.trace();
    }
    for(int i = 10; i > 0; --i)
    {
        testStack.push(i);
        cout<<"push"<<i<<" trace: ";
        testStack.trace();
        assert(testStack.getMin() == i);
        assert(testStack.top() == i);
    }
    testStack.push(-11);
    for(int i = 0; i < 10; ++i) 
    {
        testStack.push(i);
        cout<<"push"<<i<<" trace: ";
        testStack.trace();
        assert(testStack.getMin() == -11);
    }
    cout<<"ok"<<endl;
}

void againTest()
{
    MinStack testStack;
    testStack.push(2);
    testStack.trace();
    testStack.push(0);
    testStack.trace();
    testStack.push(3);
    testStack.trace();
    testStack.push(0);
    testStack.trace();
    testStack.pop();
    testStack.trace();
    testStack.pop();
    testStack.trace();
    testStack.pop();
    testStack.trace();
    testStack.pop();
    testStack.trace();
}
    

int main()
{
    unitTest();
    againTest();
    return 0;
}
