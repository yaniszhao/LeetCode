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
    string tree2str(TreeNode* t) {
        string s, ls, rs;
        if (!t) return s;
        s+=to_string(t->val);
        ls=tree2str(t->left);
        rs=tree2str(t->right);
        if (ls.size()==0&&rs.size()==0) return s;
        if (ls.size()==0) s+="()";
        else s.append("(").append(ls).append(")");
        if (rs.size()>0) s.append("(").append(rs).append(")");
        return s;
    }
};