/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    //看了别人的解析，才发现这么简单
public:  
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root==p || root==q) return root;
        TreeNode* left=lowestCommonAncestor(root->left, p, q);
        TreeNode* right=lowestCommonAncestor(root->right, p, q);
        return !left?right:!right?left:root;
    }
};

class Solution1 {
    //这种方法行不通因为当f1和f2同时为true之后也无法马上确定哪个是公共结点
public:
    int f1=0,f2=0;
    
    void LCA(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &r)
    {
        if (!root) return;
        LCA(root->left, p, q, r);
        LCA(root->right, p, q, r);
        if (r) return;
        
        if (f1==1 && f2==1) {
            r=root;
            f1=f2=0;
        }
        else if (root==p) {
            if (f2==1) {r=root; f2=0;}
            else f1=1;
        }
        else if (root==q) {
            if (f1==1) {r=root; f1=0;}
            else f2=1;
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *r=NULL;
        LCA(root, p, q, r);
        return r?r:root;
    }
};