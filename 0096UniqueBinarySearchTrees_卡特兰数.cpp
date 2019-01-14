class Solution {
public:
    //卡特兰数
    int numTrees(int n) {
        long long ans=1, c=2*n;
        //不要写成ans*=(c-i)/(i+1)，否则无法保证top/bot一定整除
        for (int i=0; i<n; i++) ans=ans*(c-i)/(i+1);
        return ans/(n+1);
    }
    
    //卡特兰数
    int numTrees1(int n) {
        unsigned long long top=1, bot=1, c=2*n;
        for (int i=0; i<n; i++) {
            top*=(c-i);
            bot*=(i+1);
            if (top%bot==0) {//不消去部分积的话数值可能会溢出
                top/=bot;
                bot=1;
            }
        }
        return top/bot/(n+1);
    }
};
