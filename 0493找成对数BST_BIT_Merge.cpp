class Solution {
public://division and conquer
    //考虑left: 4 6 8 right: 1 2 3
    //总共的对数为坐边的对数加右边的对数再加上左右各一个的对数
    //而且左右两边都有序，由这个规律就好求了
    void mergesort1(vector<int>& A, int start, int mid, int end)
    {//参考的别人的代码，和我的效率好像差不多
        int n1 = (mid - start + 1);
        int n2 = (end - mid);
        int L[n1], R[n2];
        for (int i = 0; i < n1; i++)
            L[i] = A[start + i];
        for (int j = 0; j < n2; j++)
            R[j] = A[mid + 1 + j];
        int i = 0, j = 0;
        for (int k = start; k <= end; k++) {
            if (j >= n2 || (i < n1 && L[i] <= R[j]))
                A[k] = L[i++];
            else
                A[k] = R[j++];
        }
    }
    
    void mergesort(vector<int>& v, int st, int mid, int ed)
    {//这个我写的，效率好像差不多
        vector<int> nums(v.begin()+st, v.begin()+ed+1);
        mid=mid-st;
        int idx=st, i=0, j=mid+1;
        
        while (i<=mid&&j<nums.size()) {
            if (nums[i]<nums[j]) v[idx++]=nums[i++];
            else v[idx++]=nums[j++];
        }
        while (i<=mid) v[idx++]=nums[i++];
        while (j<nums.size()) v[idx++]=nums[j++];
    }
    
    int mergecout(vector<int>& v, int st, int ed)
    {
        if (st>=ed) return 0;
        int mid=(st+ed)/2;
        int cnt=mergecout(v, st, mid)+mergecout(v, mid+1, ed);
        int i,j=mid+1;
        for (i=st; i<=mid; i++) {
            //for (j=mid+1; j<=ed && v[i]>v[j]*2LL; j++);
            //j不用回到mid+1因为之前满足的i更新之后还是满足
            //这个是最大优化点可以优化几千ms
            for (; j<=ed && v[i]>v[j]*2LL; j++);
            cnt += j-mid-1;
        }
        //sort(v.begin()+st, v.begin()+ed+1);
        //直接排序虽然简单，但是时间开销就大了，所以手动排序
        mergesort(v, st, mid, ed);
        return cnt;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergecout(nums, 0, nums.size()-1);
    }
};

class Solution4 {
public://用BIT终于有个能过的了，复杂度O(nlogn)
    void update(vector<int>& BIT, int pos, int val)
    {
        while (pos<BIT.size()) {
            BIT[pos]+=val;
            pos += pos&(-pos);
        }
    }
    
    int sum(vector<int>& BIT, int pos)
    {
        int sum=0;
        while (pos>0) {
            sum+=BIT[pos];
            pos -= pos&(-pos);
        }
        return sum;
    }
    
    int reversePairs(vector<int>& nums) {
        int n=nums.size(), cnt=0, tmp=0;
        vector<int> cpy(nums);
        sort(cpy.begin(), cpy.end());
        //unique(cpy.begin(), cpy.end());
        vector<int> BITS(n+1, 0);
        
        for (int i=0; i<n; i++) {
            tmp=sum(BITS, lower_bound(cpy.begin(), cpy.end(), nums[i]*2LL+1) - cpy.begin());
            cnt += i-tmp;//tmp得到的是小于的个数，要加的是大于的个数
            update(BITS, lower_bound(cpy.begin(), cpy.end(), nums[i]) - cpy.begin() + 1, 1);
        }
        return cnt;
    }
};

class Solution3 {
public:
    //总的复杂度O(nlogn)，但是针对单调的序列BST就退化成线性了
    class Node {
    public:
        Node *left, *right;
        int val, num;//num是为了让重复值不多浪费空间，还让右边的个数也加到这
        Node(int val) {
            this->left=this->right=NULL;
            this->num=1;
            this->val=val;
        }
    };
    
    void insert(Node *&head, int val)
    {
        if (head==NULL) {
            head=new Node(val);
            return;
        }
        //当值相同也可以重新分个结点，但是空间就会多浪费很多
        if (head->val==val) head->num++;//重复值时只加num不加新结点
        else if (head->val>val) insert(head->left, val);
        else {
            head->num++;//除了记录自己的个数，还记录右边比自己大的个数
            insert(head->right, val);
        }
    }
    
    int count(Node *head, long long val)
    {//注意val是2倍加1
        Node *p=head, *tmp;
        int cnt=0;
        if (!head) return 0;
        if (head->val==val)
            return head->num;
        else if (head->val>val)
            return head->num+count(head->left, val);
        else
            return count(head->right, val);
    }
    
    int reversePairs(vector<int>& nums) {
        Node *head=NULL;
        int cnt=0;
        for (auto it : nums) {//复杂度O(nlogn)
            //计算在it之前比it*2大的数据的个数,注意有个加1
            cnt += count(head, it*2LL+1);//复杂度O(logn)
            //把当前值插入BST中，方便后面的查找
            insert(head, it);//复杂度O(logn)
        }
        return cnt;
    }
};

class Solution2 {
public:
    //这个算法因为count是O(n)所以总的复杂度还是O(n2)
    //对于大的数据已经可以解决了，但是针对单调的序列BST就退化了
    //可以修改insert和count让count成O(logn)
    class Node {
    public:
        Node *left, *right;
        int val, num;//num是为了让重复值不多浪费空间
        Node(int val) {
            this->left=this->right=NULL;
            this->num=1;
            this->val=val;
        }
    };
    
    void insert(Node *&head, int val)
    {
        if (head==NULL) {
            head=new Node(val);
            return;
        }
        //当值相同也可以重新分个结点，但是空间就会多浪费很多
        if (head->val==val) head->num++;
        else if (head->val>val) insert(head->left, val);
        else insert(head->right, val);
    }
    
    int count(Node *head, int val)
    {//中序遍历比val*2大的数据的个数
        stack<Node*> stk;
        Node *p=head, *tmp;
        int cnt=0;
        if (!head) return 0;
        while (p || !stk.empty()) {
            if (p) {
                stk.push(p);
                p=p->left;
            }
            else {
                tmp=stk.top();
                stk.pop();
                if (tmp->val > val*2LL) cnt+=tmp->num;
                p=tmp->right;
            }
        }
        return cnt;
    }
    
    int reversePairs(vector<int>& nums) {
        Node *head=NULL;
        int cnt=0;
        for (auto it : nums) {//复杂度O(n2)
            //计算在it之前比it*2大的数据的个数
            cnt += count(head, it);//复杂度O(n)
            //把当前值插入BST中，方便后面的查找
            insert(head, it);//复杂度O(logn)
        }
        return cnt;
    }
};

class Solution1 {
public://数据太多会超时
    typedef long long LLONG;//不改成longlong大数过不了
    int reversePairs(vector<int>& nums) {
        int i, j, cnt=0;
        for (j=nums.size()-1; j>0; j--) 
            for (i=0; i<j; i++) 
                //if ((LLONG)nums[i] > 2*(LLONG)nums[j]) cnt++;
                if (nums[i] > nums[j]*2LL) cnt++;
        return cnt;
    }
};
