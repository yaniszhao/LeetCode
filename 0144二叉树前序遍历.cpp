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
    //非递归算法,推荐这个
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        while (root || !s.empty()) {
            if (root) {
                ans.push_back(root->val);
                s.push(root);
                root=root->left;
            }
            else {
                root=s.top(); s.pop();
                root=root->right;
            }
        }
        return ans;
    }
};

class Solution3 {
    //非递归算法
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        if (!root) return ans;
        s.push(root);
        while (!s.empty()) {
            root=s.top(); s.pop();
            ans.push_back(root->val);
            if (root->right) s.push(root->right);
            if (root->left) s.push(root->left);
        }
        return ans;
    }
};

class Solution2 {
    //递归算法，效率是最差的
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans, v;
        if (!root) return ans;
        ans.push_back(root->val);
        v=preorderTraversal(root->left);
        ans.insert(ans.end(), v.begin(), v.end());//连接两个vector的用法
        v=preorderTraversal(root->right);
        ans.insert(ans.end(), v.begin(), v.end());
        return ans;
    }
};

class Solution1 {
    //递归算法
public:
    vector<int> ans;
    
    void Preorder(TreeNode* root)
    {
        if (!root) return;
        ans.push_back(root->val);
        Preorder(root->left);
        Preorder(root->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        Preorder(root);
        return ans;
    }
};