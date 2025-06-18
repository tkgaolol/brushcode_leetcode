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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return root;
        if(root->val == key)
        {
            if(root->left == NULL && root->right == NULL) 
            {
                delete root;
                return NULL;
            }
            else if(root->right == NULL)
            {
                auto temp = root->left;
                delete root;
                return temp;
            }
            else if(root->left == NULL)
            {
                auto temp = root->right;
                delete root;
                return temp;
            }
            else
            {
                auto temp = root->left;
                auto temp2 = root->left;
                while(temp2->right!=NULL)
                {
                    temp2 = temp2->right;
                }
                temp2->right = root->right;
                delete root;
                return temp;
            }
        }
        if(root->val > key) root->left = deleteNode(root->left, key);
        if(root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};