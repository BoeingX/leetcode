/**
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * For example, given the following binary tree:
 * 
 *    1
 *  /   \
 * 2     3
 *  \
 *   5
 * All root-to-leaf paths are:
 * 
 * ["1->2->5", "1->3"]
 */


//Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if(root == NULL)
            return paths;
        if(root->left == NULL && root->right == NULL){
            paths.push_back(to_string(root->val));
            return paths;
        }
        vector<string> tmp;
        paths = binaryTreePaths(root->left);
        tmp = binaryTreePaths(root->right);
        paths.insert(paths.end(), tmp.begin(), tmp.end());
        for(size_t i = 0; i < paths.size(); i++)
            paths[i] = to_string(root->val) + "->" + paths[i];
        return paths;
    }
};
