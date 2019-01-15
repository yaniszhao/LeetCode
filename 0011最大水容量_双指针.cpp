class Solution {
public:
    //用双指针的方法，向中间靠拢，因为靠拢间隔减小，要使值变大，
    //必须使新的挡板比当前的最小的那块大，所以要变小的那边。
    //当两块相同的时候，在新的大块出来之前是没有最小块的。
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1;
        int maxval=0;
        while (i<j) {
            int val=(j-i)*min(height[i], height[j]);
            if (val>maxval) maxval=val;
            if (height[i]<height[j]) i++;
            else j--;
        }
        return maxval;
    }
};

class Solution1 {
public://BF大法，复杂度有点高
    int maxArea(vector<int>& height) {
        int maxval=0;
        for (int i=0; i<height.size()-1; i++) {
            for (int j=i+1; j<height.size(); j++) {
                int val=(j-i)*min(height[i], height[j]);
                if (val>maxval) maxval=val;
            }
        }
        return maxval;
    }
};
