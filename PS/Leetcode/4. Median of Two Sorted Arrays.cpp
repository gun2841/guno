class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int len = n+m;
        vector<int> vt;
         vt.insert(vt.end(), nums1.begin(), nums1.end());
        vt.insert(vt.end(), nums2.begin(), nums2.end());
        sort(vt.begin(), vt.end());
        if ((len) % 2 == 1) { return double(vt[len/2] ); };
        double d = double(vt[len/2]);
        
        double f = double(vt[(len/2)-1]);
        return  (d/2+f/2);
    }
};