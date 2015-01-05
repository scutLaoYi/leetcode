#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

class Solution {
    public:
        int minPathSum(vector<vector<int> > &grid) {
            //Total sum of each grid
            vector<vector<int> > sum;

            int rowAmount = grid.size();
            int columnAmount = (grid[0]).size();
            for (int rowIt = 0; rowIt != rowAmount; ++rowIt) {
                //Temporary data for each row
                vector<int> currentRow;

                //The first row, just sum them all
                if (rowIt == 0) {
                    currentRow.push_back(grid[0][0]);
                    for (int columnIt = 1; columnIt != columnAmount; ++columnIt) {
                        currentRow.push_back(currentRow[columnIt-1]+grid[0][columnIt]);
                    }
                }
                else {
                    //Process each row
                    for (int columnIt = 0; columnIt != columnAmount; ++columnIt) {
                        if (columnIt == 0) {
                            currentRow.push_back(sum[rowIt-1][0]+grid[rowIt][0]);
                        } else {
                            int minSum = sum[rowIt-1][columnIt] < currentRow[columnIt-1] ? sum[rowIt-1][columnIt] : currentRow[columnIt-1];
                            minSum += grid[rowIt][columnIt];
                            currentRow.push_back(minSum);
                        }
                    }
                }

                sum.push_back(currentRow);
            }
            return sum.back().back();
        }
        void gridTest(vector<vector<int> > &grid)
        {
            for (vector<vector<int> >::iterator rit = grid.begin(); rit != grid.end(); ++rit) {
                for (vector<int>::iterator cit = (*rit).begin(); cit != (*rit).end(); ++cit) {
                    cout<<*cit<<' ';
                }
                cout<<endl;
            }
        }
};
