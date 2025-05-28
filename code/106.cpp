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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty()) return NULL;
        unordered_map<int, int> inorder_map;
        for(int i = 0; i<inorder.size(); i++)
        {
            inorder_map[inorder[i]] = i;
        }
        return buildTreeHelper(inorder, postorder, 0 ,inorder.size()-1, 0, postorder.size()-1, inorder_map);
    }

    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inorderstart, int inorderend, int postorderstart, int postorderend, unordered_map<int, int>& inorder_map)
    {
        if (inorderstart > inorderend || postorderstart > postorderend) {
            return nullptr;
        }
        int rootVal = postorder[postorderend];
        TreeNode* root = new TreeNode(rootVal);
        int rootindex = inorder_map[rootVal];
        int leftsubtreesize = rootindex - inorderstart;
        root->left = buildTreeHelper(inorder, postorder, inorderstart, rootindex - 1, postorderstart, postorderstart + leftsubtreesize - 1, inorder_map);
        root->right = buildTreeHelper(inorder, postorder, rootindex + 1, inorderend,  postorderstart + leftsubtreesize, postorderend - 1, inorder_map);
        return root;

    }
};