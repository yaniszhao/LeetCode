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
public://之前的涉及重复的递归，用动态规划优化下，用map存储中间结果
    map<TreeNode*, int> dp;
    int rob(TreeNode* root)
    {
        int tval=0, val;
        if (!root) return 0;
        if (dp.find(root) != dp.end()) return dp[root];
        //孩子节点不选的时候，把后面的先加起来
        if (root->left) {
            tval += rob(root->left->left);
            tval += rob(root->left->right);
        }
        if (root->right) {
            tval += rob(root->right->left);
            tval += rob(root->right->right);
        }
        //判断选和不选时的最大值
        val = root->val + tval;//当前节点选的时候
        tval = rob(root->left) + rob(root->right);//不选当前
        dp[root] =  max(tval, val);
        return dp[root];
    }
};

class Solution3 {
public://可以优化一下选和不选
    int rob(TreeNode* root)
    {
        int tval=0, val;
        if (!root) return 0;
        //孩子节点不选的时候，把后面的先加起来
        if (root->left) {
            tval += rob(root->left->left);
            tval += rob(root->left->right);
        }
        if (root->right) {
            tval += rob(root->right->left);
            tval += rob(root->right->right);
        }

        val = root->val + tval;//当前节点选的时候
        tval = rob(root->left) + rob(root->right);//不选当前
        return tval > val ? tval : val;
    }
};

class Solution2 {
public://这个版本还要传参分选和不选，可以优化一下
    int countmax(TreeNode* root, int flag)
    {
        int tval, val, lval, rval;
        if (!root) return 0;
        tval = countmax(root->left, 1) + countmax(root->right, 1);
        if (!flag) return tval;
        else {
            lval= countmax(root->left, 0);
            rval= countmax(root->right, 0);
            val = root->val + lval + rval;
            return tval > val ? tval : val;
        }
    }
    
    int rob(TreeNode* root) {
        return countmax(root, 1);
    }
};

class Solution1 {
public://题目理解错了，以为没层找最大的那个相加就行了
    int rob(TreeNode* root) {
        queue<TreeNode*> que;
        int cnt=0, levelmax;
        TreeNode *last;
        if (!root) return 0;
        levelmax = root->val;
        last = root;
        que.push(root);
        while (!que.empty()) {
            root = que.front(); que.pop();
            if (root == last) {
                if (levelmax > 0 ) cnt += levelmax;
                levelmax = 0;
            }
            if (root->left) {
                que.push(root->left);
                if (root->left->val > levelmax)
                    levelmax = root->left->val;
            }
            if (root->right) {
                que.push(root->right);
                if (root->right->val > levelmax)
                    levelmax = root->right->val;
            }
        }
        return cnt;
    }
};
