class Solution {
public:
    //假设最终体积z = m * x + n * y（m与n为整数，可以为0或者为负）
    //令x = p * gcd, y = q * gcd，可知p与q互质。
    //则z = (m * p + n * q) * gcd
    //可以证明一定存在m,n，使得m*p+n*q=1(p与q互质的性质，参见：裴蜀定理)
    //由此可知z一定是gcd的整数倍
    int gcd(int a, int b) {return b==0?a:gcd(b, a%b);}
    
    bool canMeasureWater(int x, int y, int z) {
        if (z==0) return true;
        else if (x==0&&y!=0) return z%y==0;
        else if (x!=0&&y==0) return z%x==0;
        else if (x==0&&y==0) return false;
        if (x+y<z) return false;
        return z%gcd(x, y)==0;
    }
};
