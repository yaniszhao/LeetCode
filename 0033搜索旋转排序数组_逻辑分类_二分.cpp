class Solution {
public:
    //这题有点考逻辑费了些时间分类，要把类分清楚就好做了
    //其实每组数据应该都有nums[j]<nums[i]，所以应该省略
    //上面的省略不是太严谨，应该是nums[j]<nums[i]&&nums[mid]<nums[i]一定不会成立
    int search(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1;
        if (nums.size()==0) return -1;
        while (i<j) {
            int mid=(i+j)/2;
            if (nums[mid]==target) i=j=mid;
            else if (nums[mid]<target)
                //if (nums[j]<nums[i]&&nums[mid]<nums[i]&&target>nums[j]) j=mid-1;
                if (nums[mid]<nums[i]&&target>nums[j]) j=mid-1;
                else i=mid+1;
            else
                //if (nums[j]<nums[i]&&nums[mid]>nums[j]&&target<nums[i]) i=mid+1;
                if (nums[mid]>nums[j]&&target<nums[i]) i=mid+1;
                else j=mid-1;
        }
        return target==nums[i]?i:-1;
    }
};

class Solution2 {
public://复杂度n还是4ms测试用例应该不大
    int search(vector<int>& nums, int target) {
        for (int i=0; i<nums.size(); i++)
            if (nums[i]==target) return i;
        return -1;
    }
};

class Solution1 {
public://我还以为是判断target是不是pivot，反而搞复杂了
    int search(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1;
        if (nums.size()==0) return -1;
        if (nums.size()==1) return target==nums[0]?0:-1;
        while (i<j) {
            int mid=(i+j)/2;
            if (mid==0) {nums[0]>nums[1]?i++:j--; break;}
            if (nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])
                i++;//6 7 0
            else if (nums[mid]>nums[mid-1]&&nums[mid]<nums[mid+1])
                if (nums[mid]>nums[0]) i++;//5 6 7
                else j--;//0 1 2
            else if (nums[mid]<nums[mid-1]&&nums[mid]<nums[mid+1])
                i=j=mid;//7 0 1
        }
        return target==nums[i]?i:-1;
    }
};