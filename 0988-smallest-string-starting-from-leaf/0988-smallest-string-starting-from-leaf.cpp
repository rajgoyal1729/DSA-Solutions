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
    void solve(TreeNode* root,vector<string>&ans,string temp)
    {
        if(!root) return;
        temp+=(root->val+'a');
        if(!root->left && !root->right)
        {
            ans.push_back(temp);
           
            return ;
        }
        if(root->left)solve(root->left,ans,temp+to_string(root->left->val+'a'));
        if(root->right)solve(root->right,ans,temp+to_string(root->right->val+'a'));
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string> ans;
        string res;
        solve(root,ans,"");
        
       //we need to reverse the vector as it stores the root to leaf paths and we need leaf to root paths
        for(int i=0;i<ans.size();i++)
        {
            reverse(ans[i].begin(),ans[i].end());
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans[0].length();i++)
        {
            if(!isdigit(ans[0][i])) res+=ans[0][i];
        }
        return res;
        

    }
};