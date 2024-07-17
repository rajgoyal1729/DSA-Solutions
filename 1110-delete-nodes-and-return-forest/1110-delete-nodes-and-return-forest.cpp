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
    vector<TreeNode*>ans;
    set<int>delete_set;
    TreeNode* solve(TreeNode*root,vector<TreeNode*>&ans,set<int>&delete_set,bool isroot)
    {
        if(!root) return NULL;
        bool deleted=delete_set.find(root->val)!=delete_set.end();
        if(isroot && !deleted) ans.push_back(root);
        root->left=solve(root->left,ans,delete_set,deleted);
        root->right=solve(root->right,ans,delete_set,deleted);
        return deleted?NULL:root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto &i:to_delete) delete_set.insert(i);
        solve(root,ans,delete_set,true);
        return ans;

    }
};