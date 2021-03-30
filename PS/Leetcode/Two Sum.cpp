class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        int n = nums.size();
        map<int,int> mp;
        for(int i =0;i<n;i++)
        {
            int diff = target - nums[i];
            if(mp[diff] == 0)
            {
                mp[nums[i]]=i+1;
            }
            else
            {
                ans[1] = i; ans[0] = mp[diff]-1;
                return ans;
            }
        }
        return ans;
    }
};