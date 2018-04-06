class Solution {
public:
    string reverseWords(string s) {
        int pos, last=0;
        for (pos=0; pos<s.size(); pos++) {
            if (s[pos]==' ') {
                reverse(begin(s)+last, begin(s)+pos);
                last=pos+1;
            }
        }
        reverse(begin(s)+last, begin(s)+pos);
        return s;
    }
};

class Solution1 {
public:
    string reverseWords(string s) {
        int pos, last=0;
        s+=' ';
        for (pos=0; pos<s.size(); pos++) {
            if (s[pos]==' ') {
                reverse(begin(s)+last, begin(s)+pos);
                last=pos+1;
            }
        }
        s.resize(pos-1);
        return s;
    }
};