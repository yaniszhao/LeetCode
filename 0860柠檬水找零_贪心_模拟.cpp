class Solution {
public://贪心模拟，和下面一样的思路只是改短了下代码
    bool lemonadeChange(vector<int>& bills) {
        int five=0, ten=0;
        for (auto b : bills) {
            if (b==5) five++;
            else if (b==10) {ten++; five--;}
            else if (ten) { ten--; five--;}//进的20
            else five-=3;//进的20
            if (five<0) return false;
        }
        return true;
    }
};

class Solution1 {
public://贪心模拟，先找10元不够再找5元的，20的不用找
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int five=0, ten=0;
        for (int i=0; i<n; i++) {
            if (bills[i]==5) {
                five++;
                continue;
            }
            else if (bills[i]==10) {
                if (!five) return false;
                ten++;
                five--;
            }
            else if (bills[i]==20) {
                bills[i]-=5;//需要找零
                if (ten) {bills[i]-=10; ten--;}
                if (five*5<bills[i]) return false;
                else five-=bills[i]/5;//如果满足找零要处理这次少的零钱
            }
        }
        return true;
    }
};
