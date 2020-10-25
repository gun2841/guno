class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum=0, mul =1;
        while(n)
        {
            int t = n%10;
            sum +=t;
            mul*=t;
            n /=10;
        }
        return mul - sum;
    }
};