class Solution {
public:
    //用size()函数时无符号的，用个有符号的变量存储可以简化代码和提高效率
    //用vector替换原来的数组灵活性高一点
    //还KMP还可以优化。而且还BM的方法也是线性时间。
    int strStr(string haystack, string needle) {
        int n1=haystack.size(), n2=needle.size();
        //if (n1==0||n2==0) return -1;//这个不行
        if (n2==0) return 0;//考虑"",""和"","a"
        vector<int> next(n2);
        int i,j;
        //获得next数组
        next[0]=-1;
        //n2-1注意减1否则next会越界，就是为什么下面种方法开vector失败的原因
        for (i=0,j=-1; i<n2-1&&j<n2;)
            if (j<0 || needle[i]==needle[j]) {i++; j++; next[i]=j;}
            else j=next[j];
        for (i=0,j=0; i<n1&&j<n2;)
            if (j<0 || haystack[i]==needle[j]) {i++; j++;}
            else j=next[j];
        if (j==n2) return i-j;
        else return -1;
    }
};

class Solution3 {
public://KMP算法，有两个小问题，在上面解决了
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
        //比较，注意needle.length是无符号的，j和它比较要被转换成无符号的，
        //-1对应的无符号是最大的
        for (i=0,j=0; i<haystack.size()&&j<(int)needle.size();)
            if (j<0 || haystack[i]==needle[j]) {i++; j++;}
            else j=next[j];
        //delete[] next;
        if (j==needle.size()) return i-j;
        else return -1;
    }
};

class Solution2 {
public://c函数库
    int strStr(string haystack, string needle) {
        int n1=haystack.size(), n2=needle.size();
        if (n1==0) return n2==0?0:-1;
        const char *p1=haystack.c_str();
        const char *p2=needle.c_str();
        const char *p=strstr(p1, p2);
        if (p) return p-p1;
        else return -1;
    }
};

class Solution1 {
public://BF大法
    int strStr(string haystack, string needle) {
        int n1=haystack.size(), n2=needle.size();
        int i=0, j=0;
        while (i<n1&&j<n2) {
            if (haystack[i]==needle[j]) {i++; j++;}
            else {i=i-j+1; j=0;}
        }
        if (j==n2) return i-j;
        else return -1;
    }
};