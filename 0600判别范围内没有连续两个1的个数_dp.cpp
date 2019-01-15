class Solution {
public:
    //dp[i]表示第i位上的1所表示的数即1000...包含自己满足条件的个数
    //对一个数如1xx100拆分成计算100000之前的个数和100000到1xx100的个数
    //前者为dp[hb]，若第二高位为0则除掉最高的两位后的值内满足的都可以
    //若第二高位为1则从第二高位开始后的数都不满足因为前两位已经为11了，
    //此时的值为dp[hb-1]-1因为11000...也是不满足的减掉一个。
    int highbit(int n) {
        int cnt=0;
        for (; n!=0; n>>=1) cnt++;
        return cnt;
    }
    
    int dp[33]={0};
    
    int count(int n) {
        int cnt=0;
        if (n<=2) return n;
        int hb=highbit(n);
        cnt=dp[hb];
        n -= (1<<(hb-1));
        if ((hb-1) == highbit(n)) cnt+=dp[hb-1]-1;
        else cnt+=count(n);
        return cnt;
    }
    
    int findIntegers(int num) {
        dp[1]=1; dp[2]=2;
        for (int i=3; i<=32; i++) dp[i]=dp[i-1]+dp[i-2];
        return count(num)+1;//count是没有算上0的
    }
};

class Solution1 {
public://BF大法好，但是超时了
    bool isOk(int n) {
        int magic=0x3;
        if (n==0||n==1||n==2) return true;
        while (magic!=0xC0000000) {
            //==优先级高于&所以要加括号，否则有问题
            if ((n&magic)==magic) return false;
            magic=magic<<1;
        }
        return true;
    }
    
    int findIntegers(int num) {
        int cnt=0;
        for (int i=0; i<=num; i++)
            if (isOk(i)) cnt++;
        return cnt;
    }
};
