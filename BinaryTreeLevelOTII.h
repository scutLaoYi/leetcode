/**
 * Definition for binary tree
 */
#include <vector>
#include <list>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

class Solution {
    public:
        vector<vector<int> > levelOrderBottom(TreeNode *root) {
            vector<vector<int> > result;
            if (!root) {
                return result;
            }
            list<TreeNode *> traveller[2];
            int currentLevel = 0;
            traveller[currentLevel].push_back(root); 

            while(true)
            {
                int nextLevel = currentLevel ? 0:1;
                vector<int> currentLevelResult;

                while(!traveller[currentLevel].empty())
                {
                    TreeNode *currentNode = traveller[currentLevel].front();
                    traveller[currentLevel].pop_front();
                    currentLevelResult.push_back(currentNode->val);
                    if (currentNode->left) {
                        traveller[nextLevel].push_back(currentNode->left);
                    }
                    if (currentNode->right) {
                        traveller[nextLevel].push_back(currentNode->right);
                    }
                }

                result.push_back(currentLevelResult);
                if (traveller[nextLevel].empty()) {
                    break;
                }
                currentLevel = nextLevel;
            }
            vector<vector<int> > revertResult;
            for (vector<vector<int> >::reverse_iterator it = result.rbegin(); it != result.rend(); ++it) {
                revertResult.push_back(*it);
            }
            return revertResult;
        }
};
