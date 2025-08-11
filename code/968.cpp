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
private:
    int result;
    int traversal(TreeNode* root)
    {
        if(root ==NULL) return 2;
        int left = traversal(root->left);
        int right = traversal(root->right);
        if(left==2 & right ==2) return 0;
        else if(left == 0 || right == 0) 
        {   
            result++;
            return 1;
        }
        else return 2;

    }
public:
    int minCameraCover(TreeNode* root) {
        result = 0;
        if(traversal(root)==0) result ++;
        return result;
    }
};