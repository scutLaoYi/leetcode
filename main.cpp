#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <list>

#include "BinaryTreeLevelOTII.h"

using namespace std;

TreeNode* newNodeWithValue(char value)
{
    TreeNode * tmpNode = new TreeNode(value-'0');
    return tmpNode;
}

TreeNode* buildNode(char value)
{
    if ('#' == value) {
        return NULL;
    }
    return newNodeWithValue(value);
}

TreeNode* build(char* input) 
{
    char* element = strtok(input, ",");
    TreeNode * root = newNodeWithValue(element[0]);

    list<TreeNode *> treeBuilder;
    treeBuilder.push_back(root);

    while(!treeBuilder.empty()) 
    {
        TreeNode *currentNode = treeBuilder.front();
        treeBuilder.pop_front();

        element = strtok(NULL, ",");
        if (!element) {
            break;
        }
        currentNode->left = buildNode(element[0]);
        if (currentNode->left) {
            treeBuilder.push_back(currentNode->left);
        }

        element = strtok(NULL, ",");
        if (!element) {
            break;
        }
        currentNode->right = buildNode(element[0]);
        if (currentNode->right) {
            treeBuilder.push_back(currentNode->right);
        }
    }

    return root;
}

void travelTree(TreeNode *root)
{
    if (!root) {
        return;
    }
    travelTree(root->left);
    cout<<root->val;
    travelTree(root->right);
}

void checkResult(vector<vector<int> > &result) 
{
    for(vector<vector<int> >::iterator it = result.begin(); it != result.end(); ++it)
    {
        for (vector<int>::iterator levelIt = (*it).begin(); levelIt != (*it).end(); ++levelIt)
        {
            cout<<*levelIt<<' ';
        }
        cout<<endl;
    }
}

int main(int argc, char *argv[])
{
    string input;
    getline(cin, input);
    char *inputCStr = new char[100];
    strcpy(inputCStr, input.c_str());
    cout<<"testing..."<<inputCStr<<endl;
    TreeNode *root = build(inputCStr);
    cout<<"get tree: ";
    travelTree(root);
    cout<<endl;
    cout<<"Getting result..."<<endl;
    Solution solution;
    vector<vector<int> > result = solution.levelOrderBottom(root);
    checkResult(result);

    return 0;
}

