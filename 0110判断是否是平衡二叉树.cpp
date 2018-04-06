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
public:
    void isblace(TreeNode* root, int &bla, int &h) 
    {
        int bla1, bla2, h1, h2;
        if (!root) {bla=1; h=0; return;}
        isblace(root->left, bla1, h1);
        isblace(root->right, bla2, h2);
        h=max(h1,h2)+1;
        if (bla1&&bla2&&abs(h1-h2)<2) {bla=1; return;}
        else {bla=0; return;}
    }
    
    bool isBalanced(TreeNode* root) {
        int bla,h;
        isblace(root, bla, h);
        return bla?true:false;
    }
};