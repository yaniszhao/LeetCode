class Solution {
public://贪心算法，回溯和DP算法可以参考Jump GameII
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int dist=0;//能跳的最远距离
        for (int i=0; i<=dist&&dist<n-1; i++)
            if (i+nums[i]>dist) dist=i+nums[i];
        return dist>=n-1;
    }
};
