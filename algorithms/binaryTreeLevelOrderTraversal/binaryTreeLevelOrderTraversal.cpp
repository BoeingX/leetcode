/**
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
 * return its level order traversal as:
  [
    [3],
    [9,20],
    [15,7]
  ]
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> toVisit;
        vector<vector<int>> traversal;
        if(root != NULL){
            toVisit.push(root);
            while(!toVisit.empty()){
                vector<int> traversalLayer;
                //copy toVisit to tmp then empty toVisit
                //to store children of nodes in tmp
                queue<TreeNode*> tmp(toVisit);
                queue<TreeNode*>().swap(toVisit);
                while(!tmp.empty()){
                    TreeNode* present = tmp.front();
                    tmp.pop();
                    traversalLayer.push_back(present->val);
                    if(present->left != NULL)
                        toVisit.push(present->left);
                    if(present->right != NULL)
                        toVisit.push(present->right);
                }
                traversal.push_back(traversalLayer);
            }
        }
        return traversal;
    }
};

int main(){
    Solution solution;
    TreeNode t1(15), t2(7), t3(20), t4(9), t5(3);
    t3.left = &t1; t3.right = &t2;
    t5.left = &t4; t5.right = &t3;
    vector<vector<int>> traversal = solution.levelOrder(&t5);
    for(size_t i = 0; i < traversal.size(); i++){
        for(size_t j = 0; j < traversal[i].size(); j++)
            cout<<traversal[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
