class Solution {
public:
    //前两层循环是BF的循环，后两个数的计算是类似计算3个值的算法。
    //相比之前的题，做了一些剪枝的优化
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=nums.size();
        if (n<4) return ans;
        sort(nums.begin(), nums.end());
        for (int i=0; i<n-3; i++) {
            if (i>0&&nums[i]==nums[i-1]) continue;
            //前四个是最小的都比目标大，没必要继续了
            if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            //后面三个最大加当前值都还比目标小，当前值是不满足的，往后找大的
            if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            
            for(int j=i+1; j<n-2; j++) {
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                //类似i层的剪枝
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                int st=j+1, ed=n-1;
               
                while (st<ed) {
                    int val=nums[i]+nums[j]+nums[st]+nums[ed];
                    if (val==target) {
                        vector<int> v={nums[i], nums[j], nums[st], nums[ed]};
                        ans.push_back(v);
                        for (st++; st<ed && nums[st]==nums[st-1]; st++);
                        for (ed--; st<ed && nums[ed]==nums[ed+1]; ed--);
                    }
                    else if (val<target) {
                        for (st++; st<ed && nums[st]==nums[st-1]; st++);
                    }
                    else {
                        for (ed--; st<ed && nums[ed]==nums[ed+1]; ed--);
                    }
                }
            }
        }
        return ans;
    }
};

class Solution1 {
public://利用和简化计算3个数的函数，复杂度O(n3)
     void threeSum(vector<vector<int>>& ans, int target, \
                   vector<int>& nums, int begin, int end) {
        int mid;
        int i,st,ed; 
        
        for (i=begin; i<=end; i++) {
            if (i>begin && nums[i]==nums[i-1])
                continue;//避免相同数出现
            st=i+1;
            ed=end;
            while (st<ed) {
                int val=nums[i]+nums[st]+nums[ed];
                if (val==target) {
                    vector<int> v={nums[i], nums[st], nums[ed]};
                    ans.push_back(v);
                    for (st++; st<ed && nums[st]==nums[st-1]; st++);
                    for (ed--; st<ed && nums[ed]==nums[ed+1]; ed--);
                }
                else if (val<target) {
                    for (st++; st<ed && nums[st]==nums[st-1]; st++);
                }
                else {
                    for (ed--; st<ed && nums[ed]==nums[ed+1]; ed--);
                }
            }
        }
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> vthree, ans;
        if (nums.size()<4) return ans;
        sort(nums.begin(), nums.end());
        for (int i=0; i+3<nums.size(); i++) {
            if (i>0&&nums[i]==nums[i-1]) continue;
            vthree.clear();
            threeSum(vthree, target-nums[i], nums, i+1, nums.size()-1);
            if (!vthree.empty()) {
                for (auto it : vthree) {
                    vector<int> v={nums[i], it[0], it[1], it[2]};
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};
