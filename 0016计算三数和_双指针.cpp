class Solution {
public://这题和15类似，BF的方法就不做了
    int threeSumClosest(vector<int>& nums, int target) {
        int st,ed;
        int ans, mindiff=0x7FFFFFFF;
        sort(nums.begin(), nums.end());
        for (int i=0; i+2<nums.size(); i++) {
            if (i>0&&nums[i]==nums[i-1]) continue;
            st=i+1;
            ed=nums.size()-1;
            while (st<ed) {
                int diff=nums[i]+nums[st]+nums[ed]-target;
                if (diff==0) return target;
                else {
                    if (abs(diff)<abs(mindiff)) {
                        ans=nums[i]+nums[st]+nums[ed];
                        mindiff=diff;
                    }
                    if (diff<0) for (st++; nums[st]==nums[st-1]; st++);
                    else for (ed--; nums[ed]==nums[ed+1]; ed--);
                }
            }
        }
        return ans;
    }
};
