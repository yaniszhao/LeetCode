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
    //不用last而是用另外一个循环遍历一层
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> ans;
        vector<int> v;
        if (!root) return ans;
        que.push(root);
        while (!que.empty()) {
            int num=que.size();
            v.clear();
            for (int i=0; i<num; i++) {
                root=que.front(); que.pop();
                v.push_back(root->val);
                if (root->left) que.push(root->left);
                if (root->right) que.push(root->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};

class Solution1 {
    //用last标识一层的结尾结点
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> ans;
        vector<int> v;
        TreeNode* last=root;
        if (!root) return ans;
        que.push(root);
        while (!que.empty()) {
            root=que.front(); que.pop();
            v.push_back(root->val);
            if (root->left) que.push(root->left);
            if (root->right) que.push(root->right);
            if (root==last) {
                last=que.back();
                ans.push_back(v);
                v.clear();
            }
        }
        return ans;
    }
};