class Solution {
public://对区间a和b若开始位置字符相同，合并后代价为a+b-1
    int strangePrinter(string s) {
        int n=s.size();
        int i,j,k,len,val;
        if (n==0) return 0;
        int dp[n][n];
        //除主对角线的元素放到后面去设置最大值
        // for (i=0; i<n; i++)
        //     for (j=i; j<n; j++)
        //         dp[i][j] = i==j ? 1 : 100;
        for (i=0; i<n; i++) dp[i][i]=1;
        //每次斜着更新，一直更新到最后一个点
        for (len=1; len<n; len++)
            for (i=0; i<n; i++) {
                j=i+len;
                if (j>=n) break;
                dp[i][j]=100;//最多100个数
                for (k=i; k<j; k++) {
                    int val=dp[i][k]+dp[k+1][j];
                    if (s[i]==s[k+1]) val-=1;
                    dp[i][j]=min(dp[i][j], val);
                }
            }
        return dp[0][n-1];
    }
};

class Solution1 {
public://这个方法乱写的过不了
    int strangePrinter(string s) {
        int map[128]={0};
        int cnt=0;
        for (auto it : s) {
            if (map[it]==0) {
                cnt++;
                map[it]=1;
            }
        }
        return cnt;
    }
};
