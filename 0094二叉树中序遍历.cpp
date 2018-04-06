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
    //非递归算法,推荐这个看着清爽一些
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                root=root->left;
            }
            else {
                root=s.top(); s.pop();
                ans.push_back(root->val);
                root=root->right;
            }
        }
        return ans;
    }
};

class Solution3 {
    //非递归算法
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            if (s.top()) s.push(s.top()->left);
            else {
                s.pop();
                if (s.empty()) break;
                root=s.top(); s.pop();
                ans.push_back(root->val);
                s.push(root->right);
            }
        }
        return ans;
    }
};

class Solution2 {
    //递归版本
public:  
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans, v;
        if (!root) return ans;
        v=inorderTraversal(root->left);
        ans.insert(ans.end(), v.begin(), v.end());//连接两个vector
        ans.push_back(root->val);
        v=inorderTraversal(root->right);
        ans.insert(ans.end(), v.begin(), v.end());
        return ans;
    }
};

class Solution1 {
    //递归版本
public:
    vector<int> ans;
    
    void Inorder(TreeNode* root)
    {
        if (!root) return;
        Inorder(root->left);
        ans.push_back(root->val);
        Inorder(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        Inorder(root);
        return ans;
    }
};