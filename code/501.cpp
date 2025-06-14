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
    int count;
    int maxcount;
    TreeNode* pre = NULL;
    vector<int> result;

    void searchBSTtree(TreeNode* cur)
    {
        if(cur==NULL) return;

        searchBSTtree(cur->left);

        if(pre == NULL) count = 1;
        else if(pre->val == cur->val) count++;
        else count = 1;

        pre = cur;

        if(count == maxcount) result.push_back(cur->val);
        
        if(count > maxcount)
        {
            maxcount = count;
            result.clear();
            result.push_back(cur->val);
        }

        searchBSTtree(cur->right);
        return;
    }
    
    vector<int> findMode(TreeNode* root) {
        count = 0;
        maxcount = 0;
        result.clear(); 
        searchBSTtree(root);
        return result;
    }
};