class Solution {
public:
    string defangIPaddr(string address) {
        string temp = "";
        int n = address.length();
        for (int i = 0; i < n; i++)
        {
            if (address[i] == '.') { temp += "[.]"; }
            else
            {
                temp += address[i];
            }
        }
        return temp;
    }
};