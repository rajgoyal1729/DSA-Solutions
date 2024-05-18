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
    int ans=0;
    int dfs(TreeNode* root)
    {
        if(!root) return 0;
        int leftCoins=dfs(root->left);
        int rightCoins=dfs(root->right);
        ans+=abs(leftCoins)+abs(rightCoins);
        return (root->val-1)+leftCoins+rightCoins;
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return ans;
    }
};