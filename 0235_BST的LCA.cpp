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
    //自己想的代码，没有那么简洁
public:
    int LCA(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &r)
    {
        if (!root) return 0;
        int left=LCA(root->left, p, q, r);
        int right=LCA(root->right, p, q, r);
        if (left==1 && right==1) {r=root; return 0;}
        else if (root==p || root==q) {
            if (left==1 || right==1) {r=root; return 0;}
            else return 1;
        }
        else return left+right;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* r=NULL;
        LCA(root, p, q, r);
        return r;
    }
};

class Solution1 {
    //参考的代码
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root==p || root==q) return root;
        TreeNode* left=lowestCommonAncestor(root->left, p, q);
        TreeNode* right=lowestCommonAncestor(root->right, p, q);
        return !left?right:!right?left:root;
    }
};