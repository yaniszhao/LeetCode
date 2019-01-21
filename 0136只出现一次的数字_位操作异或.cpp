class Solution {
public:
    //看的知乎的一个回来过来做的，用异或真的吊
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for (auto n:nums) ans^=n;
        return ans;
    }
};

class Solution3 {
public:
    //用vetctor或set或map存值，存在则删去不存在则加入，最后剩的就是那个值
    //set版本
    int singleNumber(vector<int>& nums) {
        set<int> s;
        for (auto n:nums) {
            auto it=s.find(n);
            if (it==s.end()) s.insert(n);
            else s.erase(it);
        }
        return *s.begin();
    }
};

class Solution2 {
public:
    //用vetctor或set或map存值，存在则删去不存在则加入，最后剩的就是那个值
    //vector版本
    int singleNumber(vector<int>& nums) {
        vector<int> v;
        for (auto n:nums) {
            auto it=find(v.begin(), v.end(), n);
            if (it==v.end()) v.push_back(n);
            else v.erase(it);
        }
        return v[0];
    }
};

class Solution1 {
public:
    //数学分析c=2(a+b+c)-(a+b+c)，看的solution
    int singleNumber(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int sum1, sum2;
        sum1=2*accumulate(s.begin(), s.end(), 0);
        sum2=accumulate(nums.begin(), nums.end(), 0);
        return sum1-sum2;
    }
};



