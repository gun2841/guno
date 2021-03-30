class Solution {
public:
    int numberOfSteps (int num) {
        int cnt = 1;
        if (num ==0 ) return 0;
        while(1)
        {
            int t = num&1;
            if(num == 1) break;
            if(t == 1) {num-=1; cnt++;}
            else if ( t ==0 ) {num= num>>1; cnt++;}
        }
        return cnt;
    }
};