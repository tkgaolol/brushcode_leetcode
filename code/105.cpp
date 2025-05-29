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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return NULL;
        unordered_map<int, int> index;
        for(int i = 0; i < inorder.size(); i++)
        {
            index[inorder[i]] = i;
        }
        return buildTreeHelper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1, index);
    }
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int preorderstart, int preorderend, int inorderstart, int inorderend, unordered_map<int, int>& index)
    {
        if(preorderstart>preorderend || inorderstart>inorderend) return nullptr;

        int rootvalue = preorder[preorderstart];
        TreeNode* root = new TreeNode(rootvalue);
        int rootindex = index[rootvalue];
        int leftsubtreesize = rootindex - inorderstart;
        root->left = buildTreeHelper(preorder, inorder, preorderstart + 1, preorderstart + leftsubtreesize, inorderstart, inorderstart + leftsubtreesize, index);
        root->right = buildTreeHelper(preorder, inorder, preorderstart + leftsubtreesize + 1, preorderend, rootindex + 1, inorderend, index);
        return root;
    }
};