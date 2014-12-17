#include <iostream>

#include "palidrome.h"

using namespace std;

void test(string input)
{
    Solution solution;
    if (solution.isPalindrome(input)) {
        cout<<"True";
    } else {
        cout<<"False";
    }
    return;
}

int main(int argc, char *argv[])
{
    string input;
    getline(cin, input);
    cout<<"testing..."<<input<<endl;
    test(input);
    return 0;
}

