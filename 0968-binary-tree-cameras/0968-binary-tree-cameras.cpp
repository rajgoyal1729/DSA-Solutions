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
    int camera=0;
    int f(TreeNode* root)
    {
        if(!root) return 0;
        int l=f(root->left);
        int r=f(root->right);
        if(l==-1 || r==-1) 
        {
             camera++;
             return 1;
        }
        if(l==1 || r==1)
        {
            return 0;
        }
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        if(f(root)==-1) return camera+1;
        return camera;
    }
};