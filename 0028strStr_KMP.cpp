class Solution {
public:
    int next[0xFFFF];//用vector或者malloc都会有问题，暂时还不清楚为什么
    int strStr(string haystack, string needle) {
        //int *next=new int[needle.size()];
        int i,j;
        if (needle.size()==0) return 0;
        //获得next数组
        next[0]=-1;
        for (i=0,j=-1; i<needle.size()&&j<(int)needle.size();)
            if (j<0 || needle[i]==needle[j]) {i++; j++; next[i]=j;}
            else j=next[j];
        //比较，注意needle.length是无符号的，j和它比较要被转换成无符号的，-1对应的无符号是最大的
        for (i=0,j=0; i<haystack.size()&&j<(int)needle.size();)
            if (j<0 || haystack[i]==needle[j]) {i++; j++;}
            else j=next[j];
        //delete[] next;
        if (j==needle.size()) return i-j;
        else return -1;
    }
};
