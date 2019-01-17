class Solution {
public:
    //STL有四个二分算法:lower_bound
    //binary_search/equal_range/lower_bound/upper_bound
    int searchInsert(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return it-nums.begin();
    }
};

class Solution3 {
public:
    //剪枝优化了一点点
    //注意若用while(i<=j)和i=mid+1和mid-1则ij可能有一个会越界
    //<=的形式只适合单值和一定能找到的情况，用我这种ij最后在一起且不会越界
    int searchInsert(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1;
        if (nums.empty()) return 0;
        while(i<j) {//注意没等号
            int mid=(i+j)/2;
            //无重复值所以相同直接可以返回
            if (nums[mid]==target) return mid;
            else if (nums[mid]<target) i=mid+1;
            else j=mid;//注意不减1
        }
        return target>nums[i] ? i+1 : i;
    }
};

class Solution2 {
public://常规二分写法，想用bsearch但是若没找到是返回空，没法判断
    int searchInsert(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1;
        if (nums.empty()) return 0;
        while(i<j) {
            int mid=(i+j)/2;
            if (nums[mid]<target) i=mid+1;
            else j=mid;
        }
        return target>nums[i] ? i+1 : i;
    }
};

class Solution1 {
public:
    //O(n)的复杂度，简单代码少
    int searchInsert(vector<int>& nums, int target) {
        int i=0;
        for (; i<nums.size()&&nums[i]<target; i++);
        return i;
    }
};