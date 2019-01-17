class Solution {
public:
    //排序复杂度不满足，空间要求也不能用set或者hash。
    //遍历数组当前值下标不对应且不满足下面条件的要交换成对应值，
    //下标对应 或者 小于0 或者 是重复值 或者 大于可表示范围 直接往后走
    int firstMissingPositive(vector<int>& nums) {
        int i, n=nums.size();
        for (i=0; i<n;)
            if (nums[i]==i+1 || nums[i]<=0 ||\
               nums[nums[i]-1]==nums[i] || nums[i]>n) i++;
            else swap(nums[i], nums[nums[i]-1]);
        for (i=0; i<n&&nums[i]==i+1; i++);//最后要遍历一次判断
        return i+1;
    }
};

class Solution2 {
public://排序和去重的复杂度没法改，只有用二分优化查询，效果还不错
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        if (n==0) return 1;
        sort(nums.begin(), nums.end());//排序
        auto it= unique(nums.begin(), nums.end());//去重
        nums.resize(distance(nums.begin(),it));
        n=nums.size();
        it = lower_bound(nums.begin(), nums.end(), 1);//找到1
        int  st=it-nums.begin();
        if (nums[st]!=1) return 1;
        //二分查找
        int i=st, j=n-1;
        while (i<j) {
            int mid=(i+j)/2;
            if (nums[mid]==mid-st+1) i=mid+1;
            else j=mid;//有可能恰好是mid这个出错所以不减1
        }
        //有可能数组的值都是连续的，那么断掉的那个元素就应该放到最后+1的位置
        return nums[i]==i-st+1?nums[i]+1:i-st+1;
    }
};

class Solution1 {
public://效率感觉不是太高，主要排序和去重感觉话很多时间
    int firstMissingPositive(vector<int>& nums) {
        int cnt=1, n=nums.size();
        sort(nums.begin(), nums.end());//排序
        auto it= unique(nums.begin(), nums.end());//去重
        nums.resize(distance(nums.begin(),it));
        it = lower_bound(nums.begin(), nums.end(), 1);//找到1
        int i = it-nums.begin();
        for (; i<n&&nums[i]==cnt; i++, cnt++);
        return cnt;
    }
};
