class Solution {
public://双指针复杂度时间只有O(n)
    int trap(vector<int>& height) {
        int n=height.size();
        if (n<3) return 0;
        int sum=0;
        int l=0, r=n-1, lmax=0, rmax=0;
        while (l<r) {//最后l==r的时候一定是最大值，一定无水
            if (height[l]<height[r]) {//处理左边
                if (height[l]>=lmax) lmax=height[l];
                else sum += lmax-height[l];
                l++;
            }
            else {//处理右边
                if (height[r]>=rmax) rmax=height[r];
                else sum += rmax-height[r];
                r--;
            }
        }
        return sum;
    }
};

class Solution2 {
public://dp复杂度时间只有O(n)但是空间复杂增加了
    int trap(vector<int>& height) {
        int n=height.size();
        if (n<3) return 0;
        vector<int> vl(n, 0), vr(n, 0);
        //从左往右依次每个位置的平行值
        vl[0]=height[0];        
        for (int i=1; i<n; i++)
            if (height[i]>vl[i-1]) vl[i]=height[i];
            else vl[i]=vl[i-1];
        //从右往左依次每个位置的平行值
        vr[n-1]=height[n-1];        
        for (int j=n-2; j>=0; j--)
            if (height[j]>vr[j+1]) vr[j]=height[j];
            else vr[j]=vr[j+1];
        //计算总和
        int sum=0;
        for (int i=0; i<n; i++)
            sum += min(vl[i], vr[i]) - height[i];
        return sum;
    }
};

class Solution1 {
public://最核心的思路就在里面，可认为是BF算法，但复杂度只有O(n)
    int trap(vector<int>& height) {
        int n=height.size();
        int lmax=0, rmax=n-1;
        if (n<3) return 0;
        //找到左边最小值
        for (int i=1; i<n; i++)
            if (height[i]>height[lmax]) lmax=i;
        //找到右边最小值j>=lmax比j>=0要好些
        for (int j=n-2; j>=lmax; j--)
            if (height[j]>height[rmax]) rmax=j;
        int sum=0, barsum=0, maxbar=0;
        //计算左边体积
        for (int i=0; i<=lmax; i++) {
            sum+=maxbar;//递加平行体积
            if (height[i]>maxbar) maxbar=height[i];
            barsum+=height[i];//递加柱子体积
        }
        sum+=maxbar; maxbar=0;
        //计算右边体积
        for (int j=n-1; j>=rmax; j--) {
            sum+=maxbar;
            if (height[j]>maxbar) maxbar=height[j];            
            barsum+=height[j];
        }
        sum+=maxbar;
        //计算中间体积
        for (int k=lmax+1; k<rmax; k++) {
            sum+=maxbar;
            barsum+=height[k];
        }
        //水的体积等于sum-柱子的体积
        return sum-barsum;
    }
};
