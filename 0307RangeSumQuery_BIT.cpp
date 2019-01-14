class NumArray {
public:
    vector<int> v, vnum;
    NumArray(vector<int> nums) {
        v.resize(nums.size()+1, 0);
        vnum.resize(nums.size()+1, 0);
        for (int i=nums.size()-1; i>=0; i--)
            update(i, nums[i]);//反向更新很重要，不然有问题
    }
    
    void update(int i, int val) {
        myupdate(i+1, val);
        vnum[i+1] = val;
    }
    
    int sumRange(int i, int j) {
        return sum(j+1)-sum(i);
    }
    
    void myupdate(int i, int val) {
        int dif=val-vnum[i];
        for (; i<v.size(); i+=lowbit(i)) v[i]+=dif;
    }
    
    int lowbit(int x) {
        return x&-x;
    }
    
    int sum(int idx) {
        int ans=0;
        for (; idx>0; idx-=lowbit(idx)) ans+=v[idx];
        return ans;
    }
};


class NumArray1 {
public:
    vector<int> v;
    NumArray1(vector<int> nums) {
        v.resize(nums.size()+1, 0);
        //for (int i=0; i<v.size(); i++) v[i]=0;
        for (int i=nums.size()-1; i>=0; i--)
            update(i, nums[i]);//反向更新很重要，不然有问题
    }
    
    void update(int i, int val) {
        myupdate(i+1, val);
    }
    
    int sumRange(int i, int j) {
        return sum(j+1)-sum(i);
    }
    
    void myupdate(int i, int val) {
        int dif=val-(sum(i)-sum(i-1));//不是v[i]-v[i-1]
        for (; i<v.size(); i+=lowbit(i)) v[i]+=dif;
    }
    
    int lowbit(int x) {
        return x&-x;
    }
    
    int sum(int idx) {
        int ans=0;
        for (; idx>0; idx-=lowbit(idx)) ans+=v[idx];
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
