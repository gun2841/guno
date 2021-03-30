class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return "";
        string ans = strs[0];
        for (int i = 1; i < n; i++) {
            string temp = "";
            int strN = strs[i].length();
            for (int j = 0; j < strN || j < ans.length(); j++)
            {
                if (ans[j] == strs[i][j]) temp += ans[j];
                else break;
            }
            ans = temp;
        }
        return ans;
    }
};
