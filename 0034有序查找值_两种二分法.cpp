class Solution {
public:
    //STL有四个二分算法:equal_range
    //binary_search/equal_range/lower_bound/upper_bound
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={-1, -1};
        if (nums.empty()) return ans;
        auto pair = equal_range(nums.begin(), nums.end(), target);
        if (pair.first==nums.end() || *pair.first!=target) return ans;
        ans[0]=pair.first-nums.begin();
        ans[1]=pair.second-nums.begin()-1;
        return ans;
    }
};

class Solution4 {
public:
    //STL有四个二分算法:这里用后两个
    //binary_search/equal_range/lower_bound/upper_bound
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={-1, -1};
        if (nums.empty()) return ans;
        vector<int>::iterator it1, it2;
        //lower_bound是返回第一个target的位置或者是应该插入的位置
        it1 = lower_bound(nums.begin(), nums.end(), target);
        if (it1==nums.end() || *it1!=target) return ans;
        it2 = upper_bound(nums.begin(), nums.end(), target);
        ans[0]=it1-nums.begin();
        ans[1]=it2-nums.begin()-1;
        return ans;
    }
};

class Solution3 {
public://两个二分复杂度还是O(logn)，下面个有点别扭，改写下
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={-1, -1};
        if (nums.empty()) return ans;
        int i,j,mid;
        
        for (i=0, j=nums.size()-1; i<j;) {
            mid=(i+j)/2;
            if (nums[mid]<target) i=mid+1;
            else j=mid;
        }//这种写法重复值倾向于左边，且最后找没找到ij都在一起
        if (nums[i]==target) ans[0]=i;
        else return ans;//这里也是优化点，避免后边的运算
        
        for (j=nums.size()-1; i<j;) {//i不用回到0是个优化点
            mid=(i+j+1)/2;//为了倾向右边
            if (nums[mid]<=target) i=mid;
            else j=mid-1;
        }//这种写法重复值倾向于右边，且最后找没找到ij都在一起
        //if (nums[i]==target) ans[1]=i;
        ans[1]=i;//能走到这里一定是有值的
        
        return ans;
    }
};

class Solution2 {
public://两个二分复杂度还是O(logn)
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={-1, -1};
        if (nums.empty()) return ans;
        int i=0, j=nums.size()-1,mid;
        for (i=0, j=nums.size()-1; i<=j;) {
            mid=(i+j)/2;
            if (nums[mid]<target) i=mid+1;
            else j=mid-1;
        }
        if (i<nums.size()&&nums[i]==target) ans[0]=i;
        for (i=0, j=nums.size()-1; i<=j;) {
            mid=(i+j)/2;
            if (nums[mid]<=target) i=mid+1;
            else j=mid-1;
        }
        if (nums[j]==target) ans[1]=j;
        return ans;
    }
};

class Solution1 {
public://先来个BF虽然复杂度是O(n)
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={-1, -1};
        int i=0, j=nums.size()-1;
        if (nums.empty()) return ans;
        while (i<nums.size()&&nums[i]!=target) i++;
        while (j>=0&&nums[j]!=target) j--;
        if (j<0) return ans;
        ans[0]=i; ans[1]=j;
        return ans;
    }
};