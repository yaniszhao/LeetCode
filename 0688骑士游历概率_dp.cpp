class Solution {
public:
    //这种解法关键要看懂递推式,然后把k阶空间优化成2阶空间
    //dp[k[r][c]=∑(dp[k-1][r][c]/8.0))
    double knightProbability(int N, int K, int r, int c) {
        double dp[N][N], dp2[N][N];//本来应该是d[k][i][j]的，优化了
        int dr[]={2, 2, 1, 1, -1, -1, -2, -2};
        int dc[]={1, -1, 2, -2, 2, -2, 1, -1};
        double ans=0.0;
        
        memset((void*)dp, 0, sizeof(dp));
        dp[r][c]=1.0;
        for (; K>0; K--) {
            memset((void*)dp2, 0, sizeof(dp2));
            for (int i=0; i<N; i++) {
                for (int j=0; j<N; j++) {
                    for (int k=0; k<8; k++) {
                        int x=i+dr[k];
                        int y=j+dc[k];
                        if (x<0 || x>=N || y<0 || y>=N)
                            continue;
                        dp2[x][y] += dp[i][j]/8.0;
                    }
                }
            }
            memcpy((void*)dp, (void*)dp2, sizeof(dp));
        }
        
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
                ans+=dp[i][j];
        return ans;
    }
};

class Solution1 {
public://dfs会超时
    int dfs(int N, int K, int r, int c)
    {
        if (K<0) return 0;
        if (r<0 || r>=N || c<0 || c>=N) return 0;
        if (K==0) {return 1;};//最末一个点且未出界
        int cnt=0;
        cnt+=dfs(N, K-1, r-2, c-1);
        cnt+=dfs(N, K-1, r-2, c+1);
        cnt+=dfs(N, K-1, r-1, c-2);
        cnt+=dfs(N, K-1, r-1, c+2);
        cnt+=dfs(N, K-1, r+1, c-2);
        cnt+=dfs(N, K-1, r+1, c+2);
        cnt+=dfs(N, K-1, r+2, c-1);
        cnt+=dfs(N, K-1, r+2, c+1);
        return cnt;
    }
    
    double knightProbability(int N, int K, int r, int c) {
        int cnt=dfs(N, K, r, c);
        return (double)cnt/pow(8,K);
    }
};
