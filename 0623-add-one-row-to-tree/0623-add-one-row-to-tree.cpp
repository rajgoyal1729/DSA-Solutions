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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* newnode=new TreeNode(val);
        if(depth==1)
        {
            newnode->left=root;
            return newnode;
        }
        queue<TreeNode*>q;
        q.push(root);
        int level=1;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(level==depth-1)
                {
                    TreeNode* newleft=new TreeNode(val);
                    TreeNode* newright=new TreeNode(val);
                    TreeNode* l=node->left;
                    TreeNode* r=node->right;
                    node->left=newleft;
                    node->right=newright;
                    node->left->left=l;
                    node->right->right=r;
                    
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            level++;
            if(level>=depth) return root;
        }
        return root;
    }
};