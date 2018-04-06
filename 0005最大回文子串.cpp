class Solution {
public:    
    bool isPalindrome(string s, int st, int ed)
    {
        // int mid=(st+ed)/2;
        // for (int i=st; i<=mid; i++)
        //     if (s[i]!=s[ed+st-i])
        //         return false;
        // return true;
        //改进了下，更简洁
        while (st<ed) if (s[st++]!=s[ed--]) return false;
        return true;                
    }
    
    //暴力破解，复杂度O(n^3)
    string longestPalindrome(string s) {
        string ans;
        bool flag;
        for (int len=s.length(); len>=1; len--)//反着循环，否则有问题
            for (int i=0; i<=s.length()-len; i++)
                if (isPalindrome(s, i, i+len-1)) {
                    //ans.assign(s.begin()+i, s.begin()+i+len);
                    ans=s.substr(i, len);
                    return ans;
                }
        return ans;
    }
};