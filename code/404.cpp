/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return 0;
        int leftValue = 0;
        if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL)
        {
            leftValue = root->left->val;
        }
        return leftValue +sumOfLeftLeaves(root->left) +sumOfLeftLeaves(root->right);
    }
};