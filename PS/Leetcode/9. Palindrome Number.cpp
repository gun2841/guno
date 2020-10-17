class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        string temp = str;
        reverse(str.begin(), str.end());
        int n = str.size();
        for (int i = 0; i < n; i++)
        {
            if (str[i] != temp[i]) return false;
        }
        return true;
    }
};