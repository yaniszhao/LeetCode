class Solution {
public:
    //LCP问题，方法有水平扫描、垂直扫描、二分、分治
    //我这里用的垂直扫描，其他方法有空可以研究下
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        if (strs.size()==0) return ans;
        for (int i=0; ; i++) {//退出条件在下面个循环的if条件
            for (int j=0; j<strs.size(); j++) {
                if (i==strs[j].size() || strs[j][i]!=strs[0][i])
                    return ans;
            }
            ans+=strs[0][i];
        }
    }
};
