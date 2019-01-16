class Solution {
public://直接写也很简单
    int removeDuplicates(vector<int>& nums) {
        int cnt=1;
        if (nums.empty()) return 0;
        for (int i=1; i<nums.size(); i++)
            if (nums[i]!=nums[cnt-1]) nums[cnt++]=nums[i];
        return cnt;
    }
};

class Solution1 {
public://直接用STL了，注意使用unique前提是序列有序
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator it;
        it=unique(nums.begin(), nums.end());
        return it-nums.begin();
    }
};
