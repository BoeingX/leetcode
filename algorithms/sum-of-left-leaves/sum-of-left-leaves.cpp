/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeaves(root, false);
    }
    int sumOfLeftLeaves(TreeNode* root, bool isLeftChild) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL){
            if(isLeftChild)
                return root->val;
            return 0;
        }
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};
