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
    int last = 0;
    void traversal(TreeNode* cur)
    {
        if(cur == NULL) return;
        traversal(cur->right);
        cur->val+=last;
        last = cur->val;
        traversal(cur->left);
        return;
    }

    TreeNode* convertBST(TreeNode* root) {
        last = 0;
        traversal(root);
        return root;
    }
};