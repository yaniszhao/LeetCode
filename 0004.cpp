class Solution {
public:
    //用更多的空间换时间，代码简单，时间复杂度为O(n)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> mset;
        int len=nums1.size()+nums2.size();
        int mid=(len-1)/2;
        for (auto it : nums1) mset.insert(it);
        for (auto it : nums2) mset.insert(it);
        nums1.assign(mset.begin(), mset.end());
        if (len%2) return (double)nums1[mid];
        else return (double)(nums1[mid]+nums1[mid+1])/2;
    }
};

class Solution2 {
public:
    //用空间换时间，代码更简单，时间复杂度为排序复杂度O(nlogn)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len=nums1.size()+nums2.size();
        int mid=(len-1)/2;
        for (auto it : nums2) nums1.push_back(it);
        sort(nums1.begin(), nums1.end());
        if (len%2) return (double)nums1[mid];
        else return (double)(nums1[mid]+nums1[mid+1])/2;
    }
};

class Solution1 {
public:
    //代码简单，但是复杂度O(n)达不到要求
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size(), len2=nums2.size();
        int i=0, j=0, mid=(len1+len2-1)/2;
        for (int k=0; k<mid; k++)
            if (i<len1 && j<len2) {
                if (nums1[i]<nums2[j]) i++;
                else j++;
            }
            else {
                if (i<len1) i++;
                else j++;
            }
        if ((len1+len2)%2) {//奇数
            if (i<len1 && j<len2) return (double)min(nums1[i], nums2[j]);
            else if (i<len1) return (double)nums1[i];
            else return (double)nums2[j];
        }
        else {
            int sum=0;
            for (int k=0; k<2; k++)
                if (i==len1) sum+=nums2[j++];
                else if (j==len2) sum+=nums1[i++];
                else sum+=nums1[i]<nums2[j]?nums1[i++]:nums2[j++];
            return (double)sum/2;
        }
    }
};
