class Solution {
public:
    //找到比当前数字大的生成数中的最小值，如果已经是最大则变为最小值
    //走到i时i后面的一定是逆序的，当nums[i]>=nums[i+1]时直接再往前走，
    //nums[i]<nums[i+1]时找一个恰好比它大的一个数交换，再把后面的
    //顺序序就行了，因为后面一定是逆序的所以reverse的复杂度低一些
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(), i,j;
        for (i=n-2; i>=0; i--) {
            if (nums[i]<nums[i+1]) {
                for (j=i+1; j<n&&nums[j]>nums[i]; j++);
                swap(nums[i], nums[j-1]);
                reverse(nums.begin()+i+1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};

class Solution1 {
public:
    //找到比当前数字大的生成数中的最小值，如果已经是最大则变为最小值
    //STL有现成的函数
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};
