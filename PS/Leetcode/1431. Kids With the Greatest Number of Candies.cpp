class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> answer;
        int maxCandy = *max_element(candies.begin(), candies.end());
        int n = candies.size();
        for (int i = 0; i < n; i++)
        {
            if ((candies[i] + extraCandies) >= maxCandy) answer.push_back(true);
            else answer.push_back(false);
        }
        return answer;
    }
};