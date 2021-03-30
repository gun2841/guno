class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> vt;
        map<int, int> mp;
        int n = nums.size();
        int m = 0,ans = 0;
        
        for(int i =0;i<n;i++)
        {
            if(mp[nums[i]] == 0) 
            {
                mp[nums[i]] = 1;
                vt.push_back(nums[i]);
                m++;
            }
            else
                mp[nums[i]]+=1;
        }
        for(int i =0 ;i<m;i++)
        {
            if(mp[vt[i]]>1)
            {
                int t = mp[vt[i]];
                ans+=(t*(t-1)/2);
            }
        }
        return ans;
    }
};