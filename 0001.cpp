class Solution {
public:
    //1、用数据结构存，{val,index}，时间很快
    //2、直接两次循环，但是时间很大
    //3、一次循环放入map，然后遍历nums查询另外一个是否存在，要判断相同值
    //4、一次循环放入map且查询，不用判断相同值
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> map;
        vector<int> ans(2);
        
        for (int i=0; i<nums.size(); i++)
            if (map.find(target-nums[i])!=map.end()) {
                ans[0]=i;
                ans[1]=map[target-nums[i]];
                //这题顺序是没有关系的，不加下面行也能过
                if (ans[0]>ans[1]) swap(ans[0], ans[1]);
                return ans;
            }
            else map[nums[i]]=i;
    }
};

class Solution3 {
public:    
    //直接两次循环时间太大了，改hash存下标
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> map;
        vector<int> ans(2);
        
        for (int i=0; i<nums.size(); i++)
            map[nums[i]]=i;
        
        for (int i=0; i<nums.size()-1; i++)
            if (map.find(target-nums[i])!=map.end() && map[target-nums[i]]!=i) {
                ans[0]=i;
                ans[1]=map[target-nums[i]];
                return ans;
            }
    }
};

class Solution2 {
public:    
    //只有一对且有结果，要简单点, 我之前的答案是可以求多对的
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for (int i=0; i<nums.size()-1; i++)
            for (int j=i+1; j<nums.size(); j++) 
                if (nums[i]+nums[j]==target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
    }
};

typedef struct {
    int val;
    int index;
} Node;

bool cmp(Node a, Node b) {return a.val<b.val;}

class Solution1 {    
public:    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<Node> v;
        vector<int> ans;
        Node tmp;
        int i=0,j=nums.size()-1,sum;
        
        for (int k=0; k<nums.size(); k++) {
            tmp.val=nums[k];
            tmp.index=k;
            v.push_back(tmp);
        }
            
        sort(v.begin(), v.end(), cmp);
        
        while (i<j) {
            sum=v[i].val+v[j].val;
            if (sum<target) i++;
            else if (sum>target) j--; 
            else {
                ans.push_back(v[i].index);
                ans.push_back(v[j].index);
                i++;
                j--;
            }
        }
        return ans; 
    }
};
