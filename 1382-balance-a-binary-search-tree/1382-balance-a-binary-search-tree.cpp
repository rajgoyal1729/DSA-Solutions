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
    TreeNode* createBST(vector<int>&arr, int s, int e)
    {
        if(s>e) return NULL;

        int mid=s+(e-s)/2;
        TreeNode* left=createBST(arr,s,mid-1);
        TreeNode* right=createBST(arr,mid+1,e);

        return new TreeNode(arr[mid],left,right);
    }
    vector<int>nums;
    vector<int>inorder(TreeNode* root)
    {
        if(!root) return nums;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
        return nums;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>arr=inorder(root);
        int size=arr.size();
        return createBST(arr,0,size-1);
    }
};