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
    //非递归层序
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> que;
        TreeNode* last=root;
        int dep=0;
        if (!root) return dep;
        que.push(root);
        while (!que.empty()) {
            root=que.front(); que.pop();
            if (root->left) que.push(root->left);
            if (root->right) que.push(root->right);
            if (root==last) {
                dep++;
                last=que.back();
            }
        }
        return dep;
    }
};

class Solution3 {
    //递归，更加简洁
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

class Solution2 {
    //递归，简化代码
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        return (left>right?left:right)+1;
    }
};

class Solution1 {
    //递归
public:
    int dep=0;
    void depth(TreeNode* root, int curdep)
    {
        if (!root) return;
        dep=curdep>dep?curdep:dep;
        depth(root->left, curdep+1);
        depth(root->right, curdep+1);
    }
    
    int maxDepth(TreeNode* root) {
        depth(root, 1);
        return dep;
    }
};