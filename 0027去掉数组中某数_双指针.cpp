class Solution {
public://这个是去重代码和unique的类似
    int removeElement(vector<int>& nums, int val) {
        int cnt=0;
        if (nums.empty()) return 0;
        for (int i=0; i<nums.size(); i++)
            if (nums[i]!=val) nums[cnt++]=nums[i];
        return cnt;
    }
};
