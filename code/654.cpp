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
    int maxvalue(vector<int> nums)
    {
        int max = INT_MIN;
        int max_index = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(max < nums[i])
            {
                max = nums[i];
                max_index = i;
            }
        }
        return max_index;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        TreeNode* node = new TreeNode(0);
        if (nums.size() == 1) 
        {
            node->val = nums[0];
            return node;
        }
        int rootindex = maxvalue(nums);
        node->val = nums[rootindex];
        if(rootindex > 0) 
        {
            vector<int> newVec(nums.begin(), nums.begin() + rootindex);
            node->left = constructMaximumBinaryTree(newVec);
        }
        if(nums.size() - rootindex > 1)
        {
            vector<int> newVec(nums.begin() + rootindex + 1, nums.end());
            node->right = constructMaximumBinaryTree(newVec);
        }

        return node;
    }
};