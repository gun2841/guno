class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = s.size();
        string str(n, 'a');
        for(int i =0;i<n;i++)
        {
            str[indices[i]] = s[i];
        }
        return str;
    }
};