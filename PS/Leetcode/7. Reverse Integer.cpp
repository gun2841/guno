class Solution {
public:
    int reverse(int x) {
        int sign = 0;
        long long max = 2147483647;
        long long tp=0;
        if (x < 0) sign = -1;
        else sign = 1;
        if (sign == 0) return 0;

        string str = to_string(x);
        string temp = "";
        long  n = str.size();
        for (int i = n - 1; i >= 0; i--)
            temp += str[i];
        tp = atoll(temp.c_str());
        x = tp;
        if (tp > max) return 0;
        return x * sign;
    }
};