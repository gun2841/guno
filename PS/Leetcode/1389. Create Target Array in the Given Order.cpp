class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> vt;
        vector<int>::iterator it;
        for(int i =0;i<n;i++)
        {
            it = vt.begin();
            it = vt.insert(it+index[i],  nums[i]);
        }
        return  vt;
    }
};