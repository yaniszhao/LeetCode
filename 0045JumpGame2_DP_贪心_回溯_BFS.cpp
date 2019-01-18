class Solution {
public:
    //优化下，其实不用dp存储也可以，返回step就行了
    //贪心和DFS结合，step的形式一定是011122333444的样子
    int jump(vector<int>& nums) {
        int n=nums.size();
        int l=0, r=0, rmax=0, step=0;
        //也可在while里再套一个循环，只是写法不一样，区别不大
        while(l<=r&&l<n) {//(l,r)表示step都相同的区间
            rmax=max(rmax, l+nums[l]);//rmax最少也是上一层的r
            //为了避免恰好到最后一个点，造成返回值减1，所以在这处理了
            if (l==n-1) break;
            if (l==r) {r=rmax; step++;}
            l++;
        }    
        //在到达目标的前一层就提前退出了，所以step加1
        return step;
    }
};

class Solution4 {
public:
    //dp和贪心结合用DFS实现
    //dp[i]的形式一定是011122333444的样子就类似于BFS的算法
    int jump(vector<int>& nums) {
        int n=nums.size();
        int dp[n];//dp[i]表示0到i的最少跳数
        int l=0, r=0, rmax=0, step=0;
        while(l<=r&&l<n) {//(l,r)为dp值相同的区间
            dp[l]=step;
            rmax=max(rmax, l+nums[l]);//rmax最少也是上一层的r
            if (l==r) {r=rmax; step++;}
            l++;
        }    
        return dp[n-1];//说了一定有解可以直接返回
    }
};

class Solution3 {
public://dp这个是从前往后类似dijk算法
    int jump(vector<int>& nums) {
        int n=nums.size();
        int dp[n];//dp[i]表示0到i的最少跳数
        dp[0]=0;
        for(int i=1; i<n; i++)
            if (i<=nums[0]) dp[i]=1;
            else dp[i]=i;//设置一个最大值
        for (int i=0; i<n-1; i++)//每个结点去更新后面的点
            for (int k=1; k<=nums[i]&&i+k<n; k++)
                dp[i+k]=min(dp[i]+1, dp[i+k]);        
        return dp[n-1];//说了一定有解可以直接返回
    }
};

class Solution2 {
public://dp但是时间还是很高，主要是在循环里还有循环
    int jump(vector<int>& nums) {
        int n=nums.size();
        int dp[n];//dp[i]表示nums(i,n-1)的最小距离
        dp[n-1]=0;
        for (int i=n-2; i>=0; i--) {
            dp[i]=n-1-i;
            for (int k=1; k<=nums[i]; k++) {
                int next=i+k;
                if (next>=n) break;
                dp[i] = min(dp[next]+1, dp[i]);
            }
        }
        return dp[0];
    }
};

class Solution1 {
public://回溯法，超时了，这种题肯定可以用dp
    int dfs(vector<int>& nums, int i)
    {
        int n=nums.size()-1;
        if (i>=n) return 0;
        int min=n-i, num;
        for (int k=1; k<=nums[i]; k++) {//k个间隔
            num=dfs(nums, i+k);
            if (num<min) min=num;
        }
        return min+1;
    }
    
    int jump(vector<int>& nums) {
        return dfs(nums, 0);
    }
};
