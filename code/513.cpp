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
    int findBottomLeftValue(TreeNode* root) {
        int result;
        if(root == NULL) return result;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* cur = que.front();
                que.pop();
                if(i==0) result = cur->val;
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return result;
    }
};










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
    int maxDepth = INT_MIN;
    int result;
    void traversal(TreeNode* node, int depth)
    {
        if(node->left == NULL && node->right == NULL)
        {
            if (depth > maxDepth) 
            {
                maxDepth = depth;
                result = node->val;
            }
        }
        if(node->left != NULL) traversal(node->left, depth+1);
        if(node->right != NULL) traversal(node->right, depth+1);
    }

    int findBottomLeftValue(TreeNode* root) {
        traversal(root, 0);
        return result;
    }
};