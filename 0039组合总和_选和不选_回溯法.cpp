class Solution {
public://选和不选。没想到打败的人还挺多的。
    void fun(vector<vector<int>>& ans, vector<int>& nums, int target, int st)
    {
        int n=nums.size();
        if (target<nums[st]||st==n) return;
        //用于本函数处理数据
        if (nums[st]==target) {
            vector<int> v(1, target);
            ans.push_back(v);
            return;
        }
        vector<vector<int>> v1, v2;//用与接收下一层函数结过
        //选
        fun(v1, nums, target-nums[st], st);
        //要加引用，因为会改值
        for (auto &it:v1) it.insert(it.begin(), nums[st]);
        //不选
        fun(v2, nums, target, st+1);
        //连接结果
        ans.insert(ans.end(), v1.begin(), v1.end());
        ans.insert(ans.end(), v2.begin(), v2.end());
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());//有些用例是无序的
        fun(ans, candidates, target, 0);
        return ans;
    }
};
