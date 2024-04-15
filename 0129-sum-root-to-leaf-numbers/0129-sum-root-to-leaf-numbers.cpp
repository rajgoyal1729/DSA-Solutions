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
    int helper(TreeNode* root,int sum)
    {
        if(!root) return 0;
        sum=sum*10+root->val;
        if(!root->left && !root->right) return sum;
        return helper(root->left,sum)+helper(root->right,sum);
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int sum=0;
        return helper(root,sum);
    }
};