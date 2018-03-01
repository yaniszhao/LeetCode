class Solution {
public:
    //参考最高得票的代码，时间复杂度O(n)
    int lengthOfLongestSubstring(string s) {
        vector<int> map(128, -1);
        int maxlen=0, last=-1;
        for (int i=0; i<s.length(); i++) {
            //在last后面还有和当前值相同的值，更新last
            if (map[s[i]]>last) last=map[s[i]];
            map[s[i]]=i;
            maxlen=max(maxlen, i-last);
        }
        return maxlen;
    }
};

class Solution1 {
public:    
    bool isOk(string s, int st, int ed)
    {
        set<char> set;
        for (int i=st; i<ed; i++)
            if (set.find(s[i])==set.end()) set.insert(s[i]);
            else return false;
        return true;
    }
    
    //Brute Force暴力破解，复杂度O(n^3)
    int lengthOfLongestSubstring(string s) {
        bool flag=false;
        for (int i=1; i<=s.length(); i++) {
            flag=false;
            for (int j=0; j<=s.length()-i; j++)
                if (isOk(s, j, j+i)) {flag=true; break;}
            if (!flag) return i-1;
        }
                    
        return s.length();
    }
};
