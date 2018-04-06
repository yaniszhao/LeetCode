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
    //非递归，last指针都省去了；用前插的话vector移动元素太多了，
    //用deque的话转成vector麻烦，还是用后插之后反转好点
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        while (root || !s.empty()){
            if (root) {
                ans.push_back(root->val);
                s.push(root);
                root=root->right;
            }
            else {
                root=s.top(); s.pop();
                root=root->left;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

class Solution4 {
    //非递归，王道版本
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* last=root;//初始为空也可以
        stack<TreeNode*> s;
        while (root || !s.empty()){
            if (root) {
                s.push(root);
                root=root->left;
            }
            else {//左孩子为空，或左孩子被访问，或右孩子被访问
                root=s.top();
                if (root->right&&last!=root->right) {
                    root=root->right;
                    s.push(root);//这两步可以不要牺牲一次循环
                    root=root->left;
                }
                else {
                    ans.push_back(root->val);
                    last=root;
                    s.pop();
                    root=NULL;//很重要
                }
            }
        }
        return ans;
    }
};

class Solution3 {
    //非递归版本，一个结点可能会被访问两次才出栈
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* last=root;//为了第一次好判断
        stack<TreeNode*> s;
        if (!root) return ans;
        s.push(root);
        while (!s.empty()){
            root=s.top();
            if (last==root->right || last==root->left \
                || (!root->left&&!root->right)) {
                //第二次进或第一次进但孩子都空，直接访问然后出栈
                ans.push_back(root->val);
                last=root;
                s.pop();
            }
            else {//第一次进且至少有个孩子不空，需要进第二次
                if (root->right) s.push(root->right);
                if (root->left) s.push(root->left);
            }
        }
        return ans;
    }
};

class Solution2 {
    //递归版本
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans, v;
        if (!root) return ans;
        v=postorderTraversal(root->left);
        ans.insert(ans.end(), v.begin(), v.end());//连接两个vector
        v=postorderTraversal(root->right);
        ans.insert(ans.end(), v.begin(), v.end());
        ans.push_back(root->val);
        return ans;
    }
};

class Solution1 {
    //递归版本
public:
    vector<int> ans;
    
    void postOrder(TreeNode* root)
    {
        if (!root) return;
        postOrder(root->left);
        postOrder(root->right);
        ans.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        postOrder(root);
        return ans;
    }
};