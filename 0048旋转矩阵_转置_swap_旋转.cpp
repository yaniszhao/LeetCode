class Solution {
public://先转置再对换，满足时间和空间要求。还可以用多次旋转的方法。
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //沿主对角线转置
        for (int i=1; i<n; i++)
            for (int j=0; j<i; j++)
                swap(matrix[i][j], matrix[j][i]);
        //左右两边交换
        for (int i=0; i<n; i++)
            for (int j=0; j<n/2; j++)
                swap(matrix[i][j], matrix[i][n-1-j]);
    }
};

class Solution1 {
public://多开了一个矩阵，这种方法简单但是空间复杂度不满足要求
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> map(n, vector<int>(n));
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                map[j][n-1-i]=matrix[i][j];
        matrix=move(map);//用move开销好像小一点
    }
};
