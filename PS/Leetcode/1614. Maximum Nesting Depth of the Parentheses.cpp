class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int p = 0;
        int ans = 0;
        for (int i =0;i<n;i++)
        {
            if(s[i] == '(') p++;
            else if (s[i] == ')') p--;
            ans = max(ans,p);
        }
        return ans;
    }
};