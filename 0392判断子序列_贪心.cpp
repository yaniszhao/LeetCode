class Solution {
public:
    //好像还能二分？？？
    //O(n)的算法，为什么效率并不是很高
    bool isSubsequence(string s, string t) {
        int i=0, n=s.size();
        for (auto c:t) if (i<n&&c==s[i]) i++;//注意i<n
        return i==n;
    }
};

class Solution1 {
public://O(n)的算法
    bool isSubsequence(string s, string t) {
        int i=0, j=0, ns=s.size(), nt=t.size();
        while (i<ns&&j<nt) if (t[j++]==s[i]) i++;
        return i==ns;
    }
};