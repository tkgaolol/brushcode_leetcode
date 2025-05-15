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
    int minDepth(TreeNode* root) {
        int result = 0;
        if(root != NULL)
        {
            queue<TreeNode*> que;
            que.push(root);
            while(!que.empty())
            {
                result++;
                int size = que.size();
                for(int i = 0; i< size; i++)
                {
                    TreeNode* cur = que.front();
                    que.pop();
                    if(!cur->left && !cur->right) return result;
                    if(cur->left) que.push(cur->left);
                    if(cur->right) que.push(cur->right);
                }
            }
        }
        return result;
    }
};