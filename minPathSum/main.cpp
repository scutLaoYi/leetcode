#include <cstdio>
#include <vector>
#include <iostream>

#include "MinPathSum.h"

using namespace std;

void gridTest(vector<vector<int> > &grid)
{
    for (vector<vector<int> >::iterator rit = grid.begin(); rit != grid.end(); ++rit) {
        for (vector<int>::iterator cit = (*rit).begin(); cit != (*rit).end(); ++cit) {
            cout<<*cit<<' ';
        }
        cout<<endl;
    }
}

int main()
{
    int row, column;
    cin>>row>>column;
    cout<<"init a grid with "<<row<<" * "<<column<<endl;
    vector<vector<int> > grid;
    int buffer;
    for (int r = 0; r != row; ++r) {
        vector<int> currentRow;
        for (int c = 0; c != column; ++c) {
            cin>>buffer;
            currentRow.push_back(buffer);
        }
        grid.push_back(currentRow);
    }
    Solution solution;
    cout<<"result: "<<solution.minPathSum(grid);

}

