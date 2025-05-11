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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(root != NULL)
        {
            queue<TreeNode*> que;
            que.push(root);
            while(!que.empty())
            {
                int size = que.size();
                int max = INT_MIN;
                for(int i = 0; i < size; i++)
                {
                    TreeNode* cur = que.front();
                    que.pop();
                    if(cur->val >= max) max = cur->val;
                    if(cur->left) que.push(cur->left);
                    if(cur->right) que.push(cur->right);
                }
                result.push_back(max);
            }
        }
        return result;
    }
};