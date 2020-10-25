class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> vt(101,0);
        vector<int> dist(101,0);
        for(int i =0;i<n;i++)
        {
            vt[nums[i]]++;
        }
        for(int i = 1;i<101;i++)
        {
            dist[i] = dist[i-1]+vt[i-1];
        }
        for(int i =0;i<n;i++)
        {
            nums[i] = dist[nums[i]];
        }
        return nums;
    }
};