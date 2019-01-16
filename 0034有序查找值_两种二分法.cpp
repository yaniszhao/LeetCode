class Solution {
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
