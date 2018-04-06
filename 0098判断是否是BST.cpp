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
    //非递归算法
public:
    int flag=1,pre;
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        while (root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root=root->left;
            }
            else {
                root=stk.top(); stk.pop();
                if (flag) flag=0;
                else if (root->val<=pre) return false;
                pre=root->val;
                root=root->right;
            }
        }
        return true;
    }
};

class Solution1 {
    //速度太慢了
public:
    int flag=1,pre;
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (root->left&&!isValidBST(root->left)) return false;
        if (flag) flag=0;//第一次肯定是true
        else if (root->val<=pre) return false;
        pre=root->val;
        return isValidBST(root->right);
    }
};