class Solution {
public:
    //上种方法的j和k还是n2的复杂度，但是可以用双指针优化成O(n)的复杂度
    //通过判断和与0的关系可以让指针朝一个方向缩减
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int mid;//第一个大于或等于0的位置
        int i,st,ed; 
        
        if (nums.size()<3) return ans;//不可能构成一组
        sort(nums.begin(), nums.end());
        //注意mid<nums.size()很重要，否则运行时出错
        for (mid=0; mid<nums.size()&&nums[mid]<0; mid++);
        if (mid==nums.size()) return ans;//全部小于0也不可能
        
        for (i=0; i<=mid; i++) {
            if (i>0 && nums[i]==nums[i-1])
                continue;//避免相同数出现
            
            st=i+1;
            ed=nums.size()-1;
            while (st<ed) {
                int val=nums[i]+nums[st]+nums[ed];
                if (val==0) {
                    //我的eclipse为什么不支持这种初始化
                    vector<int> v={nums[i], nums[st], nums[ed]};
                    ans.push_back(v);
                    for (st++; st<ed && nums[st]==nums[st-1]; st++);
                    for (ed--; st<ed && nums[ed]==nums[ed+1]; ed--);
                }
                else if (val<0) {
                    for (st++; st<ed && nums[st]==nums[st-1]; st++);
                }
                else {
                    for (ed--; st<ed && nums[ed]==nums[ed+1]; ed--);
                }
            }
        }
        return ans;
    }
};


class Solution2 {
public:
    //虽然勉强能过但是时间复杂还是很高
    //大概思路要为0一定要有一个为正的一个负的，或者3个都为0
    //i只遍历到第一个大于等于0的前面，j从最大的整数遍历过来，
    //然后能找到一个中间值k满足条件即可，再避免下可能出现的重复3元组
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        int mid;//第一个大于或等于0的位置
        int i,j,k; 
        
        if (nums.size()<3) return ans;//不可能构成一组
        sort(nums.begin(), nums.end());
        //注意mid<nums.size()很重要，否则运行时出错
        for (mid=0; mid<nums.size()&&nums[mid]<0; mid++);
        if (mid==nums.size()) return ans;//全部小于0也不可能
        
        for (i=0; i<=mid; i++) {
            if (i>0&&nums[i]==nums[i-1])
                continue;//避免相同数出现
            
            for (j=nums.size()-1; j>=mid; j--) {
                if (j<nums.size()-1 && nums[j]==nums[j+1])
                    continue;//避免相同数出现
                
                for (k=i+1; k<j; k++) {
                    if (nums[i]+nums[j]+nums[k]==0) {
                        v.clear();
                        v.push_back(nums[i]);
                        v.push_back(nums[k]);//k要在中间
                        v.push_back(nums[j]);
                        ans.push_back(v);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution1 {
public://时间复杂度太高，会超时
    bool isOk(vector<vector<int>> ans, vector<int>& v2) {
        if (ans.size()==0) return true;
        vector<int> &v1=ans[ans.size()-1];
        return !(v1[0]==v2[0]&&v1[1]==v2[1]&&v1[2]==v2[2]);
    }
    
    //不加static还不能用，还要注意判别的写法，并不能简单的成equal那样
    static bool cmp(vector<int>& v1, vector<int>& v2) {
        if (v1[0]!=v2[0]) return v1[0]<v2[0];
        else if (v1[1]!=v2[1]) return v1[1]<v2[1];
        else return v1[2]<v2[2];
    }
    
    //不加static还不能用
    static bool equal(vector<int>& v1, vector<int>& v2) {
       return (v1[0]==v2[0]&&v1[1]==v2[1]&&v1[2]==v2[2]);
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        int i,j,k;
        
        sort(nums.begin(), nums.end());//先排序比在循环里排序要好
        //不能去重，有些就是要重复出现的
        //vector<int>::iterator it;
        //it=unique(nums.begin(), nums.end());
        //nums.resize(distance(nums.begin(),it));
        
        //本来是i<nums.size()-2的，但是size()返回是无符号的，
        //如果是0减去了反而是一个很大的值。
        for (i=0; i+2<nums.size(); i++)
            for (j=i+1; j+1<nums.size(); j++)
                for (k=j+1; k<nums.size(); k++)
                    if (nums[i]+nums[j]+nums[k]==0) {
                        v.clear();
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        //sort(v.begin(), v.end());
                        //有了后面的排序和去重就不用判断if了
                        //if (isOk(ans, v))
                        ans.push_back(v);
                    }
        sort(ans.begin(), ans.end(), cmp);
        //注意去重的写法
        vector<vector<int>>::iterator it;
        it=unique(ans.begin(), ans.end(), equal);
        ans.resize(distance(ans.begin(),it));
        //
        return ans;                
    }
};
