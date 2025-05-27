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
    vector<vector<int>> result;
    vector<int> prefix;
    void traversal(TreeNode* root, int targetSum)
    {
        if(root->left == NULL && root->right == NULL)
        {
            if(targetSum==root->val)
            {
                result.push_back(prefix);
            }
        }
        if(root->left)
        {
            prefix.push_back(root->left->val);
            traversal(root->left, targetSum - root->val);
            prefix.pop_back();
        }
        if(root->right)
        {
            prefix.push_back(root->right->val);
            traversal(root->right, targetSum - root->val);
            prefix.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return result;
        prefix.push_back(root->val);
        traversal(root, targetSum);
        return result;
    }
};